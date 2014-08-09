#ifndef NETIO_MACADDR_H
#define NETIO_MACADDR_H


#include <stdlib.h>


typedef struct
{
	unsigned char  nmac_arr[6];
} netio_macaddr_t;


int netio_macaddr_init(netio_macaddr_t *this);


int netio_macaddr_fromstr(netio_macaddr_t *this, const char *str);

int netio_macaddr_fromarr(netio_macaddr_t *this, const char *arr);

int netio_macaddr_fromifn(netio_macaddr_t *this, const char *ifn);


int netio_macaddr_tostr(const netio_macaddr_t *this, char *buf);

int netio_macaddr_toarr(const netio_macaddr_t *this, char *arr);


int netio_macaddr_cmp(const netio_macaddr_t *a, const netio_macaddr_t *b);


#endif
