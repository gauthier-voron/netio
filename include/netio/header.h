#ifndef NETIO_HEADER_H
#define NETIO_HEADER_H


struct netio_header;
typedef struct netio_header netio_header_t;


#include "netio/protocol.h"


struct netio_header
{
	const netio_protocol_t  *nh_protocol;
	struct netio_header     *nh_next;
	struct netio_header     *nh_prev;
	struct netio_header     *nh_head;
};


int netio_header_init(netio_header_t *this, const netio_protocol_t *protocol);

int netio_header_link(netio_header_t *this, netio_header_t *prev);

int netio_header_fill(netio_header_t *this, netio_header_t *next);


#endif
