#include <stdio.h>
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

static char saferepr(char c)
{
	if (c < 33 || c > 126)
		return '.';
	return c;
}

static int netio_raw_print(netio_context_t *ctx, const netio_raw_t *cur)
{
	int i;
	unsigned int line = 0;

	printf("raw\n");

	while (cur->nraw_size - line * 16 > 16) {
		printf("  %06x   ", line);
		for (i=0; i<8; i++)
			printf("%02x ", cur->nraw_data[line*16 + i] & 0xff);
		printf(" ");
		for (i=8; i<16; i++)
			printf("%02x ", cur->nraw_data[line*16 + i] & 0xff);
		printf("  ");
		
		for (i=0; i<8; i++)
			printf("%c", saferepr(cur->nraw_data[line*16 + i]));
		printf(" ");
		for (i=8; i<16; i++)
			printf("%c", saferepr(cur->nraw_data[line*16 + i]));
		printf("\n");

		line++;
	}


	if (cur->nraw_size == line * 16)
		goto ret;


	printf("  %06x   ", line);

	for (i=0; i<8; i++)
		if (line*16 + i < cur->nraw_size)
			printf("%02x ", cur->nraw_data[line*16 + i] & 0xff);
		else
			printf("   ");
	printf(" ");
	for (i=8; i<16; i++)
		if (line*16 + i < cur->nraw_size)
			printf("%02x ", cur->nraw_data[line*16 + i] & 0xff);
		else
			printf("   ");
	printf("  ");

	for (i=0; i<8; i++)
		if (line*16 + i < cur->nraw_size)
			printf("%c", saferepr(cur->nraw_data[line*16 + i]));
		else
			printf(" ");
	printf(" ");
	for (i=8; i<16; i++)
		if (line*16 + i < cur->nraw_size)
			printf("%c", saferepr(cur->nraw_data[line*16 + i]));
		else
			printf(" ");
	printf("\n");

 ret:
	return ctx->nc_at_print(ctx, &cur->nraw_header,
				cur->nraw_header.nh_next);
}


netio_protocol_t __NETIO_RAW_PROTOCOL = {
	(netio_unpack_t) netio_raw_unpack,
	(netio_chain_t)  netio_raw_chain,
	(netio_print_t)  netio_raw_print
};

netio_protocol_t *NETIO_RAW_PROTOCOL = &__NETIO_RAW_PROTOCOL;


int netio_raw_init(netio_raw_t *this)
{
	netio_header_init(&this->nraw_header, NETIO_RAW_PROTOCOL);
	
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
