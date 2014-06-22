#include <arpa/inet.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "netio/ip.h"
#include "netio/ipaddr.h"
#include "netio/raw.h"


struct __ip
{
	uint8_t   version_ihl;
	uint8_t   tos;
	uint16_t  len;
	uint16_t  id;
	uint16_t  flags_off;
	uint8_t   ttl;
	uint8_t   proto;
	uint16_t  sum;
	uint8_t   src[4];
	uint8_t   dest[4];
} __attribute__((packed));

static int netio_ip_unpack(netio_context_t *ctx, netio_header_t *prev,
			   const char *data, size_t size)
{
	netio_ip_t ip;
	const struct __ip *__ip;

	if (size < sizeof(struct __ip))
		return -1;

	netio_ip_init(&ip);
	netio_header_link(&ip.nip_header, prev);

	__ip = (const struct __ip *) data;

	netio_ip_setversion(&ip, __ip->version_ihl >> 4);
	netio_ip_setihl(&ip, __ip->version_ihl & 0xf);

	if (size < (unsigned) (netio_ip_getihl(&ip) * sizeof(uint32_t)))
		return -1;

	netio_ip_settos(&ip, __ip->tos);
	netio_ip_setlen(&ip, ntohs(__ip->len));
	netio_ip_setid(&ip, ntohs(__ip->id));
	netio_ip_setflags(&ip, ntohs(__ip->flags_off) >> 13);
	netio_ip_setoff(&ip, ntohs(__ip->flags_off) & 0x1fff);
	netio_ip_setttl(&ip, __ip->ttl);
	netio_ip_setproto(&ip, __ip->proto);
	netio_ip_setsum(&ip, ntohs(__ip->sum));

	netio_ip_setsrc(&ip, alloca(sizeof(netio_ipaddr_t)));
	netio_ipaddr_fromarr(netio_ip_getsrc(&ip), (char *) __ip->src);

	netio_ip_setdest(&ip, alloca(sizeof(netio_ipaddr_t)));
	netio_ipaddr_fromarr(netio_ip_getdest(&ip), (char *) __ip->dest);

	data += (netio_ip_getihl(&ip) << 2);
	size -= (netio_ip_getihl(&ip) << 2);

	return ctx->nc_at_unpack(ctx, &ip.nip_header, data, size);
}

static int netio_ip_chain(netio_context_t *ctx, netio_ip_t *cur,
			  const char *data, size_t size)
{
	const netio_protocol_t *next = NULL;

	if (size > 0)
		next = NETIO_RAW_PROTOCOL;

	return ctx->nc_at_chain(ctx, &cur->nip_header, data, size, next);
}

