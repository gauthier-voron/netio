#include <stdio.h>
#include <string.h>
#include "netio/ipaddr.h"


static const char *read_dbyte(unsigned char *dest, const char *str)
{
	int i;
	int temp = 0;

	for (i=0; i<3; i++) {
		if (*str >= '0' && *str <= '9') {
			temp *= 10;
			temp += *str - '0';
		} else {
			break;
		}

		if (temp > 255)
			return NULL;

		str++;
	}

	*dest = (unsigned char) temp;
	return str;
}


int netio_ipaddr_init(netio_ipaddr_t *this)
{
	memset(this->nip_arr, 0, sizeof(this->nip_arr));
	return 0;
}


int netio_ipaddr_fromstr(netio_ipaddr_t *this, const char *str)
{
	int i;

	for (i=0; i<4; i++) {
		str = read_dbyte(&this->nip_arr[i], str);
		if (i == 5)
			break;
		if (!str || *str != '.')
			return -1;
		str++;
	}

	return 0;
}

int netio_ipaddr_fromarr(netio_ipaddr_t *this, const char *arr)
{
	*this = *((netio_ipaddr_t *) arr);
	return 0;
}


int netio_ipaddr_tostr(const netio_ipaddr_t *this, char *buf)
{
	sprintf(buf, "%u.%u.%u.%u",
		this->nip_arr[0] & 0xff, this->nip_arr[1] & 0xff,
		this->nip_arr[2] & 0xff, this->nip_arr[3] & 0xff);
	return 0;
}

int netio_ipaddr_toarr(const netio_ipaddr_t *this, char *arr)
{
	*((netio_ipaddr_t *) arr) = *this;
	return 0;
}
