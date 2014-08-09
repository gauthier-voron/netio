#include <arpa/inet.h>
#include <net/if.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>
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
		if (i == 3)
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

int netio_ipaddr_fromifn(netio_ipaddr_t *this, const char *ifn)
{
	int fd, ret;
	struct ifreq ifreq;
	struct sockaddr_in *sin;
	size_t size = sizeof(ifreq.ifr_name);

	ifreq.ifr_name[size - 1] = '\0';
	strncpy(ifreq.ifr_name, ifn, size);
	if (ifreq.ifr_name[size - 1] != '\0')
		return -1;
	ifreq.ifr_addr.sa_family = AF_INET;

	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return -1;
	ret = ioctl(fd, SIOCGIFADDR, &ifreq);
	if (close(fd) != 0 || ret != 0)
		return -1;

	sin = (struct sockaddr_in *) &ifreq.ifr_addr;
	*this = *((netio_ipaddr_t *) &sin->sin_addr);
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


int netio_ipaddr_cmp(const netio_ipaddr_t *a, const netio_ipaddr_t *b)
{
	return memcmp(a->nip_arr, b->nip_arr, sizeof(a->nip_arr));
}
