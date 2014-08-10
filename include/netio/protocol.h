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


#ifndef NETIO_PROTOCOL_H
#define NETIO_PROTOCOL_H


struct netio_protocol;
typedef struct netio_protocol netio_protocol_t;


#include <stdio.h>
#include <stdlib.h>
#include "netio/context.h"
#include "netio/protocol.h"


typedef int (*netio_unpack_t)(netio_context_t *ctx, netio_header_t *prev,
			      const char *data, size_t size);

typedef int (*netio_chain_t)(netio_context_t *ctx, netio_header_t *cur,
			     const char *data, size_t size);

typedef int (*netio_print_t)(netio_context_t *ctx, FILE *f,
			     const netio_header_t *cur);

typedef int (*netio_reply_t)(netio_context_t *ctx, netio_header_t *next,
			     const netio_header_t *req);

typedef int (*netio_repack_t)(netio_context_t *ctx, const netio_header_t *cur,
			      char *data, size_t *size);


struct netio_protocol
{
	netio_unpack_t  np_unpack;
	netio_chain_t   np_chain;
	netio_print_t   np_print;
	netio_reply_t   np_reply;
	netio_repack_t  np_repack;
};


#endif
