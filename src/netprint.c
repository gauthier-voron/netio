#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "netio/netio.h"
#include "netio/packet.h"


int main(void)
{
	netio_packet_t packet;

	if (netio_packet_read(&packet, STDIN_FILENO) == -1)
		return EXIT_FAILURE;
	printf("size = %lu / ifname = %s\n", packet.np_size, packet.np_ifname);

	return EXIT_SUCCESS;
}
