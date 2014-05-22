#ifndef NETIO_MACADDR_H
#define NETIO_MACADDR_H


#include <stdlib.h>


typedef struct
{
	unsigned char  nmac_arr[6];
} netio_macaddr_t;


int netio_macaddr_fromstr(netio_macaddr_t *this, const char *str);

int netio_macaddr_fromarr(netio_macaddr_t *this, const char *arr);


int netio_macaddr_tostr(const netio_macaddr_t *this, char *buf, size_t size);

int netio_macaddr_toarr(const netio_macaddr_t *this, char *arr);


#endif
