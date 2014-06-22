#ifndef NETIO_PROTOCOL_H
#define NETIO_PROTOCOL_H


struct netio_protocol;
typedef struct netio_protocol netio_protocol_t;


#include <stdio.h>
#include <stdlib.h>
#include "netio/context.h"
#include "netio/protocol.h"


/*
 * Protocol specific unpacking function.
 * Implementation should:
 * - allocate a protocol specific object on stack which must have a
 *   netio_header_t as first field.
 * - fill this object with informations extracted from the "data" field.
 * - link it with the previous object "prev".
 * - call the unpack function of the context "ctx" and return the result
 *   immediately.
 */
typedef int (*netio_unpack_t)(netio_context_t *ctx, netio_header_t *prev,
			      const char *data, size_t size);

/*
 * Protocol specific payload chaining function.
 * Implementation should:
 * - cast the given "cur" header as a protocol specific object pointer.
 * - use it to determine what is the payload protocol
 * - call the chain function of the context "ctx" and return the result
 *   immediately.
 */
typedef int (*netio_chain_t)(netio_context_t *ctx, netio_header_t *cur,
			     const char *data, size_t size);

typedef int (*netio_print_t)(netio_context_t *ctx, FILE *f,
			     const netio_header_t *cur);

/*
 * Protocol specific reply function.
 * Implementation should:
 * - compute reply addresses when possible (basing on "req").
 * - compute every packet length fields since the payloads (in "next") are
 *   already computed.
 * - compute every checksum fields.
 * - not make any assumptions on the packet semantic.
 */
typedef int (*netio_reply_t)(netio_context_t *ctx, netio_header_t *next,
			     const netio_header_t *req);

typedef int (*netio_repack_t)(netio_context_t *ctx, const netio_header_t *cur,
			      char *data, size_t *size);


struct netio_protocol
{
	netio_unpack_t  np_unpack;
	netio_chain_t   np_chain;
	netio_print_t   np_print;
	netio_reply_t   np_reply;
	netio_repack_t  np_repack;
};


#endif
