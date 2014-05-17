#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "netio/context.h"
#include "netio/device.h"
#include "netio/ethernet.h"
#include "netio/netio.h"
#include "netio/packet.h"
#include "netio/protocol.h"


static int user_at_unpack(netio_context_t *ctx, netio_header_t *cur,
			  const char *data, size_t size)
{
	int i;
	const char *str;

	if (cur->nh_protocol == NETIO_DEVICE_PROTOCOL) {
		printf("device:\n");

		str = netio_device_getifname((netio_device_t *) cur);
		printf("  ifname = %s\n", str);

	} else if (cur->nh_protocol == NETIO_ETHERNET_PROTOCOL) {
		printf("ethernet:\n");

		str = netio_ethernet_getdest((netio_ethernet_t *) cur);
		printf("  dest = %02x:%02x:%02x:%02x:%02x:%02x\n",
		       str[0] & 0xff, str[1] & 0xff, str[2] & 0xff, 
		       str[3] & 0xff, str[4] & 0xff, str[5] & 0xff);

		str = netio_ethernet_getsrc((netio_ethernet_t *) cur);
		printf("  src  = %02x:%02x:%02x:%02x:%02x:%02x\n",
		       str[0] & 0xff, str[1] & 0xff, str[2] & 0xff, 
		       str[3] & 0xff, str[4] & 0xff, str[5] & 0xff);

		i = netio_ethernet_gettype((netio_ethernet_t *) cur);
		printf("  type = %04x\n", i);
	}

	return cur->nh_protocol->np_chain(ctx, cur, data, size);
}

static int user_at_chain(netio_context_t *ctx, netio_header_t *prev,
			 const char *data, size_t size,
			 const netio_protocol_t *next)
{
	printf("size = %lu\n", size);
	if (size == 0) {
		printf("end of parsing\n");
		return 0;
	}
	return next->np_unpack(ctx, prev, data, size);
}


int main(void)
{
	netio_context_t context;
	netio_packet_t packet;

	netio_context_init(&context);
	netio_context_setatunpack(&context, user_at_unpack);
	netio_context_setatchain(&context, user_at_chain);

	if (netio_packet_read(&packet, STDIN_FILENO) == -1)
		return EXIT_FAILURE;

	netio_context_unpack(&context, &packet);

	return EXIT_SUCCESS;
}
