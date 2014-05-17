#include "netio/raw.h"


static int netio_raw_unpack(netio_context_t *ctx, netio_header_t *prev,
			    const char *data, size_t size)
{
	netio_raw_t raw;

	netio_raw_init(&raw);
	netio_header_link(&raw.nraw_header, prev);

	netio_raw_setdata(&raw, data, size);

	return ctx->nc_at_unpack(ctx, &raw.nraw_header, NULL, 0);
}

static int netio_raw_chain(netio_context_t *ctx, netio_raw_t *cur,
			   const char *data, size_t size)
{
	const netio_protocol_t *next = NULL;

	if (size > 0)
		next = NETIO_RAW_PROTOCOL;

	return ctx->nc_at_chain(ctx, &cur->nraw_header, data, size, next);
}


netio_protocol_t __NETIO_RAW_PROTOCOL = {
	(netio_unpack_t) netio_raw_unpack,
	(netio_chain_t)  netio_raw_chain
};

netio_protocol_t *NETIO_RAW_PROTOCOL = &__NETIO_RAW_PROTOCOL;


int netio_raw_init(netio_raw_t *this)
{
	this->nraw_header.nh_protocol = NETIO_RAW_PROTOCOL;
	this->nraw_header.nh_next = NULL;
	this->nraw_header.nh_prev = NULL;
	this->nraw_header.nh_head = &this->nraw_header;
	
	this->nraw_data = NULL;
	this->nraw_size = 0;

	return 0;
}


int netio_raw_setdata(netio_raw_t *this, const char *data, size_t size)
{
	this->nraw_data = data;
	this->nraw_size = size;

	return 0;
}


const char *netio_raw_getdata(const netio_raw_t *this)
{
	return this->nraw_data;
}

size_t netio_raw_getsize(const netio_raw_t *this)
{
	return this->nraw_size;
}
