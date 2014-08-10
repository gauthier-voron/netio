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


#include <unistd.h>
#include "netio/packet.h"


int netio_packet_read(netio_packet_t *dest, int fd)
{
	ssize_t ssize;
	size_t size = sizeof(*dest) - NETIO_PACKET_DATALEN;

	ssize = read(fd, dest, size);
	if (ssize < 0 || (size_t) ssize != size)
		return -1;
	
	size = dest->np_size;
	ssize = read(fd, &dest->np_data, size);
	if (ssize < 0 || (size_t) ssize != size)
		return -1;

	return 0;
}

int netio_packet_write(const netio_packet_t *src, int fd)
{
	size_t size = sizeof(*src);
	ssize_t ssize;
	
	if (src->np_size > NETIO_PACKET_DATALEN)
		return -1;
	size -= NETIO_PACKET_DATALEN;
	size += src->np_size;

	ssize = write(fd, src, size);
	if (ssize < 0 || (size_t) ssize != size)
		return -1;
	return 0;
}
