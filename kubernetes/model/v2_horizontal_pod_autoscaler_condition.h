/*
 * v2_horizontal_pod_autoscaler_condition.h
 *
 * HorizontalPodAutoscalerCondition describes the state of a HorizontalPodAutoscaler at a certain point.
 */

#ifndef _v2_horizontal_pod_autoscaler_condition_H_
#define _v2_horizontal_pod_autoscaler_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_horizontal_pod_autoscaler_condition_t v2_horizontal_pod_autoscaler_condition_t;




typedef struct v2_horizontal_pod_autoscaler_condition_t {
    char *last_transition_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v2_horizontal_pod_autoscaler_condition_t;

__attribute__((deprecated)) v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v2_horizontal_pod_autoscaler_condition_free(v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition);

v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition_parseFromJSON(cJSON *v2_horizontal_pod_autoscaler_conditionJSON);

cJSON *v2_horizontal_pod_autoscaler_condition_convertToJSON(v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition);

#endif /* _v2_horizontal_pod_autoscaler_condition_H_ */

