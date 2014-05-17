#ifndef PACKET_H
#define PACKET_H

#include <net/if.h>
#include <stdlib.h>


#define NETIO_PACKET_IFLEN     IFNAMSIZ
#define NETIO_PACKET_DATALEN   1500


typedef struct
{
	char      np_ifname[NETIO_PACKET_IFLEN];
	size_t    np_size;
	char      np_data[NETIO_PACKET_DATALEN];
} netio_packet_t;


int netio_packet_read(netio_packet_t *dest, int fd);

int netio_packet_write(const netio_packet_t *src, int fd);

#endif
