#include <net/if.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>
#include "netio/device.h"
#include "netio/ethernet.h"
#include "netio/raw.h"


static int netio_dev_chain(netio_context_t *ctx, netio_device_t *cur,
			   const char *data, size_t size)
{
	const netio_protocol_t *next = NULL;

	if (size == 0)
		goto ret;

	switch (cur->ndev_ifname[0]) {
	case 'e':
		next = NETIO_ETHERNET_PROTOCOL;
		break;
	default:
		next = NETIO_RAW_PROTOCOL;
		break;
	}

 ret:
	return ctx->nc_at_chain(ctx, &cur->ndev_header, data, size, next);
}

static int netio_dev_print(netio_context_t *ctx, FILE *f,
			   const netio_device_t *cur)
{
	fprintf(f, "device\n");
	fprintf(f, "%-30s %s\n", "  interface name", cur->ndev_ifname);
	return ctx->nc_at_print(ctx, f, &cur->ndev_header,
				cur->ndev_header.nh_next);
}

static int netio_dev_reply(netio_context_t *ctx, netio_header_t *next,
			   const netio_device_t *req)
{
	netio_device_t rep;

	netio_device_init(&rep);
	netio_header_fill(&rep.ndev_header, next);

	netio_device_setifname(&rep, netio_device_getifname(req));

	return ctx->nc_at_reply(ctx, &rep.ndev_header, &req->ndev_header);
}


netio_protocol_t __NETIO_DEVICE_PROTOCOL = {
	(netio_unpack_t) NULL,
	(netio_chain_t)  netio_dev_chain,
	(netio_print_t)  netio_dev_print,
	(netio_reply_t)  netio_dev_reply,
	(netio_repack_t) NULL
};

netio_protocol_t *NETIO_DEVICE_PROTOCOL = &__NETIO_DEVICE_PROTOCOL;


int netio_device_init(netio_device_t *this)
{
	netio_header_init(&this->ndev_header, NETIO_DEVICE_PROTOCOL);

	this->ndev_ifname = NULL;

	return 0;
}


static int netio_device_getifconf(struct ifreq *buffer, size_t size)
{
	int fd, ret;
	int len = size * sizeof(*buffer);
	struct ifconf ifconf;

	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1)
		return -1;

	ifconf.ifc_len = len;
	ifconf.ifc_buf = (char *) buffer;

	ret = ioctl(fd, SIOCGIFCONF, &ifconf);
	if (close(fd) != 0 || ret != 0)
		return -1;

	if (ifconf.ifc_len == len)
		return 0;
	return ifconf.ifc_len / sizeof(*buffer);
}

static int netio_device_putifnames(char *buffer, size_t size,
				   const struct ifreq *ifs, int count)
{
	int i;
	size_t len;

	for (i=0; i<count; i++) {
		len = strnlen(ifs[i].ifr_name, size);
		if (len >= size)
			break;

		strncpy(buffer, ifs[i].ifr_name, size);
		size -= len + 1;
		buffer += len + 1;
	}

	return i;
}

int netio_device_listifnames(char *buffer, size_t size)
{
	int count;
	size_t arrsize = 16;
	struct ifreq *arr;

	do {
		arr = alloca(arrsize * sizeof(*arr));
		count = netio_device_getifconf(arr, arrsize);
		arrsize *= 2;
	} while (count == 0);

	if (count < 0)
		return -1;

	return netio_device_putifnames(buffer, size, arr, count);
}

int netio_device_getifflags(const char *ifname)
{
	int fd, ret;
	struct ifreq ifreq;
	size_t size = sizeof(ifreq.ifr_name);

	ifreq.ifr_name[size - 1] = '\0';
	strncpy(ifreq.ifr_name, ifname, size);
	if (ifreq.ifr_name[size - 1] != '\0')
		return -1;

	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return -1;
	ret = ioctl(fd, SIOCGIFFLAGS, &ifreq);
	if (close(fd) != 0 || ret != 0)
		return -1;

	return ifreq.ifr_flags;
}


int netio_device_setifname(netio_device_t *this, const char *ifname)
{
	this->ndev_ifname = ifname;
	return 0;
}


const char *netio_device_getifname(const netio_device_t *this)
{
	return this->ndev_ifname;
}
