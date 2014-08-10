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


#include "netio/header.h"


int netio_header_init(netio_header_t *this, const netio_protocol_t *protocol)
{
	this->nh_protocol = protocol;
	this->nh_next = NULL;
	this->nh_prev = NULL;
	this->nh_head = this;

	return 0;
}

int netio_header_link(netio_header_t *this, netio_header_t *prev)
{
	this->nh_prev = prev;
	
	if (prev) {
		prev->nh_next = this;
		this->nh_head = prev->nh_head;
	}

	return 0;
}

int netio_header_fill(netio_header_t *this, netio_header_t *next)
{
	this->nh_next = next;

	if (next)
		next->nh_prev = this;
	while (next) {
		next->nh_head = this->nh_head;
		next = next->nh_next;
	}

	return 0;
}
