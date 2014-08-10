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


#ifndef PACKET_H
#define PACKET_H

#include <net/if.h>
#include <stdlib.h>


#define NETIO_PACKET_IFLEN     IFNAMSIZ
#define NETIO_PACKET_DATALEN   1500


struct netio_packet
{
	char      np_ifname[NETIO_PACKET_IFLEN];
	size_t    np_size;
	char      np_data[NETIO_PACKET_DATALEN];
} __attribute__((packed));
typedef struct netio_packet netio_packet_t;


int netio_packet_read(netio_packet_t *dest, int fd);

int netio_packet_write(const netio_packet_t *src, int fd);

#endif
