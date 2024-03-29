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


#ifndef NETIO_ARP_H
#define NETIO_ARP_H


struct netio_arp;
typedef struct netio_arp netio_arp_t;


#include "netio/header.h"
#include "netio/protocol.h"


extern netio_protocol_t *NETIO_ARP_PROTOCOL;


#define NETIO_ARP_HRD_ETHERNET     0x0001

#define NETIO_ARP_PRO_IP           0x0800

#define NETIO_ARP_OP_REQUEST       1
#define NETIO_ARP_OP_REPLY         2


struct netio_arp
{
	netio_header_t   narp_header;
	int              narp_hrd;
	int              narp_pro;
	int              narp_hln;
	int              narp_pln;
	int              narp_op;
	void            *narp_sha;
	void            *narp_spa;
	void            *narp_tha;
	void            *narp_tpa;
};


int netio_arp_init(netio_arp_t *this);


const char *netio_arp_hrdalias(int hrd);

const char *netio_arp_proalias(int pro);

const char *netio_arp_opalias(int op);


int netio_arp_sethrd(netio_arp_t *this, int hrd);

int netio_arp_setpro(netio_arp_t *this, int pro);

int netio_arp_sethln(netio_arp_t *this, int hln);

int netio_arp_setpln(netio_arp_t *this, int pln);

int netio_arp_setop(netio_arp_t *this, int op);

int netio_arp_setsha(netio_arp_t *this, void *sha);

int netio_arp_setspa(netio_arp_t *this, void *spa);

int netio_arp_settha(netio_arp_t *this, void *tha);

int netio_arp_settpa(netio_arp_t *this, void *tpa);


int netio_arp_gethrd(const netio_arp_t *this);

int netio_arp_getpro(const netio_arp_t *this);

int netio_arp_gethln(const netio_arp_t *this);

int netio_arp_getpln(const netio_arp_t *this);

int netio_arp_getop(const netio_arp_t *this);

void *netio_arp_getsha(const netio_arp_t *this);

void *netio_arp_getspa(const netio_arp_t *this);

void *netio_arp_gettha(const netio_arp_t *this);

void *netio_arp_gettpa(const netio_arp_t *this);


#endif
