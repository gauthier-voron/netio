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


#ifndef NETIO_MACADDR_H
#define NETIO_MACADDR_H


#include <stdlib.h>


typedef struct
{
	unsigned char  nmac_arr[6];
} netio_macaddr_t;


int netio_macaddr_init(netio_macaddr_t *this);


int netio_macaddr_fromstr(netio_macaddr_t *this, const char *str);

int netio_macaddr_fromarr(netio_macaddr_t *this, const char *arr);

int netio_macaddr_fromifn(netio_macaddr_t *this, const char *ifn);


int netio_macaddr_tostr(const netio_macaddr_t *this, char *buf);

int netio_macaddr_toarr(const netio_macaddr_t *this, char *arr);


int netio_macaddr_cmp(const netio_macaddr_t *a, const netio_macaddr_t *b);


#endif
