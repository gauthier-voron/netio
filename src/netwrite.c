#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
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


int main(void)
{
	netio_packet_t packet;

	if (open_sock() == -1)
		return EXIT_FAILURE;

	while (1) {
		if (netio_packet_read(&packet, STDIN_FILENO) == -1)
			return EXIT_FAILURE;
		if (netio_packet_netwrite(&packet) == -1)
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
