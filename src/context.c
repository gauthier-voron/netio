#include "netio/context.h"
#include "netio/raw.h"


static int netio_context_at_unpack(netio_context_t *ctx, netio_header_t *cur,
				   const char *payload, size_t size)
{
	return cur->nh_protocol->np_chain(ctx, cur, payload, size);
}

static int netio_context_at_chain(netio_context_t *ctx, netio_header_t *prev,
				  const char *payload, size_t size,
				  const netio_protocol_t *next)
{
	if (!next)
		return 0;
	return next->np_unpack(ctx, prev, payload, size);
}


int netio_context_init(netio_context_t *ctx)
{
	ctx->nc_at_unpack = netio_context_at_unpack;
	ctx->nc_at_chain = netio_context_at_chain;

	return 0;
}

int netio_context_unpack(netio_context_t *this, const netio_packet_t *packet)
{
	const netio_protocol_t *next = NETIO_RAW_PROTOCOL;
	return this->nc_at_chain(this, NULL, packet->np_data, packet->np_size,
				 next);
}


int netio_context_setatunpack(netio_context_t *this, netio_at_unpack_t handle)
{
	if (!handle)
		handle = netio_context_at_unpack;
	this->nc_at_unpack = handle;

	return 0;
}

int netio_context_setatchain(netio_context_t *this, netio_at_chain_t handle)
{
	if (!handle)
		handle = netio_context_at_chain;
	this->nc_at_chain = handle;

	return 0;
}


netio_at_unpack_t netio_context_getatunpack(const netio_context_t *this)
{
	return this->nc_at_unpack;
}

netio_at_chain_t netio_context_getatchain(const netio_context_t *this)
{
	return this->nc_at_chain;
}
