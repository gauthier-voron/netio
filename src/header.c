#include "netio/header.h"


int netio_header_link(netio_header_t *this, netio_header_t *prev)
{
	this->nh_prev = prev;
	
	if (prev) {
		prev->nh_next = this;
		this->nh_head = prev->nh_head;
	}

	return 0;
}
