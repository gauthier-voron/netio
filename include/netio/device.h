/*
 * Copyright (c) 20014 Gauthier Voron.
 *
 * This file is part of Netio.
 *
 * Netio is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * Netio is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Netio. If not, see <http://www.gnu.org/licenses/>.
 */


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
