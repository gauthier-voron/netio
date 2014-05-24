#ifndef NETIO_ETHERNET_H
#define NETIO_ETHERNET_H


struct netio_ethernet;
typedef struct netio_ethernet netio_ethernet_t;


#include "netio/header.h"
#include "netio/macaddr.h"
#include "netio/protocol.h"


extern netio_protocol_t *NETIO_ETHERNET_PROTOCOL;


#define NETIO_ETHERNET_TYPE_IP   0x0800
#define NETIO_ETHERNET_TYPE_ARP  0x0806


struct netio_ethernet
{
	netio_header_t    neth_header;
	netio_macaddr_t  *neth_dest;
	netio_macaddr_t  *neth_src;
	int               neth_type;
};


int netio_ethernet_init(netio_ethernet_t *this);


const char *netio_ethernet_typealias(int type);


int netio_ethernet_setdest(netio_ethernet_t *this, netio_macaddr_t *dst);

int netio_ethernet_setsrc(netio_ethernet_t *this, netio_macaddr_t *src);

int netio_ethernet_settype(netio_ethernet_t *this, int type);


netio_macaddr_t *netio_ethernet_getdest(const netio_ethernet_t *this);

netio_macaddr_t *netio_ethernet_getsrc(const netio_ethernet_t *this);

int netio_ethernet_gettype(const netio_ethernet_t *this);


#endif
