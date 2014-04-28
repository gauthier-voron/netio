int __netio_context_unpack (netio_context_t *context, netio_header_t *current,
			    const char *data, size_t size)
{
	return current->nhd_protocol->npt_chain (context, current, data, size);
}

int __netio_context_chain (netio_context_t *context, netio_header_t *prev,
			   const char *data, size_t size,
			   const netio_protocol_t *next)
{
	return next->npt_unpack (context, prev, data, size);
}

int __netio_context_reply (netio_context_t *context, netio_header_t *prev,
			   netio_header_t *req)
{
	return req->nhd_protocol->npt_reply (context, prev, req);
}


int netio_ethernet_unpack (netio_context_t *context, netio_header_t *prev,
			   const char *data, size_t size)
{
	netio_ethernet_t eth;

	if (size < ETHERNET_SIZE) {
		context->ncx_errmsg = "Corrupted packet";
		return -1;
	}

	/* netio_ethernet_init (&eth); */
	eth.ne_header.nhd_protocol = NETIO_ETHERNET_PROTOCOL;
	eth.ne_header.nhd_payload = NULL;
	eth.ne_header.nhd_container = NULL;
	eth.ne_header.nhd_base = &eth;

	/* netio_ethernet_link (&eth, prev); */
	prev->nhd_payload = &eth;
	eth.ne_header.nhd_container = prev;
	eth.ne_header.nhd_base = prev->nhd_base;

	eth.ne_data = data;

	data += ETHERNET_SIZE;
	size -= ETHERNET_SIZE;

	return context->ncx_unpack (context, &eth->ne_header, data, size);
}

int netio_ethernet_chain (netio_context_t *context, netio_ethernet_t *eth,
			  const char *data, size_t size)
{
	const netio_protocol_t *next;

	switch (netio_ethernet_getop (eth)) {
	case NETIO_ETHERNET_OP_ARP:
		next = NETIO_ARP_PROTOCOL;
		break;
	default:
		next = NETIO_RAW_PROTOCOL;
		break;
	}

	return context->ncx_chain (context, &eth->ne_header, data, size, next);
}

int netio_ethernet_reply (netio_context_t *context, netio_header_t *prev,
			  netio_ethernet_t *req)
{
	netio_ethernet_t rep;
	netio_header_t *next;

	netio_ethernet_init (&rep);
	netio_ethernet_link (&rep, prev);

	netio_ethernet_setsrc (netio_ethernet_getdest (req));
	netio_ethernet_setdest (netio_ethernet_getsrc (req));

	next = netio_ethernet_getpayload (req);
	return context->ncx_reply (context, &rep->ne_header, next);
}


int my_chain (netio_context_t *context, netio_header_t *prev,
	      const char *data, size_t size, const netio_protocol_t *next)
{
	int op;

	if (size == 0 && prev->npt_protocol == NETIO_ARP_PROTOCOL) {
		op = netio_arp_getop ((netio_arp_t *) prev);
		if (op != NETIO_ARP_OP_REQUEST)
			return 0;
		return netio_context_reply (context, prev->nhd_base);
	} else {
		return next->npt_chain (context, prev, data, size);
	}
}

int my_reply (netio_context_t *context, netio_header_t *prev,
	      netio_header_t *req)
{
	int ret;
	netio_packet_t packet;
	netio_macaddr_t *spoofed;
	netio_arp_t *arp;

	if (req == NULL) {
		arp = (netio_arp_t *) prev;
		spoofed = (netio_macaddr_t *) netio_context_getudata (context);
		netio_arp_setspa (arp, spoofed);

		ret = netio_context_repack (context, &packet);
		netio_packet_fwrite (&packet, stdout);

		return ret;
	} else {
		return req->nhd_protocol->npt_reply (context, prev, req);
	}
}



int my_print_chain (netio_context_t *context, netio_header_t *prev,
		    const char *data, size_t size, const netio_protocol_t *nxt)
{
	if (size == 0) {
		return netio_context_fprint (context, prev->nhd_base, stdout);
	} else {
		return nxt->npt_chain (context, prev, data, size);
	}
}



void send_fake_arp (void)
{
	netio_context_t context;
	netio_packet_t packet;

	netio_device_t dev;
	netio_ethernet_t eth;
	netio_arp_t arp;

	netio_macaddr_t macsrc, macdest;
	netio_ipaddr_t ipsrc, ipdest;


	netio_macaddr_set (&macsrc, "00:11:22:33:44:55");
	netio_macaddr_set (&macdest, "aa:bb:cc:dd:ee:ff");
	netio_ipaddr_set (&ipsrc, "192.168.0.1");
	netio_ipaddr_set (&ipdest, "192.168.0.12");

	netio_device_init (&dev);
	netio_device_setifname (&dev, "eth0");

	netio_ethernet_init (&eth);
	netio_ethernet_setop (&eth, NETIO_ETHERNET_OP_ARP);
	netio_ethernet_setsrc (&eth, &macsrc);
	netio_ethernet_setdest (&eth, &macdest);
	netio_ethernet_link (&eth, &dev);

	netio_arp_init (&arp);
	netio_arp_sethrd (&arp, NETIO_ARP_HRD_ETHERNET);
	netio_arp_setpro (&arp, NETIO_ARP_PRO_IP);
	netio_arp_setop (&arp, NETIO_ARP_OP_REPLY);
	netio_arp_setsha (&arp, &macsrc);
	netio_arp_setspa (&arp, &ipsrc);
	netio_arp_settha (&arp, &macdest);
	netio_arp_settpa (&arp, &ipdest);
	netio_arp_link (&arp, &eth);


	netio_context_repack (&context, &packet);
	netio_packet_fwrite (&packet, stdout);
}
