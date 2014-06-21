#ifndef NETIO_IP_H
#define NETIO_IP_H


struct netio_ip;
typedef struct netio_ip netio_ip_t;


#include "netio/header.h"
#include "netio/ipaddr.h"
#include "netio/protocol.h"


extern netio_protocol_t *NETIO_IP_PROTOCOL;


#define NETIO_IP_TOS_ROUTINE     0
#define NETIO_IP_TOS_PRIORITY    1
#define NETIO_IP_TOS_IMMEDIATE   2
#define NETIO_IP_TOS_FLASH       3
#define NETIO_IP_TOS_OVERRIDE    4
#define NETIO_IP_TOS_CRITIC      5
#define NETIO_IP_TOS_INETCTRL    6
#define NETIO_IP_TOS_NETCTRL     7

#define NETIO_IP_TOS_LOWDELAY    (1 << 3)
#define NETIO_IP_TOS_HIGHTTHR    (1 << 4)
#define NETIO_IP_TOS_HIGHTREL    (1 << 5)

#define NETIO_IP_FLAGS_NOFRAG    (1 << 1)
#define NETIO_IP_FLAGS_MRFRAG    (1 << 2)

#define NETIO_IP_PROTO_TCP       0x06
#define NETIO_IP_PROTO_UDP       0x11


struct netio_ip
{
	netio_header_t   nip_header;
	int              nip_version;
	int              nip_ihl;
	int              nip_tos;
	int              nip_len;
	int              nip_id;
	int              nip_flags;
	int              nip_off;
	int              nip_ttl;
	int              nip_proto;
	int              nip_sum;
	netio_ipaddr_t  *nip_src;
	netio_ipaddr_t  *nip_dest;
};


int netio_ip_init(netio_ip_t *this);


const char *netio_ip_precealias(int tos);

const char *netio_ip_delayalias(int tos);

const char *netio_ip_throualias(int tos);

const char *netio_ip_relibalias(int tos);

const char *netio_ip_nfrgalias(int flags);

const char *netio_ip_mfrgalias(int flags);

const char *netio_ip_protoalias(int proto);


int netio_ip_setversion(netio_ip_t *this, int version);

int netio_ip_setihl(netio_ip_t *this, int ihl);

int netio_ip_settos(netio_ip_t *this, int tos);

int netio_ip_setlen(netio_ip_t *this, int len);

int netio_ip_setid(netio_ip_t *this, int id);

int netio_ip_setflags(netio_ip_t *this, int flags);

int netio_ip_setoff(netio_ip_t *this, int off);

int netio_ip_setttl(netio_ip_t *this, int ttl);

int netio_ip_setproto(netio_ip_t *this, int proto);

int netio_ip_setsum(netio_ip_t *this, int sum);

int netio_ip_setsrc(netio_ip_t *this, netio_ipaddr_t *src);

int netio_ip_setdest(netio_ip_t *this, netio_ipaddr_t *dest);


int netio_ip_getversion(const netio_ip_t *this);

int netio_ip_getihl(const netio_ip_t *this);

int netio_ip_gettos(const netio_ip_t *this);

int netio_ip_getlen(const netio_ip_t *this);

int netio_ip_getid(const netio_ip_t *this);

int netio_ip_getflags(const netio_ip_t *this);

int netio_ip_getoff(const netio_ip_t *this);

int netio_ip_getttl(const netio_ip_t *this);

int netio_ip_getproto(const netio_ip_t *this);

int netio_ip_getsum(const netio_ip_t *this);

netio_ipaddr_t *netio_ip_getsrc(const netio_ip_t *this);

netio_ipaddr_t *netio_ip_getdest(const netio_ip_t *this);


#endif
