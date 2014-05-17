#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "netio/context.h"
#include "netio/device.h"
#include "netio/netio.h"
#include "netio/packet.h"
#include "netio/protocol.h"


static int user_at_unpack(netio_context_t *ctx, netio_header_t *cur,
			  const char *data, size_t size)
{
	if (cur->nh_protocol == NETIO_DEVICE_PROTOCOL)
		printf("ifname = %s\n", ((netio_device_t *) cur)->ndev_ifname);
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
