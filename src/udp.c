#include <arpa/inet.h>
#include <stdint.h>
#include "netio/context.h"
#include "netio/ip.h"
#include "netio/ipaddr.h"
#include "netio/udp.h"
#include "netio/raw.h"


struct __udp
{
	uint16_t  src;
	uint16_t  dest;
	uint16_t  len;
	uint16_t  sum;
} __attribute__((packed));

static int netio_udp_unpack(netio_context_t *ctx, netio_header_t *prev,
			    const char *data, size_t size)
{
	netio_udp_t udp;
	const struct __udp *__udp;

	if (size < sizeof(*__udp))
		return -1;

	netio_udp_init(&udp);
	netio_header_link(&udp.nudp_header, prev);

	__udp = (const struct __udp *) data;

	netio_udp_setsrc(&udp, ntohs(__udp->src));
	netio_udp_setdest(&udp, ntohs(__udp->dest));
	netio_udp_setlen(&udp, ntohs(__udp->len));
	netio_udp_setsum(&udp, ntohs(__udp->sum));

	data += sizeof(*__udp);
	size -= sizeof(*__udp);

	return ctx->nc_at_unpack(ctx, &udp.nudp_header, data, size);
}

static int netio_udp_chain(netio_context_t *ctx, netio_udp_t *cur,
			   const char *data, size_t size)
{
	const netio_protocol_t *next = NULL;

	if (size > 0)
		next = NETIO_RAW_PROTOCOL;

	return ctx->nc_at_chain(ctx, &cur->nudp_header, data, size, next);
}

static int netio_udp_print(netio_context_t *ctx, FILE *f,
			  const netio_udp_t *cur)
{
	fprintf(f, "udp\n");
	
	fprintf(f, "%-30s %d\n", "  source", netio_udp_getsrc(cur));
	fprintf(f, "%-30s %d\n", "  destination", netio_udp_getdest(cur));
	fprintf(f, "%-30s %d\n", "  length", netio_udp_getlen(cur));
	fprintf(f, "%-30s 0x%04x\n", "  checksum", netio_udp_getsum(cur));

	return ctx->nc_at_print(ctx, f, &cur->nudp_header,
				cur->nudp_header.nh_next);
}

static int netio_udp_reply(netio_context_t *ctx, netio_header_t *next,
			   const netio_udp_t *req)
{
	netio_udp_t rep;
	size_t len = (uint16_t) -1;
	int ret;

	netio_udp_init(&rep);
	netio_header_fill(&rep.nudp_header, next);

	ret = ctx->nc_at_repack(ctx, next, NULL, &len);
	if (ret)
		return ret;
	len = ((uint16_t) -1) - len;

	netio_udp_setsrc(&rep, netio_udp_getdest(req));
	netio_udp_setdest(&rep, netio_udp_getsrc(req));
	netio_udp_setlen(&rep, len);

	netio_udp_setsum(&rep, netio_udp_getsum(req) * 0);

	return ctx->nc_at_reply(ctx, &rep.nudp_header, &req->nudp_header);
}

static int netio_udp_repack(netio_context_t *ctx, const netio_udp_t *cur,
			    char *data, size_t *size)
{
	struct __udp *__udp;

	if (*size < sizeof(*__udp)) {
		*size = 0;
		return -1;
	}
	*size -= sizeof(*__udp);

	if (data) {
		__udp = (struct __udp *) data;
		__udp->src = htons(netio_udp_getsrc(cur));
		__udp->dest = htons(netio_udp_getdest(cur));
		__udp->len = htons(netio_udp_getlen(cur));
		__udp->sum = htons(netio_udp_getsum(cur));

		data += sizeof(*__udp);
	}

	return ctx->nc_at_repack(ctx, cur->nudp_header.nh_next, data, size);
}


netio_protocol_t __NETIO_UDP_PROTOCOL = {
	(netio_unpack_t) netio_udp_unpack,
	(netio_chain_t)  netio_udp_chain,
	(netio_print_t)  netio_udp_print,
	(netio_reply_t)  netio_udp_reply,
	(netio_repack_t) netio_udp_repack
};

netio_protocol_t *NETIO_UDP_PROTOCOL = &__NETIO_UDP_PROTOCOL;


int netio_udp_init(netio_udp_t *this)
{
	netio_header_init(&this->nudp_header, NETIO_UDP_PROTOCOL);

	this->nudp_src = 0;
	this->nudp_dest = 0;
	this->nudp_len = 0;
	this->nudp_sum = 0;

	return 0;
}


struct __udp_pseudo
{
	uint32_t     src;
	uint32_t     dest;
	uint8_t      zero;
	uint8_t      proto;
	uint16_t     len;
} __attribute__((packed));

