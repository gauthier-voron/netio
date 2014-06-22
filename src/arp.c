#include <arpa/inet.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "netio/arp.h"
#include "netio/ipaddr.h"
#include "netio/macaddr.h"
#include "netio/raw.h"


struct __arp
{
	uint16_t  hrd;
	uint16_t  pro;
	uint8_t   hln;
	uint8_t   pln;
	uint16_t  op;
} __attribute__((packed));

static int netio_arp_unpack(netio_context_t *ctx, netio_header_t *prev,
			    const char *data, size_t size)
{
	void *ptr;
	size_t incr;
	netio_arp_t arp;
	const struct __arp *__arp;

	if (size < sizeof(struct __arp))
		return -1;

	netio_arp_init(&arp);
	netio_header_link(&arp.narp_header, prev);

	__arp = (const struct __arp *) data;
	netio_arp_sethrd(&arp, ntohs(__arp->hrd));
	netio_arp_setpro(&arp, ntohs(__arp->pro));
	netio_arp_sethln(&arp, __arp->hln);
	netio_arp_setpln(&arp, __arp->pln);
	netio_arp_setop(&arp, ntohs(__arp->op));

	if (size < ( sizeof(struct __arp)
		     + 2 * netio_arp_gethln(&arp)
		     + 2 * netio_arp_getpln(&arp) ))
		return -1;

	if (netio_arp_gethrd(&arp) == NETIO_ARP_HRD_ETHERNET) {
		incr = sizeof(struct __arp);
		ptr = alloca(sizeof(netio_macaddr_t));
		netio_macaddr_fromarr(ptr, data + incr);
		netio_arp_setsha(&arp, ptr);

		incr += netio_arp_gethln(&arp);
		incr += netio_arp_getpln(&arp);
		ptr = alloca(sizeof(netio_macaddr_t));
		netio_macaddr_fromarr(ptr, data + incr);
		netio_arp_settha(&arp, ptr);
	}

	if (netio_arp_getpro(&arp) == NETIO_ARP_PRO_IP) {
		incr = sizeof(struct __arp);
		incr += netio_arp_gethln(&arp);
		ptr = alloca(sizeof(netio_ipaddr_t));
		netio_ipaddr_fromarr(ptr, data + incr);
		netio_arp_setspa(&arp, ptr);

		incr += netio_arp_getpln(&arp);
		incr += netio_arp_gethln(&arp);
		ptr = alloca(sizeof(netio_ipaddr_t));
		netio_ipaddr_fromarr(ptr, data + incr);
		netio_arp_settpa(&arp, ptr);
	}

	incr = sizeof(struct __arp)
		+ 2 * netio_arp_gethln(&arp)
		+ 2 * netio_arp_getpln(&arp);
	data += incr;
	size -= incr;

	return ctx->nc_at_unpack(ctx, &arp.narp_header, data, size);
}

static int netio_arp_chain(netio_context_t *ctx, netio_arp_t *cur,
			   const char *data, size_t size)
{
	const netio_protocol_t *next = NULL;

	if (size > 0)
		next = NETIO_RAW_PROTOCOL;

	return ctx->nc_at_chain(ctx, &cur->narp_header, data, size, next);
}

static int netio_arp_print(netio_context_t *ctx, FILE *f,
			   const netio_arp_t *cur)
{
	int tmp;
	char buffer[32];

	fprintf(f, "arp\n");
	
	tmp = netio_arp_gethrd(cur);
	fprintf(f, "%-30s %s (0x%04x)\n", "  hardware type",
	       netio_arp_hrdalias(tmp), tmp);

	tmp = netio_arp_getpro(cur);
	fprintf(f, "%-30s %s (0x%04x)\n", "  protocol type",
	       netio_arp_proalias(tmp), tmp);

	fprintf(f, "%-30s %d\n", "  hardware length", netio_arp_gethln(cur));
	fprintf(f, "%-30s %d\n", "  protocole length", netio_arp_getpln(cur));

	tmp = netio_arp_getop(cur);
	fprintf(f, "%-30s %s (0x%04x)\n", "  operation code",
	       netio_arp_opalias(tmp), tmp);

	netio_macaddr_tostr(netio_arp_getsha(cur), buffer);
	fprintf(f, "%-30s %s\n", "  hardware source", buffer);

	netio_ipaddr_tostr(netio_arp_getspa(cur), buffer);
	fprintf(f, "%-30s %s\n", "  protocol source", buffer);

	netio_macaddr_tostr(netio_arp_gettha(cur), buffer);
	fprintf(f, "%-30s %s\n", "  hardware target", buffer);

	netio_ipaddr_tostr(netio_arp_gettpa(cur), buffer);
	fprintf(f, "%-30s %s\n", "  protocol target", buffer);

	return ctx->nc_at_print(ctx, f, &cur->narp_header,
				cur->narp_header.nh_next);
}

