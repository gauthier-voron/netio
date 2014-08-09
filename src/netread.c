#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <net/if.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
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


static int netio_packet_netread(netio_packet_t *dest)
{
	ssize_t ssize;
	struct ifreq ifreq;
	struct sockaddr_ll sll;
	socklen_t len = sizeof(sll);

	if ((ssize = recvfrom(sock, &dest->np_data, NETIO_PACKET_DATALEN, 0,
			      (struct sockaddr *) &sll, &len)) == -1)
		return -1;

	dest->np_size = (size_t) ssize;
	ifreq.ifr_ifindex = sll.sll_ifindex;
	if (ioctl(sock, SIOCGIFNAME, &ifreq) == -1)
		return -1;
	memcpy(dest->np_ifname, ifreq.ifr_name, sizeof(ifreq.ifr_name));

	return 0;
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
	printf("usage: netread [-v | --version]      print the version number "
	       "and exit\n"
	       "       netread [-h | -? | --help]    print this help message "
	       "and exit\n"
	       "       netread                       capture the network "
	       "packets\n\n");
	printf("The netread program is used to capture and dump on its "
	       "standard output, the\n"
	       "network packets at a low level. To work properly, this "
	       "program needs to be run\n"
	       "as root or with the cap_net_raw capability. The capture stops "
	       "when receiving an\n"
	       "INT, QUIT or TERM signal.\n");
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
		if (netio_packet_netread(&packet) == -1)
			continue;
		if (netio_packet_write(&packet, STDOUT_FILENO) == -1)
			continue;
	}

	close_sock();

	return EXIT_SUCCESS;
}
