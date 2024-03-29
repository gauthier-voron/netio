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


#ifndef NETIO_RAW_H
#define NETIO_RAW_H


struct netio_raw;
typedef struct netio_raw netio_raw_t;


#include "netio/header.h"
#include "netio/protocol.h"


extern netio_protocol_t *NETIO_RAW_PROTOCOL;


struct netio_raw
{
	netio_header_t   nraw_header;
	const char      *nraw_data;
	size_t           nraw_size;
};


int netio_raw_init(netio_raw_t *this);


int netio_raw_setdata(netio_raw_t *this, const char *data, size_t size);


const char *netio_raw_getdata(const netio_raw_t *this);

size_t netio_raw_getsize(const netio_raw_t *this);


#endif
