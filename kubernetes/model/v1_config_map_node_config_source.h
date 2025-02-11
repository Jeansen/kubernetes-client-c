/*
 * v1_config_map_node_config_source.h
 *
 * ConfigMapNodeConfigSource contains the information to reference a ConfigMap as a config source for the Node. This API is deprecated since 1.22: https://git.k8s.io/enhancements/keps/sig-node/281-dynamic-kubelet-configuration
 */

#ifndef _v1_config_map_node_config_source_H_
#define _v1_config_map_node_config_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_config_map_node_config_source_t v1_config_map_node_config_source_t;




typedef struct v1_config_map_node_config_source_t {
    char *kubelet_config_key; // string
    char *name; // string
    char *_namespace; // string
    char *resource_version; // string
    char *uid; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_config_map_node_config_source_t;

__attribute__((deprecated)) v1_config_map_node_config_source_t *v1_config_map_node_config_source_create(
    char *kubelet_config_key,
    char *name,
    char *_namespace,
    char *resource_version,
    char *uid
);

void v1_config_map_node_config_source_free(v1_config_map_node_config_source_t *v1_config_map_node_config_source);

v1_config_map_node_config_source_t *v1_config_map_node_config_source_parseFromJSON(cJSON *v1_config_map_node_config_sourceJSON);

cJSON *v1_config_map_node_config_source_convertToJSON(v1_config_map_node_config_source_t *v1_config_map_node_config_source);

#endif /* _v1_config_map_node_config_source_H_ */

