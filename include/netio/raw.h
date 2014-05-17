#ifndef NETIO_RAW_H
#define NETIO_RAW_H


struct netio_raw;
typedef struct netio_raw netio_raw_t;


#include "netio/header.h"
#include "netio/protocol.h"


extern netio_protocol_t *NETIO_RAW_PROTOCOL;


struct netio_raw
{
	netio_header_t   nraw_header;
	const char      *nraw_data;
	size_t           nraw_size;
};


int netio_raw_init(netio_raw_t *this);


int netio_raw_setdata(netio_raw_t *this, const char *data, size_t size);


const char *netio_raw_getdata(const netio_raw_t *this);

size_t netio_raw_getsize(const netio_raw_t *this);


#endif
