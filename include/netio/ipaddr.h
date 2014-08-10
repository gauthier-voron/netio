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


#ifndef NETIO_IPADDR_H
#define NETIO_IPADDR_H


#include <stdlib.h>


typedef struct
{
	unsigned char  nip_arr[4];
} netio_ipaddr_t;


int netio_ipaddr_init(netio_ipaddr_t *this);


int netio_ipaddr_fromstr(netio_ipaddr_t *this, const char *str);

int netio_ipaddr_fromarr(netio_ipaddr_t *this, const char *arr);

int netio_ipaddr_fromifn(netio_ipaddr_t *this, const char *ifn);


int netio_ipaddr_tostr(const netio_ipaddr_t *this, char *buf);

int netio_ipaddr_toarr(const netio_ipaddr_t *this, char *arr);


int netio_ipaddr_cmp(const netio_ipaddr_t *a, const netio_ipaddr_t *b);


#endif
