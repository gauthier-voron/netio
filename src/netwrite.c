/*
 * Copyright (c) 20014 Gauthier Voron.
 *
 * This file is part of Netio.
 *
 * Netio is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * Netio is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Netio. If not, see <http://www.gnu.org/licenses/>.
 */


#include <arpa/inet.h>
#include <errno.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>
#include "netio/packet.h"


static int sock = -1;
static volatile int killed = 0;


static void close_sock(void)
{
	if (sock != -1)
		close(sock);
}

static int open_sock(void)
{
	sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if (sock == -1)
		return -1;
	atexit(close_sock);
	return 0;
}


static int netio_packet_netwrite(const netio_packet_t *src)
{
	struct ifreq ifreq;
	struct sockaddr_ll sll;
	ssize_t ssize;
	size_t size;

	size = strnlen(src->np_ifname, sizeof(ifreq.ifr_name));
	if (size == sizeof(ifreq.ifr_name))
		return -1;
	strcpy(ifreq.ifr_name, src->np_ifname);

	if (ioctl(sock, SIOCGIFINDEX, &ifreq) != 0)
		return -1;

	sll.sll_family = AF_PACKET;
	sll.sll_protocol = 0;
	sll.sll_ifindex = ifreq.ifr_ifindex;
	sll.sll_hatype = 0;
	sll.sll_pkttype = 0;
	sll.sll_halen = 0;
	memset(sll.sll_addr, 0, sizeof(sll.sll_addr));

	ssize = sendto(sock, src->np_data, src->np_size, 0,
		       (const struct sockaddr *) &sll, sizeof(sll));

	if (ssize < 0)
		return -1;

	size = (signed) ssize;
	return (size == src->np_size) ? 0 : -1;
}


static void signal_handler(int signum __attribute__((unused)))
{
	killed = 1;
}

static int setup_signal_handler(int signum)
{
	struct sigaction sigact;

	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigact.sa_handler = signal_handler;

	return sigaction(signum, &sigact, NULL);
}


static void invocation_error(const char *program)
{
	fprintf(stderr, "%s: invocation error\n", program);
	fprintf(stderr, "pease run '%s --help' for more informations\n",
		program);
}

static void version(void)
{
	printf("%s\n", VERSION);
}

static void usage(void)
{
	printf("usage: netwrite [-v | --version]     print the version number "
	       "and exit\n"
	       "       netwrite [-h | -? | --help]   print this help message "
	       "and exit\n"
	       "       netwrite                      inject the network "
	       "packets\n\n");
	printf("The netwrite program is used to inject packets it receive on "
	       "its standard input\n"
	       "into the network at a low level. To work properly, this "
	       "program needs to be run\n"
	       "as root or with the cap_net_raw capability. The injection "
	       "stops when receiving\n"
	       "an INT, QUIT or TERM signal or stdin closes.\n");
}


int main(int argc, const char **argv)
{
	netio_packet_t packet;

	if (argc >= 2) {
		if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")) {
			version();
			return EXIT_SUCCESS;
		} else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "-?")
			   || !strcmp(argv[1], "--help")) {
			usage();
			return EXIT_SUCCESS;
		} else {
			invocation_error(argv[0]);
			return EXIT_FAILURE;
		}
	}

	if (setup_signal_handler(SIGINT) != 0
	    || setup_signal_handler(SIGQUIT) != 0
	    || setup_signal_handler(SIGTERM) != 0)
		return EXIT_FAILURE;

	if (open_sock() == -1)
		return EXIT_FAILURE;

	while (!killed) {
		if (netio_packet_read(&packet, STDIN_FILENO) == -1) {
			if (errno == EAGAIN || errno == EINTR)
				continue;
			break;
		}
		if (netio_packet_netwrite(&packet) == -1)
			break;
	}

	close_sock();

	return EXIT_SUCCESS;
}
