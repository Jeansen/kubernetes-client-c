/*
 * v1_tcp_socket_action.h
 *
 * TCPSocketAction describes an action based on opening a socket
 */

#ifndef _v1_tcp_socket_action_H_
#define _v1_tcp_socket_action_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_tcp_socket_action_t v1_tcp_socket_action_t;

#include "int_or_string.h"



typedef struct v1_tcp_socket_action_t {
    char *host; // string
    int_or_string_t *port; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} v1_tcp_socket_action_t;

__attribute__((deprecated)) v1_tcp_socket_action_t *v1_tcp_socket_action_create(
    char *host,
    int_or_string_t *port
);

void v1_tcp_socket_action_free(v1_tcp_socket_action_t *v1_tcp_socket_action);

v1_tcp_socket_action_t *v1_tcp_socket_action_parseFromJSON(cJSON *v1_tcp_socket_actionJSON);

cJSON *v1_tcp_socket_action_convertToJSON(v1_tcp_socket_action_t *v1_tcp_socket_action);

#endif /* _v1_tcp_socket_action_H_ */

