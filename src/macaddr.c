#include <stdio.h>
#include <string.h>
#include "netio/macaddr.h"


static const char *read_hex(unsigned char *dest, const char *str)
{
	int i;

	*dest = 0;

	for (i=0; i<2; i++) {
		*dest *= 16;

		if (*str >= '0' && *str <= '9')
			*dest += *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			*dest += *str - 'a';
		else if (*str >= 'A' && *str <= 'F')
			*dest += *str - 'A';
		else
			return NULL;

		str++;
	}

	return str;
}


int netio_macaddr_init(netio_macaddr_t *this)
{
	memset(this->nmac_arr, 0, sizeof(this->nmac_arr));
	return 0;
}


int netio_macaddr_fromstr(netio_macaddr_t *this, const char *str)
{
	int i;

	for (i=0; i<6; i++) {
		str = read_hex(&this->nmac_arr[i], str);
		if (!str || *str != ':')
			return -1;
		if (i < 5)
			str++;
	}

	return 0;
}

int netio_macaddr_fromarr(netio_macaddr_t *this, const char *arr)
{
	*this = *((netio_macaddr_t *) arr);
	return 0;
}


int netio_macaddr_tostr(const netio_macaddr_t *this, char *buf)
{
	sprintf(buf, "%02x:%02x:%02x:%02x:%02x:%02x",
		this->nmac_arr[0] & 0xff, this->nmac_arr[1] & 0xff,
		this->nmac_arr[2] & 0xff, this->nmac_arr[3] & 0xff,
		this->nmac_arr[4] & 0xff, this->nmac_arr[5] & 0xff);
	return 0;
}

int netio_macaddr_toarr(const netio_macaddr_t *this, char *arr)
{
	*((netio_macaddr_t *) arr) = *this;
	return 0;
}
