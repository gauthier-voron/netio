#ifndef NETIO_DEVICE_H
#define NETIO_DEVICE_H


struct netio_device;
typedef struct netio_device netio_device_t;


#include <net/if.h>
#include <stdlib.h>
#include "netio/header.h"
#include "netio/protocol.h"


extern netio_protocol_t *NETIO_DEVICE_PROTOCOL;


#define NETIO_DEVICE_FLAG_UP             IFF_UP
#define NETIO_DEVICE_FLAG_BROADCAST      IFF_BROADCAST
#define NETIO_DEVICE_FLAG_DEBUG          IFF_DEBUG
#define NETIO_DEVICE_FLAG_LOOPBACK       IFF_LOOPBACK
#define NETIO_DEVICE_FLAG_POINTOPOINT    IFF_POINTOPOINT
#define NETIO_DEVICE_FLAG_RUNNING        IFF_RUNNING
#define NETIO_DEVICE_FLAG_NOARP          IFF_NOARP
#define NETIO_DEVICE_FLAG_PROMISC        IFF_PROMISC
#define NETIO_DEVICE_FLAG_NOTRAILERS     IFF_NOTRAILERS
#define NETIO_DEVICE_FLAG_ALLMULTI       IFF_ALLMULTI
#define NETIO_DEVICE_FLAG_MASTER         IFF_MASTER
#define NETIO_DEVICE_FLAG_SLAVE          IFF_SLAVE
#define NETIO_DEVICE_FLAG_MULTICAST      IFF_MULTICAST
#define NETIO_DEVICE_FLAG_PORTSEL        IFF_PORTSEL
#define NETIO_DEVICE_FLAG_AUTOMEDIA      IFF_AUTOMEDIA
#define NETIO_DEVICE_FLAG_DYNAMIC        IFF_DYNAMIC


struct netio_device
{
	netio_header_t   ndev_header;
	const char      *ndev_ifname;
};


int netio_device_init(netio_device_t *this);


int netio_device_listifnames(char *buffer, size_t size);

int netio_device_getifflags(const char *ifname);

int netio_device_getifmtu(const char *ifname);


int netio_device_setifname(netio_device_t *this, const char *ifname);


const char *netio_device_getifname(const netio_device_t *this);


#endif