static int netio_ip_print(netio_context_t *ctx, FILE *f,
			  const netio_ip_t *cur)
{
	int tmp;
	char buffer[16];

	fprintf(f, "ip\n");
	
	fprintf(f, "%-30s %d\n", "  version", netio_ip_getversion(cur));
	fprintf(f, "%-30s %d\n", "  internet header length",
		netio_ip_getihl(cur));

	tmp = netio_ip_gettos(cur);
	fprintf(f, "%-30s %d%d%d%d%d%d%d%d\n", "  type of service",
		(tmp >> 0) & 0x1, (tmp >> 1) & 0x1, (tmp >> 2) & 0x1,
		(tmp >> 3) & 0x1, (tmp >> 4) & 0x1, (tmp >> 5) & 0x1,
		(tmp >> 6) & 0x1, (tmp >> 7) & 0x1);
	fprintf(f, "    %-26s %d%d%d.....\n", netio_ip_precealias(tmp),
		(tmp >> 7) & 0x1, (tmp >> 6) & 0x1, (tmp >> 5) & 0x1);
	fprintf(f, "    %-26s ...%d....\n",
		netio_ip_delayalias(tmp), (tmp >> 4) & 0x1);
	fprintf(f, "    %-26s ....%d...\n",
		netio_ip_throualias(tmp), (tmp >> 3) & 0x1);
	fprintf(f, "    %-26s .....%d..\n",
		netio_ip_relibalias(tmp), (tmp >> 2) & 0x1);

	fprintf(f, "%-30s %d\n", "  total length", netio_ip_getlen(cur));
	fprintf(f, "%-30s %d\n", "  identification", netio_ip_getid(cur));

	tmp = netio_ip_getflags(cur);
	fprintf(f, "%-30s %d%d%d\n", "  flags",
		(tmp >> 0) & 0x1, (tmp >> 1) & 0x1, (tmp >> 2) & 0x1);
	fprintf(f, "    %-26s .%d.\n",
		netio_ip_nfrgalias(tmp), (tmp >> 1) & 0x1);
	fprintf(f, "    %-26s ..%d\n",
		netio_ip_mfrgalias(tmp), (tmp >> 2) & 0x1);

	fprintf(f, "%-30s %d\n", "  fragment offset", netio_ip_getoff(cur));
	fprintf(f, "%-30s %d\n", "  time to live", netio_ip_getttl(cur));

	tmp = netio_ip_getproto(cur);
	fprintf(f, "%-30s %s (0x%02x)\n", "  protocol",
		netio_ip_protoalias(tmp), tmp);

	fprintf(f, "%-30s 0x%04x\n", "  header checksum",
		netio_ip_getsum(cur));

	netio_ipaddr_tostr(netio_ip_getsrc(cur), buffer);
	fprintf(f, "%-30s %s\n", "  source", buffer);
	
	netio_ipaddr_tostr(netio_ip_getdest(cur), buffer);
	fprintf(f, "%-30s %s\n", "  destination", buffer);

	return ctx->nc_at_print(ctx, f, &cur->nip_header,
				cur->nip_header.nh_next);
}

static int netio_ip_reply(netio_context_t *ctx, netio_header_t *next,
			  const netio_ip_t *req)
{
	netio_ip_t rep;
	size_t len = (uint16_t) -1;
	int ret;

	netio_ip_init(&rep);
	netio_header_fill(&rep.nip_header, next);

	ret = ctx->nc_at_repack(ctx, next, NULL, &len);
	if (ret)
		return ret;
	len = ((uint16_t) -1) - len;

	netio_ip_setversion(&rep, NETIO_IP_VERSION_IPV4);
	netio_ip_setihl(&rep, sizeof(struct __ip) / sizeof(uint32_t));
	netio_ip_setlen(&rep, len + netio_ip_getihl(&rep) * sizeof(uint32_t));
	netio_ip_setttl(&rep, NETIO_IP_TTL_DEFAULT);
	netio_ip_setsrc(&rep, netio_ip_getdest(req));
	netio_ip_setdest(&rep, netio_ip_getsrc(req));

	netio_ip_settos(&rep, netio_ip_gettos(req));
	netio_ip_setid(&rep, netio_ip_getid(req));
	netio_ip_setflags(&rep, netio_ip_getflags(req));
	netio_ip_setoff(&rep, netio_ip_getoff(req));
	netio_ip_setproto(&rep, netio_ip_getproto(req));

	netio_ip_setsum(&rep, netio_ip_checksum(&rep));

	return ctx->nc_at_reply(ctx, &rep.nip_header, &req->nip_header);
}

