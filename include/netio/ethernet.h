#ifndef NETIO_ETHERNET_H
#define NETIO_ETHERNET_H


struct netio_ethernet;
typedef struct netio_ethernet netio_ethernet_t;


#include "netio/header.h"
#include "netio/protocol.h"


extern netio_protocol_t *NETIO_ETHERNET_PROTOCOL;


struct netio_ethernet
{
	netio_header_t   neth_header;
	const char      *neth_dest;
	const char      *neth_src;
	int              neth_type;
};


int netio_ethernet_init(netio_ethernet_t *this);


int netio_ethernet_setdest(netio_ethernet_t *this, const char *dest);

int netio_ethernet_setsrc(netio_ethernet_t *this, const char *src);

int netio_ethernet_settype(netio_ethernet_t *this, int type);


const char *netio_ethernet_getdest(const netio_ethernet_t *this);

const char *netio_ethernet_getsrc(const netio_ethernet_t *this);

int netio_ethernet_gettype(const netio_ethernet_t *this);


#endif
