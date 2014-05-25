#include <stdio.h>
#include <string.h>
#include "netio/device.h"
#include "netio/ethernet.h"
#include "netio/raw.h"


static int netio_dev_chain(netio_context_t *ctx, netio_device_t *cur,
			   const char *data, size_t size)
{
	const netio_protocol_t *next = NULL;

	if (size == 0)
		goto ret;

	switch (cur->ndev_ifname[0]) {
	case 'e':
		next = NETIO_ETHERNET_PROTOCOL;
		break;
	default:
		next = NETIO_RAW_PROTOCOL;
		break;
	}

 ret:
	return ctx->nc_at_chain(ctx, &cur->ndev_header, data, size, next);
}

static int netio_dev_print(netio_context_t *ctx, FILE *f,
			   const netio_device_t *cur)
{
	fprintf(f, "device\n");
	fprintf(f, "%-30s %s\n", "  interface name", cur->ndev_ifname);
	return ctx->nc_at_print(ctx, f, &cur->ndev_header,
				cur->ndev_header.nh_next);
}


netio_protocol_t __NETIO_DEVICE_PROTOCOL = {
	(netio_unpack_t) NULL,
	(netio_chain_t)  netio_dev_chain,
	(netio_print_t)  netio_dev_print
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
