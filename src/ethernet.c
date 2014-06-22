#include <arpa/inet.h>
#include <stdio.h>
#include <stdint.h>
#include "netio/arp.h"
#include "netio/ethernet.h"
#include "netio/ip.h"
#include "netio/raw.h"


struct __ethernet
{
	uint8_t  dest[6];
	uint8_t  src[6];
	uint16_t type;
} __attribute__((packed));

static int netio_ethernet_unpack(netio_context_t *ctx, netio_header_t *prev,
				 const char *data, size_t size)
{
	netio_ethernet_t eth;
	netio_macaddr_t dest, src;
	const struct __ethernet *__eth;

	if (size < sizeof(struct __ethernet))
		return -1;

	netio_ethernet_init(&eth);
	netio_header_link(&eth.neth_header, prev);

	__eth = (const struct __ethernet *) data;
	netio_macaddr_fromarr(&dest, (const char *) __eth->dest);
	netio_ethernet_setdest(&eth, &dest);
	netio_macaddr_fromarr(&src, (const char *) __eth->src);
	netio_ethernet_setsrc(&eth, &src);
	netio_ethernet_settype(&eth, ntohs(__eth->type));

	data += sizeof(struct __ethernet);
	size -= sizeof(struct __ethernet);

	return ctx->nc_at_unpack(ctx, &eth.neth_header, data, size);
}

static int netio_ethernet_chain(netio_context_t *ctx, netio_ethernet_t *cur,
				const char *data, size_t size)
{
	const netio_protocol_t *next = NULL;

	if (size == 0)
		goto ret;

	switch (cur->neth_type) {
	case NETIO_ETHERNET_TYPE_ARP:
		next = NETIO_ARP_PROTOCOL;
		break;
	case NETIO_ETHERNET_TYPE_IP:
		next = NETIO_IP_PROTOCOL;
		break;
	default:
		next = NETIO_RAW_PROTOCOL;
		break;
	}

 ret:
	return ctx->nc_at_chain(ctx, &cur->neth_header, data, size, next);
}

static int netio_ethernet_print(netio_context_t *ctx, FILE *f,
				const netio_ethernet_t *cur)
{
	int tmp;
	char buffer[32];

	fprintf(f, "ethernet\n");

	netio_macaddr_tostr(netio_ethernet_getdest(cur), buffer);
	fprintf(f, "%-30s %s\n", "  destination", buffer);

	netio_macaddr_tostr(netio_ethernet_getsrc(cur), buffer);
	fprintf(f, "%-30s %s\n", "  source", buffer);
	
	tmp = netio_ethernet_gettype(cur);
	fprintf(f, "%-30s %s (0x%04x)\n", "  type",
		netio_ethernet_typealias(tmp), tmp);

	return ctx->nc_at_print(ctx, f, &cur->neth_header,
				cur->neth_header.nh_next);
}

static int netio_ethernet_reply(netio_context_t *ctx, netio_header_t *next,
				const netio_ethernet_t *req)
{
	netio_ethernet_t rep;
	int type;

	netio_ethernet_init(&rep);
	netio_header_fill(&rep.neth_header, next);

	netio_ethernet_setsrc(&rep, netio_ethernet_getdest(req));
	netio_ethernet_setdest(&rep, netio_ethernet_getsrc(req));

	if (next->nh_protocol == NETIO_ARP_PROTOCOL)
		type = NETIO_ETHERNET_TYPE_ARP;
	else if (next->nh_protocol == NETIO_IP_PROTOCOL)
		type = NETIO_ETHERNET_TYPE_IP;
	else
		type = netio_ethernet_gettype(req);
	netio_ethernet_settype(&rep, type);

	return ctx->nc_at_reply(ctx, &rep.neth_header, &req->neth_header);
}

static int netio_ethernet_repack(netio_context_t *ctx,
				 const netio_ethernet_t *cur, char *data,
				 size_t *size)
{
	struct __ethernet *__eth;

	if (*size < sizeof(*__eth)) {
		*size = 0;
		return -1;
	}

	__eth = (struct __ethernet *) data;
	netio_macaddr_toarr(netio_ethernet_getdest(cur), (char *) __eth->dest);
	netio_macaddr_toarr(netio_ethernet_getsrc(cur), (char *) __eth->src);
	__eth->type = htons(netio_ethernet_gettype(cur));

	data += sizeof(*__eth);
	*size -= sizeof(*__eth);

	return ctx->nc_at_repack(ctx, cur->neth_header.nh_next, data, size);
}


netio_protocol_t __NETIO_ETHERNET_PROTOCOL = {
	(netio_unpack_t) netio_ethernet_unpack,
	(netio_chain_t)  netio_ethernet_chain,
	(netio_print_t)  netio_ethernet_print,
	(netio_reply_t)  netio_ethernet_reply,
	(netio_repack_t) netio_ethernet_repack
};

netio_protocol_t *NETIO_ETHERNET_PROTOCOL = &__NETIO_ETHERNET_PROTOCOL;


int netio_ethernet_init(netio_ethernet_t *this)
{
	netio_header_init(&this->neth_header, NETIO_ETHERNET_PROTOCOL);
	
	this->neth_dest = NULL;
	this->neth_src  = NULL;
	this->neth_type = 0;

	return 0;
}


const char *netio_ethernet_typealias(int type)
{
	switch (type) {
	case NETIO_ETHERNET_TYPE_IP:
		return "ip";
	case NETIO_ETHERNET_TYPE_ARP:
		return "arp";
	default:
		return "unknown";
	}
}


int netio_ethernet_setdest(netio_ethernet_t *this, netio_macaddr_t *dst)
{
	this->neth_dest = dst;
	return 0;
}

int netio_ethernet_setsrc(netio_ethernet_t *this, netio_macaddr_t *src)
{
	this->neth_src = src;
	return 0;

}

int netio_ethernet_settype(netio_ethernet_t *this, int type)
{
	this->neth_type = type;
	return 0;
}


netio_macaddr_t *netio_ethernet_getdest(const netio_ethernet_t *this)
{
	return this->neth_dest;
}

netio_macaddr_t *netio_ethernet_getsrc(const netio_ethernet_t *this)
{
	return this->neth_src;
}

int netio_ethernet_gettype(const netio_ethernet_t *this)
{
	return this->neth_type;
}
