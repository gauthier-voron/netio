#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <net/if.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "netio/packet.h"


static int sock = -1;


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


int main(void)
{
	netio_packet_t packet;

	if (open_sock() == -1)
		return EXIT_FAILURE;

	while (1) {
		if (netio_packet_netread(&packet) == -1)
			return EXIT_FAILURE;
		if (netio_packet_write(&packet, STDOUT_FILENO) == -1)
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
