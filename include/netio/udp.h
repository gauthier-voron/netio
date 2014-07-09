#ifndef NETIO_UDP_H
#define NETIO_UDP_H


struct netio_udp;
typedef struct netio_udp netio_udp_t;


#include "netio/header.h"
#include "netio/protocol.h"


extern netio_protocol_t *NETIO_UDP_PROTOCOL;


struct netio_udp
{
	netio_header_t   nudp_header;
	int              nudp_src;
	int              nudp_dest;
	int              nudp_len;
	int              nudp_sum;
};


int netio_udp_init(netio_udp_t *this);


int netio_udp_checksum(const netio_udp_t *this, const netio_ip_t *pseudo,
		       const char *data, size_t size);

int netio_udp_auto_checksum(const netio_udp_t *this);


int netio_udp_setsrc(netio_udp_t *this, int src);

int netio_udp_setdest(netio_udp_t *this, int dest);

int netio_udp_setlen(netio_udp_t *this, int len);

int netio_udp_setsum(netio_udp_t *this, int sum);


int netio_udp_getsrc(const netio_udp_t *this);

int netio_udp_getdest(const netio_udp_t *this);

int netio_udp_getlen(const netio_udp_t *this);

int netio_udp_getsum(const netio_udp_t *this);


#endif
