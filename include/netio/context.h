#ifndef NETIO_CONTEXT_H
#define NETIO_CONTEXT_H


struct netio_context;
typedef struct netio_context netio_context_t;


#include "netio/header.h"
#include "netio/packet.h"
#include "netio/protocol.h"


/*
 * Context specific post unpack handler.
 * Implementation can be used to perform user related treatment in a given
 * context right after the last payload has been unpacked.
 * To continue the unpacking normally, implementation should call the
 * chain function of the current protocol "cur->nh_protocol->np_chain".
 */
typedef int (*netio_at_unpack_t)(netio_context_t *ctx, netio_header_t *cur,
				 const char *payload, size_t size);

/*
 * Context specific post chain handler.
 * Implementation can be used to perform user related treatment in a given
 * context right after the last chaining.
 * To continue the unpacking normally, implementation should call the
 * unpack function of the next protocol "next->np_unpack".
 */
typedef int (*netio_at_chain_t)(netio_context_t *ctx, netio_header_t *prev,
				const char *payload, size_t size,
				const netio_protocol_t *next);

typedef int (*netio_at_print_t)(netio_context_t *ctx, FILE *f,
				const netio_header_t *prev,
				const netio_header_t *next);

/*
 * Context specific post reply handle.
 * Implementation can be used to perform user related treatment in a given
 * context right after the default reply.
 * Default reply are best-effort and try to resolve as much field as possible.
 * Other fields are not filled and contain unspecified values.
 */
typedef int (*netio_at_reply_t)(netio_context_t *ctx, netio_header_t *rep,
				const netio_header_t *req);


struct netio_context
{
	netio_at_unpack_t  nc_at_unpack;
	netio_at_chain_t   nc_at_chain;
	netio_at_print_t   nc_at_print;
	netio_at_reply_t   nc_at_reply;
};


int netio_context_init(netio_context_t *this);

int netio_context_unpack(netio_context_t *this, const netio_packet_t *packet);

int netio_context_print(netio_context_t *this, FILE *f,
			const netio_header_t *header);

int netio_context_reply(netio_context_t *this, const netio_header_t *header);


int netio_context_setatunpack(netio_context_t *this, netio_at_unpack_t handle);

int netio_context_setatchain(netio_context_t *this, netio_at_chain_t handle);

int netio_context_setatprint(netio_context_t *this, netio_at_print_t handle);

int netio_context_setatreply(netio_context_t *this, netio_at_reply_t handle);


netio_at_unpack_t netio_context_getatunpack(const netio_context_t *this);

netio_at_chain_t netio_context_getatchain(const netio_context_t *this);

netio_at_print_t netio_context_getatprint(const netio_context_t *this);

netio_at_reply_t netio_context_getatreply(const netio_context_t *this);


#endif
