#ifndef NETIO_PROTOCOL_H
#define NETIO_PROTOCOL_H


struct netio_protocol;
typedef struct netio_protocol netio_protocol_t;


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

typedef int (*netio_print_t)(netio_context_t *ctx, const netio_header_t *cur);


struct netio_protocol
{
	netio_unpack_t  np_unpack;
	netio_chain_t   np_chain;
	netio_print_t   np_print;
};


#endif