static uint16_t netio_udp_pseudo_checksum(const netio_udp_t *this,
					  const netio_ip_t *pseudo,
					  uint16_t sum)
{
	struct __udp_pseudo __pseudo;
	uint32_t __sum = sum & 0xffff;
	const uint16_t *arr = ((uint16_t *) &__pseudo);
	size_t i;

	netio_ipaddr_toarr(netio_ip_getsrc(pseudo), (char *) &__pseudo.src);
	netio_ipaddr_toarr(netio_ip_getdest(pseudo), (char *) &__pseudo.dest);
	__pseudo.zero = 0;
	__pseudo.proto = netio_ip_getproto(pseudo);
	__pseudo.len = htons(netio_udp_getlen(this));

	for (i=0; i<(sizeof(__pseudo) / sizeof(uint16_t)); i++) {
		__sum += ntohs(arr[i]);
		__sum = (__sum & 0xffff) + (__sum >> 16);
	}

	return ((uint16_t) (__sum & 0xffff));
}

static uint16_t netio_udp_udp_checksum(const netio_udp_t *this, uint16_t sum)
{
	struct __udp __udp;
	uint32_t __sum = sum & 0xffff;
	const uint16_t *arr = ((uint16_t *) &__udp);
	size_t i;

	__udp.src = htons(netio_udp_getsrc(this));
	__udp.dest = htons(netio_udp_getdest(this));
	__udp.len = htons(netio_udp_getlen(this));
	__udp.sum = 0;

	for (i=0; i<(sizeof(__udp) / sizeof(uint16_t)); i++) {
		__sum += ntohs(arr[i]);
		__sum = (__sum & 0xffff) + (__sum >> 16);
	}

	return ((uint16_t) (__sum & 0xffff));
}

static uint16_t netio_udp_data_checksum(const char *data, size_t size,
					uint16_t sum)
{
	uint32_t __sum = sum & 0xffff;
	const uint16_t *arr = ((const uint16_t *) data);
	size_t i;

	for (i=0; i<(size / sizeof(uint16_t)); i++) {
		__sum += ntohs(arr[i]);
		__sum = (__sum & 0xffff) + (__sum >> 16);
	}

	if (size % sizeof(uint16_t)) {
		i *= sizeof(uint16_t);
		__sum += data[i] << 8;
		__sum = (__sum & 0xffff) + (__sum >> 16);
	}

	return ((uint16_t) (__sum & 0xffff));
}

int netio_udp_checksum(const netio_udp_t *this, const netio_ip_t *pseudo,
		       const char *data, size_t size)
{
	uint16_t sum = 0;

	sum = netio_udp_pseudo_checksum(this, pseudo, sum);
	sum = netio_udp_udp_checksum(this, sum);
	sum = netio_udp_data_checksum(data, size, sum);

	sum = ((~sum) & 0xffff);
	return (int) ((sum) ? sum : ((uint16_t) -1));
}

int netio_udp_auto_checksum(const netio_udp_t *this)
{
	netio_header_t *next = this->nudp_header.nh_next;
	netio_header_t *prev = this->nudp_header.nh_prev;
	netio_ip_t *ip = ((netio_ip_t *) prev);
	netio_context_t ctx;
	char *data = NULL;
	size_t size = 0, rem;
	int ret;
	
	if (!prev || prev->nh_protocol != NETIO_IP_PROTOCOL)
		return 0;
	if (next) {
		netio_context_init(&ctx);
		size = 1500;
		do {
			rem = size;
			data = alloca(size);

			ret = netio_context_getatrepack(&ctx)
				(&ctx, next, data, &rem);

			if (ret != 0)
				return 0;
			size *= 2;
		} while (rem == 0);

		size = size / 2 - rem;
	}

	return netio_udp_checksum(this, ip, data, size);
}


int netio_udp_setsrc(netio_udp_t *this, int src)
{
	this->nudp_src = src;
	return 0;
}

int netio_udp_setdest(netio_udp_t *this, int dest)
{
	this->nudp_dest = dest;
	return 0;
}

int netio_udp_setlen(netio_udp_t *this, int len)
{
	this->nudp_len = len;
	return 0;
}

int netio_udp_setsum(netio_udp_t *this, int sum)
{
	this->nudp_sum = sum;
	return 0;
}


int netio_udp_getsrc(const netio_udp_t *this)
{
	return this->nudp_src;
}

int netio_udp_getdest(const netio_udp_t *this)
{
	return this->nudp_dest;
}

int netio_udp_getlen(const netio_udp_t *this)
{
	return this->nudp_len;
}

int netio_udp_getsum(const netio_udp_t *this)
{
	return this->nudp_sum;
}
