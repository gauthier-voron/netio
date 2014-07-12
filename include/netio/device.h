#ifndef NETIO_DEVICE_H
#define NETIO_DEVICE_H


struct netio_device;
typedef struct netio_device netio_device_t;


#include <stdlib.h>
#include "netio/header.h"
#include "netio/protocol.h"


extern netio_protocol_t *NETIO_DEVICE_PROTOCOL;


struct netio_device
{
	netio_header_t   ndev_header;
	const char      *ndev_ifname;
};


int netio_device_init(netio_device_t *this);


int netio_device_listifnames(char *buffer, size_t size);


int netio_device_setifname(netio_device_t *this, const char *ifname);


const char *netio_device_getifname(const netio_device_t *this);


#endif
