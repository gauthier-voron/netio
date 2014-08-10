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
