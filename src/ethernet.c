#include <arpa/inet.h>
#include <stdint.h>
#include "netio/ethernet.h"
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
	netio_macaddr_t mac;
	const struct __ethernet *__eth;

	if (size < sizeof(struct __ethernet))
		return -1;

	netio_ethernet_init(&eth);
	netio_header_link(&eth.neth_header, prev);

	__eth = (const struct __ethernet *) data;
	netio_macaddr_fromarr(&mac, (const char *) __eth->dest);
	netio_ethernet_setdest(&eth, &mac);
	netio_macaddr_fromarr(&mac, (const char *) __eth->src);
	netio_ethernet_setsrc(&eth, &mac);
	netio_ethernet_settype(&eth, ntohs(__eth->type));

	data += sizeof(struct __ethernet);
	size -= sizeof(struct __ethernet);

	return ctx->nc_at_unpack(ctx, &eth.neth_header, data, size);
}

static int netio_ethernet_chain(netio_context_t *ctx, netio_ethernet_t *cur,
				const char *data, size_t size)
{
	const netio_protocol_t *next = NULL;

	if (size > 0)
		next = NETIO_RAW_PROTOCOL;

	return ctx->nc_at_chain(ctx, &cur->neth_header, data, size, next);
}


netio_protocol_t __NETIO_ETHERNET_PROTOCOL = {
	(netio_unpack_t) netio_ethernet_unpack,
	(netio_chain_t)  netio_ethernet_chain
};

netio_protocol_t *NETIO_ETHERNET_PROTOCOL = &__NETIO_ETHERNET_PROTOCOL;


int netio_ethernet_init(netio_ethernet_t *this)
{
	netio_header_init(&this->neth_header, NETIO_ETHERNET_PROTOCOL);
	
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


int netio_ethernet_setdest(netio_ethernet_t *this, const netio_macaddr_t *dst)
{
	this->neth_dest = *dst;
	return 0;
}

int netio_ethernet_setsrc(netio_ethernet_t *this, const netio_macaddr_t *src)
{
	this->neth_src = *src;
	return 0;

}

int netio_ethernet_settype(netio_ethernet_t *this, int type)
{
	this->neth_type = type;
	return 0;
}


int netio_ethernet_getdest(const netio_ethernet_t *this, netio_macaddr_t *dst)
{
	*dst = this->neth_dest;
	return 0;
}

int netio_ethernet_getsrc(const netio_ethernet_t *this, netio_macaddr_t *src)
{
	*src = this->neth_src;
	return 0;
}

int netio_ethernet_gettype(const netio_ethernet_t *this)
{
	return this->neth_type;
}
