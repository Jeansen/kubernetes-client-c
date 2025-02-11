/*
 * v1_limit_response.h
 *
 * LimitResponse defines how to handle requests that can not be executed right now.
 */

#ifndef _v1_limit_response_H_
#define _v1_limit_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_limit_response_t v1_limit_response_t;

#include "v1_queuing_configuration.h"



typedef struct v1_limit_response_t {
    struct v1_queuing_configuration_t *queuing; //model
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_limit_response_t;

__attribute__((deprecated)) v1_limit_response_t *v1_limit_response_create(
    v1_queuing_configuration_t *queuing,
    char *type
);

void v1_limit_response_free(v1_limit_response_t *v1_limit_response);

v1_limit_response_t *v1_limit_response_parseFromJSON(cJSON *v1_limit_responseJSON);

cJSON *v1_limit_response_convertToJSON(v1_limit_response_t *v1_limit_response);

#endif /* _v1_limit_response_H_ */

