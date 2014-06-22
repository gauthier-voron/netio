#include <stdio.h>
#include <string.h>
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

static int netio_raw_print(netio_context_t *ctx, FILE *f,
			   const netio_raw_t *cur)
{
	int i;
	unsigned int line = 0;

	fprintf(f, "raw\n");

	while (cur->nraw_size - line * 16 > 16) {
		fprintf(f, "  %06x   ", line);
		for (i=0; i<8; i++)
			fprintf(f, "%02x ",
				cur->nraw_data[line*16 + i] & 0xff);
		fprintf(f, " ");
		for (i=8; i<16; i++)
			fprintf(f, "%02x ",
				cur->nraw_data[line*16 + i] & 0xff);
		fprintf(f, "  ");
		
		for (i=0; i<8; i++)
			fprintf(f, "%c",
				saferepr(cur->nraw_data[line*16 + i]));
		fprintf(f, " ");
		for (i=8; i<16; i++)
			fprintf(f, "%c",
				saferepr(cur->nraw_data[line*16 + i]));
		fprintf(f, "\n");

		line++;
	}


	if (cur->nraw_size == line * 16)
		goto ret;


	fprintf(f, "  %06x   ", line);

	for (i=0; i<8; i++)
		if (line*16 + i < cur->nraw_size)
			fprintf(f, "%02x ",
				cur->nraw_data[line*16 + i] & 0xff);
		else
			fprintf(f, "   ");
	fprintf(f, " ");
	for (i=8; i<16; i++)
		if (line*16 + i < cur->nraw_size)
			fprintf(f, "%02x ",
				cur->nraw_data[line*16 + i] & 0xff);
		else
			fprintf(f, "   ");
	fprintf(f, "  ");

	for (i=0; i<8; i++)
		if (line*16 + i < cur->nraw_size)
			fprintf(f, "%c",
				saferepr(cur->nraw_data[line*16 + i]));
		else
			fprintf(f, " ");
	fprintf(f, " ");
	for (i=8; i<16; i++)
		if (line*16 + i < cur->nraw_size)
			fprintf(f, "%c",
				saferepr(cur->nraw_data[line*16 + i]));
		else
			fprintf(f, " ");
	fprintf(f, "\n");

 ret:
	return ctx->nc_at_print(ctx, f, &cur->nraw_header,
				cur->nraw_header.nh_next);
}

static int netio_raw_reply(netio_context_t *ctx, netio_header_t *next,
			   const netio_raw_t *req)
{
	netio_raw_t rep;

	netio_raw_init(&rep);
	netio_header_fill(&rep.nraw_header, next);

	netio_raw_setdata(&rep, netio_raw_getdata(req), netio_raw_getsize(req));

	return ctx->nc_at_reply(ctx, &rep.nraw_header, &req->nraw_header);
}

static int netio_raw_repack(netio_context_t *ctx, const netio_raw_t *cur,
			    char *data, size_t *size)
{
	size_t rsize = netio_raw_getsize(cur);

	if (*size < rsize) {
		*size = 0;
		return -1;
	}
	*size -= rsize;

	if (data) {
		memcpy(data, netio_raw_getdata(cur), rsize);
		data += rsize;
	}

	return ctx->nc_at_repack(ctx, cur->nraw_header.nh_next, data, size);
}


netio_protocol_t __NETIO_RAW_PROTOCOL = {
	(netio_unpack_t) netio_raw_unpack,
	(netio_chain_t)  netio_raw_chain,
	(netio_print_t)  netio_raw_print,
	(netio_reply_t)  netio_raw_reply,
	(netio_repack_t) netio_raw_repack
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
