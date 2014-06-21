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
	int ret;

	if (data == NULL) {
		printf("=== request ===\n");
		ret = netio_context_print(ctx, stdout, cur->nh_head);
		if (ret != 0)
			return ret;
		return netio_context_reply(ctx, cur);
	}
	return cur->nh_protocol->np_chain(ctx, cur, data, size);
}

static int user_at_reply(netio_context_t *ctx, netio_header_t *rep,
			 const netio_header_t *req)
{
	if (!req->nh_prev) {
		printf("=== reply ===\n");
		return netio_context_print(ctx, stdout, rep);
	}
	return req->nh_prev->nh_protocol->np_reply(ctx, rep, req->nh_prev);
}


int main(void)
{
	netio_context_t context;
	netio_packet_t packet;

	netio_context_init(&context);
	netio_context_setatunpack(&context, user_at_unpack);
	netio_context_setatreply(&context, user_at_reply);

	while (netio_packet_read(&packet, STDIN_FILENO) != -1)
		netio_context_unpack(&context, &packet);

	return EXIT_SUCCESS;
}