static int netio_arp_reply(netio_context_t *ctx, netio_header_t *next,
			   const netio_arp_t *req)
{
	netio_arp_t rep;
	int op;

	netio_arp_init(&rep);
	netio_header_fill(&rep.narp_header, next);

	netio_arp_sethrd(&rep, netio_arp_gethrd(req));
	netio_arp_setpro(&rep, netio_arp_getpro(req));
	netio_arp_sethln(&rep, netio_arp_gethln(req));
	netio_arp_setpln(&rep, netio_arp_getpln(req));

	switch (netio_arp_getop(req)) {
	case NETIO_ARP_OP_REQUEST:
		op = NETIO_ARP_OP_REPLY;
		break;
	case NETIO_ARP_OP_REPLY:
		op = NETIO_ARP_OP_REQUEST;
		break;
	default:
		op = netio_arp_getop(req);
		break;
	}
	netio_arp_setop(&rep, op);

	netio_arp_setsha(&rep, netio_arp_gettha(req));
	netio_arp_setspa(&rep, netio_arp_gettpa(req));
	netio_arp_settha(&rep, netio_arp_getsha(req));
	netio_arp_settpa(&rep, netio_arp_getspa(req));

	return ctx->nc_at_reply(ctx, &rep.narp_header, &req->narp_header);
}


netio_protocol_t __NETIO_ARP_PROTOCOL = {
	(netio_unpack_t) netio_arp_unpack,
	(netio_chain_t)  netio_arp_chain,
	(netio_print_t)  netio_arp_print,
	(netio_reply_t)  netio_arp_reply
};

netio_protocol_t *NETIO_ARP_PROTOCOL = &__NETIO_ARP_PROTOCOL;


int netio_arp_init(netio_arp_t *this)
{
	netio_header_init(&this->narp_header, NETIO_ARP_PROTOCOL);
	
	this->narp_hrd = 0;
	this->narp_pro = 0;
	this->narp_hln = 0;
	this->narp_pln = 0;
	this->narp_op  = 0;

	return 0;
}


const char *netio_arp_hrdalias(int hrd)
{
	switch (hrd) {
	case NETIO_ARP_HRD_ETHERNET:
		return "ethernet";
	default:
		return "unknown";
	}
}

const char *netio_arp_proalias(int pro)
{
	switch (pro) {
	case NETIO_ARP_PRO_IP:
		return "ip";
	default:
		return "unknown";
	}
}

const char *netio_arp_opalias(int op)
{
	switch (op) {
	case NETIO_ARP_OP_REQUEST:
		return "request";
	case NETIO_ARP_OP_REPLY:
		return "reply";
	default:
		return "unknown";
	}
}


int netio_arp_sethrd(netio_arp_t *this, int hrd)
{
	this->narp_hrd = hrd;
	return 0;
}

int netio_arp_setpro(netio_arp_t *this, int pro)
{
	this->narp_pro = pro;
	return 0;
}

int netio_arp_sethln(netio_arp_t *this, int hln)
{
	this->narp_hln = hln;
	return 0;
}

int netio_arp_setpln(netio_arp_t *this, int pln)
{
	this->narp_pln = pln;
	return 0;
}

int netio_arp_setop(netio_arp_t *this, int op)
{
	this->narp_op = op;
	return 0;
}

int netio_arp_setsha(netio_arp_t *this, void *sha)
{
	this->narp_sha = sha;
	return 0;
}

int netio_arp_setspa(netio_arp_t *this, void *spa)
{
	this->narp_spa = spa;
	return 0;
}

int netio_arp_settha(netio_arp_t *this, void *tha)
{
	this->narp_tha = tha;
	return 0;
}

int netio_arp_settpa(netio_arp_t *this, void *tpa)
{
	this->narp_tpa = tpa;
	return 0;
}


int netio_arp_gethrd(const netio_arp_t *this)
{
	return this->narp_hrd;
}

int netio_arp_getpro(const netio_arp_t *this)
{
	return this->narp_pro;
}

int netio_arp_gethln(const netio_arp_t *this)
{
	return this->narp_hln;
}

int netio_arp_getpln(const netio_arp_t *this)
{
	return this->narp_pln;
}

int netio_arp_getop(const netio_arp_t *this)
{
	return this->narp_op;
}

void *netio_arp_getsha(const netio_arp_t *this)
{
	return this->narp_sha;
}

void *netio_arp_getspa(const netio_arp_t *this)
{
	return this->narp_spa;
}

void *netio_arp_gettha(const netio_arp_t *this)
{
	return this->narp_tha;
}

void *netio_arp_gettpa(const netio_arp_t *this)
{
	return this->narp_tpa;
}