static int netio_ip_repack(netio_context_t *ctx, const netio_ip_t *cur,
			   char *data, size_t *size)
{
	struct __ip *__ip;

	if (*size < (netio_ip_getihl(cur) * sizeof(uint32_t))) {
		*size = 0;
		return -1;
	}
	*size -= (netio_ip_getihl(cur) * sizeof(uint32_t));

	if (data) {
		__ip = (struct __ip *) data;
		__ip->version_ihl = ((netio_ip_getversion(cur) & 0xf) << 4)
			| (netio_ip_getihl(cur) & 0xf);
		__ip->tos = netio_ip_gettos(cur);
		__ip->len = htons(netio_ip_getlen(cur));
		__ip->id = htons(netio_ip_getid(cur));
		__ip->flags_off = htons(((netio_ip_getflags(cur) & 0x7) << 13)
					| (netio_ip_getoff(cur) & 0x1fff));
		__ip->ttl = netio_ip_getttl(cur);
		__ip->proto = netio_ip_getproto(cur);
		__ip->sum = htons(netio_ip_getsum(cur));

		netio_ipaddr_toarr(netio_ip_getsrc(cur), (char *) __ip->src);
		netio_ipaddr_toarr(netio_ip_getdest(cur), (char *) __ip->dest);

		data += (netio_ip_getihl(cur) * sizeof(uint32_t));
	}

	return ctx->nc_at_repack(ctx, cur->nip_header.nh_next, data, size);
}


netio_protocol_t __NETIO_IP_PROTOCOL = {
	(netio_unpack_t) netio_ip_unpack,
	(netio_chain_t)  netio_ip_chain,
	(netio_print_t)  netio_ip_print,
	(netio_reply_t)  netio_ip_reply,
	(netio_repack_t) netio_ip_repack
};

netio_protocol_t *NETIO_IP_PROTOCOL = &__NETIO_IP_PROTOCOL;


int netio_ip_init(netio_ip_t *this)
{
	netio_header_init(&this->nip_header, NETIO_IP_PROTOCOL);
	
	this->nip_version = 0;
	this->nip_ihl     = 0;
	this->nip_len     = 0;
	this->nip_id      = 0;
	this->nip_flags   = 0;
	this->nip_off     = 0;
	this->nip_ttl     = 0;
	this->nip_proto   = 0;
	this->nip_sum     = 0;
	this->nip_src     = NULL;
	this->nip_dest    = NULL;

	return 0;
}


int netio_ip_checksum(const netio_ip_t *this)
{
	struct __ip __ip;
	uint16_t *arr = (uint16_t *) &__ip;
	uint32_t sum = 0;
	size_t i;

	__ip.version_ihl = ((netio_ip_getversion(this) & 0xf) << 4)
		| (netio_ip_getihl(this) & 0xf);
	__ip.tos = netio_ip_gettos(this);
	__ip.len = htons(netio_ip_getlen(this));
	__ip.id = htons(netio_ip_getid(this));
	__ip.flags_off = htons(((netio_ip_getflags(this) & 0x7) << 13)
			       | (netio_ip_getoff(this) & 0x1fff));
	__ip.ttl = netio_ip_getttl(this);
	__ip.proto = netio_ip_getproto(this);
	__ip.sum = 0;
	netio_ipaddr_toarr(netio_ip_getsrc(this), (char *) __ip.src);
	netio_ipaddr_toarr(netio_ip_getdest(this), (char *) __ip.dest);

	for (i=0; i<(sizeof(__ip) / sizeof(uint16_t)); i++) {
		sum += ntohs(arr[i]);
		sum = (sum & 0xffff) + (sum >> 16);
	}

	return (int) ((~sum) & 0xffff);
}


const char *netio_ip_precealias(int tos)
{
	switch (tos & 0x7) {
	case NETIO_IP_TOS_ROUTINE:     return "routine";
	case NETIO_IP_TOS_PRIORITY:    return "priority";
	case NETIO_IP_TOS_IMMEDIATE:   return "immediate";
	case NETIO_IP_TOS_FLASH:       return "flash";
	case NETIO_IP_TOS_OVERRIDE:    return "flash/override";
	case NETIO_IP_TOS_CRITIC:      return "CRITIC/ECP";
	case NETIO_IP_TOS_INETCTRL:    return "internetwork control";
	case NETIO_IP_TOS_NETCTRL:     return "network control";
	default:                       return "unknown";
	}
}

