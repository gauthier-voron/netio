#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "netio/arp.h"
#include "netio/context.h"
#include "netio/device.h"
#include "netio/ethernet.h"
#include "netio/ipaddr.h"
#include "netio/macaddr.h"
#include "netio/netio.h"
#include "netio/packet.h"
#include "netio/protocol.h"


static int user_at_unpack(netio_context_t *ctx, netio_header_t *cur,
			  const char *data, size_t size)
{
	if (data == NULL)
		return netio_context_print(ctx, stdout, cur->nh_head);
	return cur->nh_protocol->np_chain(ctx, cur, data, size);
}

static int user_at_unpack(netio_context_t *ctx, netio_header_t *cur,
			  const char *data, size_t size)
{
	netio_context_t context;
	netio_packet_t packet;
	int ret;

	if (data == NULL) {
		printf("===== original =====\n");
		ret = netio_context_print(ctx, stdout, cur->nh_head);
		if (ret)
			return ret;

		netio_context_repack(ctx, &packet, cur->nh_head);

		netio_context_init(&context);
		netio_context_setatunpack(&context, user_at_unpack);
		printf("=====   copy   =====\n");
		netio_context_unpack(&context, &packet);
		printf("size = %lu\n", packet.np_size);
	}

	return cur->nh_protocol->np_chain(ctx, cur, data, size);
}


int main(void)
{
	netio_context_t context;
	netio_packet_t packet;

	netio_context_init(&context);
	netio_context_setatunpack(&context, user_at_unpack2);

	while (netio_packet_read(&packet, STDIN_FILENO) != -1)
		netio_context_unpack(&context, &packet);

	return EXIT_SUCCESS;
}
