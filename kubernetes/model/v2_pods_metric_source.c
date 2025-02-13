#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_pods_metric_source.h"



static v2_pods_metric_source_t *v2_pods_metric_source_create_internal(
    v2_metric_identifier_t *metric,
    v2_metric_target_t *target
    ) {
    v2_pods_metric_source_t *v2_pods_metric_source_local_var = malloc(sizeof(v2_pods_metric_source_t));
    if (!v2_pods_metric_source_local_var) {
        return NULL;
    }
    v2_pods_metric_source_local_var->metric = metric;
    v2_pods_metric_source_local_var->target = target;

    v2_pods_metric_source_local_var->_library_owned = 1;
    return v2_pods_metric_source_local_var;
}

__attribute__((deprecated)) v2_pods_metric_source_t *v2_pods_metric_source_create(
    v2_metric_identifier_t *metric,
    v2_metric_target_t *target
    ) {
    return v2_pods_metric_source_create_internal (
        metric,
        target
        );
}

void v2_pods_metric_source_free(v2_pods_metric_source_t *v2_pods_metric_source) {
    if(NULL == v2_pods_metric_source){
        return ;
    }
    if(v2_pods_metric_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_pods_metric_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_pods_metric_source->metric) {
        v2_metric_identifier_free(v2_pods_metric_source->metric);
        v2_pods_metric_source->metric = NULL;
    }
    if (v2_pods_metric_source->target) {
        v2_metric_target_free(v2_pods_metric_source->target);
        v2_pods_metric_source->target = NULL;
    }
    free(v2_pods_metric_source);
}

cJSON *v2_pods_metric_source_convertToJSON(v2_pods_metric_source_t *v2_pods_metric_source) {
    cJSON *item = cJSON_CreateObject();

    // v2_pods_metric_source->metric
    if (!v2_pods_metric_source->metric) {
        goto fail;
    }
    cJSON *metric_local_JSON = v2_metric_identifier_convertToJSON(v2_pods_metric_source->metric);
    if(metric_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metric", metric_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v2_pods_metric_source->target
    if (!v2_pods_metric_source->target) {
        goto fail;
    }
    cJSON *target_local_JSON = v2_metric_target_convertToJSON(v2_pods_metric_source->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2_pods_metric_source_t *v2_pods_metric_source_parseFromJSON(cJSON *v2_pods_metric_sourceJSON){

    v2_pods_metric_source_t *v2_pods_metric_source_local_var = NULL;

    // define the local variable for v2_pods_metric_source->metric
    v2_metric_identifier_t *metric_local_nonprim = NULL;

    // define the local variable for v2_pods_metric_source->target
    v2_metric_target_t *target_local_nonprim = NULL;

    // v2_pods_metric_source->metric
    cJSON *metric = cJSON_GetObjectItemCaseSensitive(v2_pods_metric_sourceJSON, "metric");
    if (cJSON_IsNull(metric)) {
        metric = NULL;
    }
    if (!metric) {
        goto end;
    }

    
    metric_local_nonprim = v2_metric_identifier_parseFromJSON(metric); //nonprimitive

    // v2_pods_metric_source->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v2_pods_metric_sourceJSON, "target");
    if (cJSON_IsNull(target)) {
        target = NULL;
    }
    if (!target) {
        goto end;
    }

    
    target_local_nonprim = v2_metric_target_parseFromJSON(target); //nonprimitive


    v2_pods_metric_source_local_var = v2_pods_metric_source_create_internal (
        metric_local_nonprim,
        target_local_nonprim
        );

    return v2_pods_metric_source_local_var;
end:
    if (metric_local_nonprim) {
        v2_metric_identifier_free(metric_local_nonprim);
        metric_local_nonprim = NULL;
    }
    if (target_local_nonprim) {
        v2_metric_target_free(target_local_nonprim);
        target_local_nonprim = NULL;
    }
    return NULL;

}
