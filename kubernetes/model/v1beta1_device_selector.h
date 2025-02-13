/*
 * v1beta1_device_selector.h
 *
 * DeviceSelector must have exactly one field set.
 */

#ifndef _v1beta1_device_selector_H_
#define _v1beta1_device_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_device_selector_t v1beta1_device_selector_t;

#include "v1beta1_cel_device_selector.h"



typedef struct v1beta1_device_selector_t {
    struct v1beta1_cel_device_selector_t *cel; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_device_selector_t;

__attribute__((deprecated)) v1beta1_device_selector_t *v1beta1_device_selector_create(
    v1beta1_cel_device_selector_t *cel
);

void v1beta1_device_selector_free(v1beta1_device_selector_t *v1beta1_device_selector);

v1beta1_device_selector_t *v1beta1_device_selector_parseFromJSON(cJSON *v1beta1_device_selectorJSON);

cJSON *v1beta1_device_selector_convertToJSON(v1beta1_device_selector_t *v1beta1_device_selector);

#endif /* _v1beta1_device_selector_H_ */

