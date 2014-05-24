#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "netio/arp.h"
#include "netio/context.h"
#include "netio/device.h"
#include "netio/ethernet.h"
#include "netio/ipaddr.h"
#include "netio/macaddr.h"
#include "netio/netio.h"
#include "netio/packet.h"
#include "netio/protocol.h"


static int user_at_unpack(netio_context_t *ctx, netio_header_t *cur,
			  const char *data, size_t size)
{
	netio_arp_t *arp;
	netio_ethernet_t *eth;
	const char *str;
	char buffer[18];
	int integer;

	if (cur->nh_protocol == NETIO_DEVICE_PROTOCOL) {
		printf("device:\n");

		str = netio_device_getifname((netio_device_t *) cur);
		printf("  ifname = %s\n", str);

	} else if (cur->nh_protocol == NETIO_ETHERNET_PROTOCOL) {
		eth = (netio_ethernet_t *) cur;

		printf("ethernet:\n");

		netio_macaddr_tostr(netio_ethernet_getdest(eth), buffer);
		printf("  dest = %s\n", buffer);

		netio_macaddr_tostr(netio_ethernet_getsrc(eth), buffer);
		printf("  src  = %s\n", buffer);

		integer = netio_ethernet_gettype(eth);
		printf("  type = %s (0x%04x)\n",
		       netio_ethernet_typealias(integer), integer);

	} else if (cur->nh_protocol == NETIO_ARP_PROTOCOL) {
		arp = (netio_arp_t *) cur;
		
		printf("arp:\n");

		integer = netio_arp_gethrd(arp);
		printf("  hrd  = %s (0x%04x)\n",
		       netio_arp_hrdalias(integer), integer);
		integer = netio_arp_getpro(arp);
		printf("  pro  = %s (0x%04x)\n",
		       netio_arp_proalias(integer), integer);
		printf("  hln  = %d\n", netio_arp_gethln(arp));
		printf("  pln  = %d\n", netio_arp_getpln(arp));
		integer = netio_arp_getop(arp);
		printf("  op   = %s (0x%04x)\n",
		       netio_arp_opalias(integer), integer);

		if (netio_arp_gethrd(arp) == NETIO_ARP_HRD_ETHERNET) {
			netio_macaddr_tostr(netio_arp_getsha(arp), buffer);
			printf("  sha  = %s\n", buffer);
		}

		if (netio_arp_getpro(arp) == NETIO_ARP_PRO_IP) {
			netio_ipaddr_tostr(netio_arp_getspa(arp), buffer);
			printf("  spa  = %s\n", buffer);
		}

		if (netio_arp_gethrd(arp) == NETIO_ARP_HRD_ETHERNET) {
			netio_macaddr_tostr(netio_arp_gettha(arp), buffer);
			printf("  tha  = %s\n", buffer);
		}

		if (netio_arp_getpro(arp) == NETIO_ARP_PRO_IP) {
			netio_ipaddr_tostr(netio_arp_gettpa(arp), buffer);
			printf("  tpa  = %s\n", buffer);
		}
	}

	return cur->nh_protocol->np_chain(ctx, cur, data, size);
}


int main(void)
{
	netio_context_t context;
	netio_packet_t packet;

	netio_context_init(&context);
	netio_context_setatunpack(&context, user_at_unpack);

	while (netio_packet_read(&packet, STDIN_FILENO) != -1)
		netio_context_unpack(&context, &packet);

	return EXIT_SUCCESS;
}
