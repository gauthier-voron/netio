#ifndef NETIO_IPADDR_H
#define NETIO_IPADDR_H


#include <stdlib.h>


typedef struct
{
	unsigned char  nip_arr[4];
} netio_ipaddr_t;


int netio_ipaddr_init(netio_ipaddr_t *this);


int netio_ipaddr_fromstr(netio_ipaddr_t *this, const char *str);

int netio_ipaddr_fromarr(netio_ipaddr_t *this, const char *arr);


int netio_ipaddr_tostr(const netio_ipaddr_t *this, char *buf);

int netio_ipaddr_toarr(const netio_ipaddr_t *this, char *arr);


#endif
