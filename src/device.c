#include "netio/device.h"
#include "netio/raw.h"


static int netio_dev_chain(netio_context_t *ctx, netio_raw_t *cur,
			   const char *data, size_t size)
{
	const netio_protocol_t *next = NULL;

	if (size > 0)
		next = NETIO_RAW_PROTOCOL;

	return ctx->nc_at_chain(ctx, &cur->nraw_header, data, size, next);
}


netio_protocol_t __NETIO_DEVICE_PROTOCOL = {
	(netio_unpack_t) NULL,
	(netio_chain_t)  netio_dev_chain
};

netio_protocol_t *NETIO_DEVICE_PROTOCOL = &__NETIO_DEVICE_PROTOCOL;


int netio_device_init(netio_device_t *this)
{
	netio_header_init(&this->ndev_header, NETIO_DEVICE_PROTOCOL);

	this->ndev_ifname = NULL;

	return 0;
}


int netio_device_setifname(netio_device_t *this, const char *ifname)
{
	this->ndev_ifname = ifname;
	return 0;
}


const char *netio_device_getifname(const netio_device_t *this)
{
	return this->ndev_ifname;
}
