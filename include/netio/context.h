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


#ifndef NETIO_CONTEXT_H
#define NETIO_CONTEXT_H


struct netio_context;
typedef struct netio_context netio_context_t;


#include "netio/header.h"
#include "netio/packet.h"
#include "netio/protocol.h"


typedef int (*netio_at_unpack_t)(netio_context_t *ctx, netio_header_t *cur,
				 const char *payload, size_t size);

typedef int (*netio_at_chain_t)(netio_context_t *ctx, netio_header_t *prev,
				const char *payload, size_t size,
				const netio_protocol_t *next);

typedef int (*netio_at_print_t)(netio_context_t *ctx, FILE *f,
				const netio_header_t *prev,
				const netio_header_t *next);

typedef int (*netio_at_reply_t)(netio_context_t *ctx, netio_header_t *rep,
				const netio_header_t *req);

typedef int (*netio_at_repack_t)(netio_context_t *ctx,
				 const netio_header_t *next, char *data,
				 size_t *size);


struct netio_context
{
	netio_at_unpack_t  nc_at_unpack;
	netio_at_chain_t   nc_at_chain;
	netio_at_print_t   nc_at_print;
	netio_at_reply_t   nc_at_reply;
	netio_at_repack_t  nc_at_repack;
};


int netio_context_init(netio_context_t *this);

int netio_context_unpack(netio_context_t *this, const netio_packet_t *packet);

int netio_context_print(netio_context_t *this, FILE *f,
			const netio_header_t *header);

int netio_context_reply(netio_context_t *this, const netio_header_t *header);

int netio_context_repack(netio_context_t *this, netio_packet_t *packet,
			 const netio_header_t *header);


int netio_context_setatunpack(netio_context_t *this, netio_at_unpack_t handle);

int netio_context_setatchain(netio_context_t *this, netio_at_chain_t handle);

int netio_context_setatprint(netio_context_t *this, netio_at_print_t handle);

int netio_context_setatreply(netio_context_t *this, netio_at_reply_t handle);

int netio_context_setatrepack(netio_context_t *this, netio_at_repack_t handle);


netio_at_unpack_t netio_context_getatunpack(const netio_context_t *this);

netio_at_chain_t netio_context_getatchain(const netio_context_t *this);

netio_at_print_t netio_context_getatprint(const netio_context_t *this);

netio_at_reply_t netio_context_getatreply(const netio_context_t *this);

netio_at_repack_t netio_context_getatrepack(const netio_context_t *this);


int netio_context_atunpack(netio_context_t *ctx, netio_header_t *cur,
			   const char *payload, size_t size);

int netio_context_atchain(netio_context_t *ctx, netio_header_t *prev,
			  const char *payload, size_t size,
			  const netio_protocol_t *next);

int netio_context_atprint(netio_context_t *ctx, FILE *f,
			  const netio_header_t *prev,
			  const netio_header_t *next);

int netio_context_atreply(netio_context_t *ctx, netio_header_t *rep,
			  const netio_header_t *req);

int netio_context_atrepack(netio_context_t *ctx, const netio_header_t *next,
			   char *data, size_t *size);


#endif
