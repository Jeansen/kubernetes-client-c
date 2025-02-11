/*
 * v1_grpc_action.h
 *
 * GRPCAction specifies an action involving a GRPC service.
 */

#ifndef _v1_grpc_action_H_
#define _v1_grpc_action_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_grpc_action_t v1_grpc_action_t;




typedef struct v1_grpc_action_t {
    int port; //numeric
    char *service; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_grpc_action_t;

__attribute__((deprecated)) v1_grpc_action_t *v1_grpc_action_create(
    int port,
    char *service
);

void v1_grpc_action_free(v1_grpc_action_t *v1_grpc_action);

v1_grpc_action_t *v1_grpc_action_parseFromJSON(cJSON *v1_grpc_actionJSON);

cJSON *v1_grpc_action_convertToJSON(v1_grpc_action_t *v1_grpc_action);

#endif /* _v1_grpc_action_H_ */

