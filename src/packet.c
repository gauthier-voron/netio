#include <unistd.h>
#include "netio/packet.h"


int netio_packet_read(netio_packet_t *dest, int fd)
{
	ssize_t ssize;
	size_t size = sizeof(*dest) - NETIO_PACKET_DATALEN;

	ssize = read(fd, dest, size);
	if (ssize < 0 || (size_t) ssize != size)
		return -1;
	
	size = dest->np_size;
	ssize = read(fd, &dest->np_data, size);
	if (ssize < 0 || (size_t) ssize != size)
		return -1;

	return 0;
}

int netio_packet_write(const netio_packet_t *src, int fd)
{
	size_t size = sizeof(*src);
	ssize_t ssize;
	
	if (src->np_size > NETIO_PACKET_DATALEN)
		return -1;
	size -= NETIO_PACKET_DATALEN;
	size += src->np_size;

	ssize = write(fd, src, size);
	if (ssize < 0 || (size_t) ssize != size)
		return -1;
	return 0;
}