const char *netio_ip_delayalias(int tos)
{
	if (tos & NETIO_IP_TOS_LOWDELAY)
		return "low delay";
	else
		return "normal delay";
}

const char *netio_ip_throualias(int tos)
{
	if (tos & NETIO_IP_TOS_HIGHTTHR)
		return "hight throughput";
	else
		return "normal throughput";
}

const char *netio_ip_relibalias(int tos)
{
	if (tos & NETIO_IP_TOS_HIGHTREL)
		return "hight relibility";
	else
		return "normal reliblity";
}

const char *netio_ip_nfrgalias(int tos)
{
	if (tos & NETIO_IP_FLAGS_NOFRAG)
		return "don't fragment";
	else
		return "may fragment";
}

const char *netio_ip_mfrgalias(int tos)
{
	if (tos & NETIO_IP_FLAGS_MRFRAG)
		return "more fragments";
	else
		return "last fragment";
}

const char *netio_ip_protoalias(int proto)
{
	switch (proto) {
	case NETIO_IP_PROTO_TCP:   return "tcp";
	case NETIO_IP_PROTO_UDP:   return "udp";
	default:                   return "unknown";
	}
}


int netio_ip_setversion(netio_ip_t *this, int version)
{
	this->nip_version = version;
	return 0;
}

int netio_ip_setihl(netio_ip_t *this, int ihl)
{
	this->nip_ihl = ihl;
	return 0;
}

int netio_ip_settos(netio_ip_t *this, int tos)
{
	this->nip_tos = tos;
	return 0;
}

int netio_ip_setlen(netio_ip_t *this, int len)
{
	this->nip_len = len;
	return 0;
}

int netio_ip_setid(netio_ip_t *this, int id)
{
	this->nip_id = id;
	return 0;
}

int netio_ip_setflags(netio_ip_t *this, int flags)
{
	this->nip_flags = flags;
	return 0;
}

int netio_ip_setoff(netio_ip_t *this, int off)
{
	this->nip_off = off;
	return 0;
}

int netio_ip_setttl(netio_ip_t *this, int ttl)
{
	this->nip_ttl = ttl;
	return 0;
}

int netio_ip_setproto(netio_ip_t *this, int proto)
{
	this->nip_proto = proto;
	return 0;
}

int netio_ip_setsum(netio_ip_t *this, int sum)
{
	this->nip_sum = sum;
	return 0;
}

int netio_ip_setsrc(netio_ip_t *this, netio_ipaddr_t *src)
{
	this->nip_src = src;
	return 0;
}

int netio_ip_setdest(netio_ip_t *this, netio_ipaddr_t *dest)
{
	this->nip_dest = dest;
	return 0;
}


int netio_ip_getversion(const netio_ip_t *this)
{
	return this->nip_version;
}

int netio_ip_getihl(const netio_ip_t *this)
{
	return this->nip_ihl;
}

int netio_ip_gettos(const netio_ip_t *this)
{
	return this->nip_tos;
}

int netio_ip_getlen(const netio_ip_t *this)
{
	return this->nip_len;
}

int netio_ip_getid(const netio_ip_t *this)
{
	return this->nip_id;
}

int netio_ip_getflags(const netio_ip_t *this)
{
	return this->nip_flags;
}

int netio_ip_getoff(const netio_ip_t *this)
{
	return this->nip_off;
}

int netio_ip_getttl(const netio_ip_t *this)
{
	return this->nip_ttl;
}

int netio_ip_getproto(const netio_ip_t *this)
{
	return this->nip_proto;
}

int netio_ip_getsum(const netio_ip_t *this)
{
	return this->nip_sum;
}

netio_ipaddr_t *netio_ip_getsrc(const netio_ip_t *this)
{
	return this->nip_src;
}

netio_ipaddr_t *netio_ip_getdest(const netio_ip_t *this)
{
	return this->nip_dest;
}
