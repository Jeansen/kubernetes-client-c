/*
 * v1_ingress_load_balancer_ingress.h
 *
 * IngressLoadBalancerIngress represents the status of a load-balancer ingress point.
 */

#ifndef _v1_ingress_load_balancer_ingress_H_
#define _v1_ingress_load_balancer_ingress_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_load_balancer_ingress_t v1_ingress_load_balancer_ingress_t;

#include "v1_ingress_port_status.h"



typedef struct v1_ingress_load_balancer_ingress_t {
    char *hostname; // string
    char *ip; // string
    list_t *ports; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_ingress_load_balancer_ingress_t;

__attribute__((deprecated)) v1_ingress_load_balancer_ingress_t *v1_ingress_load_balancer_ingress_create(
    char *hostname,
    char *ip,
    list_t *ports
);

void v1_ingress_load_balancer_ingress_free(v1_ingress_load_balancer_ingress_t *v1_ingress_load_balancer_ingress);

v1_ingress_load_balancer_ingress_t *v1_ingress_load_balancer_ingress_parseFromJSON(cJSON *v1_ingress_load_balancer_ingressJSON);

cJSON *v1_ingress_load_balancer_ingress_convertToJSON(v1_ingress_load_balancer_ingress_t *v1_ingress_load_balancer_ingress);

#endif /* _v1_ingress_load_balancer_ingress_H_ */

