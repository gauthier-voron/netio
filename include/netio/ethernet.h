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
