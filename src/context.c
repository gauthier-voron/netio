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


#include <string.h>
#include "netio/context.h"
#include "netio/device.h"
#include "netio/raw.h"


int netio_context_atunpack(netio_context_t *ctx, netio_header_t *cur,
			   const char *payload, size_t size)
{
	return cur->nh_protocol->np_chain(ctx, cur, payload, size);
}

int netio_context_atchain(netio_context_t *ctx, netio_header_t *prev,
			  const char *payload, size_t size,
			  const netio_protocol_t *next)
{
	if (!next)
		return 0;
	return next->np_unpack(ctx, prev, payload, size);
}

int netio_context_atprint(netio_context_t *ctx, FILE *f,
			  const netio_header_t *prev __attribute__((unused)),
			  const netio_header_t *next)
{
	if (!next)
		return 0;
	return next->nh_protocol->np_print(ctx, f, next);
}

int netio_context_atreply(netio_context_t *ctx, netio_header_t *rep,
			  const netio_header_t *req)
{
	if (!req->nh_prev)
		return 0;
	return req->nh_prev->nh_protocol->np_reply(ctx, rep, req->nh_prev);
}

int netio_context_atrepack(netio_context_t *ctx, const netio_header_t *next,
			   char *data, size_t *size)
{
	if (!next)
		return 0;
	return next->nh_protocol->np_repack(ctx, next, data, size);
}


int netio_context_init(netio_context_t *ctx)
{
	ctx->nc_at_unpack = netio_context_atunpack;
	ctx->nc_at_chain = netio_context_atchain;
	ctx->nc_at_print = netio_context_atprint;
	ctx->nc_at_reply = netio_context_atreply;
	ctx->nc_at_repack = netio_context_atrepack;

	return 0;
}

int netio_context_unpack(netio_context_t *this, const netio_packet_t *packet)
{
	netio_device_t dev;

	netio_device_init(&dev);
	netio_device_setifname(&dev, packet->np_ifname);

	return this->nc_at_unpack(this, &dev.ndev_header, packet->np_data,
				  packet->np_size);
}

int netio_context_print(netio_context_t *this, FILE *f,
			const netio_header_t *header)
{
	return netio_context_atprint(this, f, header->nh_prev, header);
}

int netio_context_reply(netio_context_t *this, const netio_header_t *header)
{
	return header->nh_protocol->np_reply(this, NULL, header);
}

int netio_context_repack(netio_context_t *this, netio_packet_t *packet,
			 const netio_header_t *header)
{
	const netio_device_t *dev;
	int ret;

	if (header->nh_protocol == NETIO_DEVICE_PROTOCOL) {
		dev = (const netio_device_t *) header;
		strncpy(packet->np_ifname, netio_device_getifname(dev),
			sizeof(packet->np_ifname));

		if (packet->np_ifname[sizeof(packet->np_ifname) - 1])
			return -1;

		header = header->nh_next;
		if (!header)
			return 0;
	}

	packet->np_size = sizeof(packet->np_data);
	ret = this->nc_at_repack(this,header,packet->np_data,&packet->np_size);
	packet->np_size = sizeof(packet->np_data) - packet->np_size;
	return ret;
}


int netio_context_setatunpack(netio_context_t *this, netio_at_unpack_t handle)
{
	if (!handle)
		handle = netio_context_atunpack;
	this->nc_at_unpack = handle;

	return 0;
}

int netio_context_setatchain(netio_context_t *this, netio_at_chain_t handle)
{
	if (!handle)
		handle = netio_context_atchain;
	this->nc_at_chain = handle;

	return 0;
}

int netio_context_setatprint(netio_context_t *this, netio_at_print_t handle)
{
	if (!handle)
		handle = netio_context_atprint;
	this->nc_at_print = handle;
	
	return 0;
}

int netio_context_setatreply(netio_context_t *this, netio_at_reply_t handle)
{
	if (!handle)
		handle = netio_context_atreply;
	this->nc_at_reply = handle;

	return 0;
}

int netio_context_setatrepack(netio_context_t *this, netio_at_repack_t handle)
{
	if (!handle)
		handle = netio_context_atrepack;
	this->nc_at_repack = handle;

	return 0;
}


netio_at_unpack_t netio_context_getatunpack(const netio_context_t *this)
{
	return this->nc_at_unpack;
}

netio_at_chain_t netio_context_getatchain(const netio_context_t *this)
{
	return this->nc_at_chain;
}

netio_at_print_t netio_context_getatprint(const netio_context_t *this)
{
	return this->nc_at_print;
}

netio_at_reply_t netio_context_getatreply(const netio_context_t *this)
{
	return this->nc_at_reply;
}

netio_at_repack_t netio_context_getatrepack(const netio_context_t *this)
{
	return this->nc_at_repack;
}
