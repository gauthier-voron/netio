#include "netio/context.h"
#include "netio/device.h"
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

static int netio_context_at_print(netio_context_t *ctx, FILE *f,
				  const netio_header_t *prev
				  __attribute__((unused)),
				  const netio_header_t *next)
{
	if (!next)
		return 0;
	return next->nh_protocol->np_print(ctx, f, next);
}


int netio_context_init(netio_context_t *ctx)
{
	ctx->nc_at_unpack = netio_context_at_unpack;
	ctx->nc_at_chain = netio_context_at_chain;
	ctx->nc_at_print = netio_context_at_print;

	return 0;
}

int netio_context_unpack(netio_context_t *this, const netio_packet_t *packet)
{
	netio_device_t dev;

	netio_device_init(&dev);
	netio_device_setifname(&dev, packet->np_ifname);

	return this->nc_at_unpack(this, &dev.ndev_header, packet->np_data,
				  packet->np_size);
}

int netio_context_print(netio_context_t *this, FILE *f,
			const netio_header_t *header)
{
	return netio_context_at_print(this, f, header->nh_prev, header);
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

int netio_context_setatprint(netio_context_t *this, netio_at_print_t handle)
{
	if (!handle)
		handle = netio_context_at_print;
	this->nc_at_print = handle;
	
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

netio_at_print_t netio_context_getatprint(const netio_context_t *this)
{
	return this->nc_at_print;
}
