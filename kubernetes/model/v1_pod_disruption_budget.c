#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_disruption_budget.h"



static v1_pod_disruption_budget_t *v1_pod_disruption_budget_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_pod_disruption_budget_spec_t *spec,
    v1_pod_disruption_budget_status_t *status
    ) {
    v1_pod_disruption_budget_t *v1_pod_disruption_budget_local_var = malloc(sizeof(v1_pod_disruption_budget_t));
    if (!v1_pod_disruption_budget_local_var) {
        return NULL;
    }
    v1_pod_disruption_budget_local_var->api_version = api_version;
    v1_pod_disruption_budget_local_var->kind = kind;
    v1_pod_disruption_budget_local_var->metadata = metadata;
    v1_pod_disruption_budget_local_var->spec = spec;
    v1_pod_disruption_budget_local_var->status = status;

    v1_pod_disruption_budget_local_var->_library_owned = 1;
    return v1_pod_disruption_budget_local_var;
}

__attribute__((deprecated)) v1_pod_disruption_budget_t *v1_pod_disruption_budget_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_pod_disruption_budget_spec_t *spec,
    v1_pod_disruption_budget_status_t *status
    ) {
    return v1_pod_disruption_budget_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
}

void v1_pod_disruption_budget_free(v1_pod_disruption_budget_t *v1_pod_disruption_budget) {
    if(NULL == v1_pod_disruption_budget){
        return ;
    }
    if(v1_pod_disruption_budget->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_disruption_budget_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_disruption_budget->api_version) {
        free(v1_pod_disruption_budget->api_version);
        v1_pod_disruption_budget->api_version = NULL;
    }
    if (v1_pod_disruption_budget->kind) {
        free(v1_pod_disruption_budget->kind);
        v1_pod_disruption_budget->kind = NULL;
    }
    if (v1_pod_disruption_budget->metadata) {
        v1_object_meta_free(v1_pod_disruption_budget->metadata);
        v1_pod_disruption_budget->metadata = NULL;
    }
    if (v1_pod_disruption_budget->spec) {
        v1_pod_disruption_budget_spec_free(v1_pod_disruption_budget->spec);
        v1_pod_disruption_budget->spec = NULL;
    }
    if (v1_pod_disruption_budget->status) {
        v1_pod_disruption_budget_status_free(v1_pod_disruption_budget->status);
        v1_pod_disruption_budget->status = NULL;
    }
    free(v1_pod_disruption_budget);
}

cJSON *v1_pod_disruption_budget_convertToJSON(v1_pod_disruption_budget_t *v1_pod_disruption_budget) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_disruption_budget->api_version
    if(v1_pod_disruption_budget->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_pod_disruption_budget->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_disruption_budget->kind
    if(v1_pod_disruption_budget->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_pod_disruption_budget->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_disruption_budget->metadata
    if(v1_pod_disruption_budget->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_pod_disruption_budget->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_pod_disruption_budget->spec
    if(v1_pod_disruption_budget->spec) {
    cJSON *spec_local_JSON = v1_pod_disruption_budget_spec_convertToJSON(v1_pod_disruption_budget->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_pod_disruption_budget->status
    if(v1_pod_disruption_budget->status) {
    cJSON *status_local_JSON = v1_pod_disruption_budget_status_convertToJSON(v1_pod_disruption_budget->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_disruption_budget_t *v1_pod_disruption_budget_parseFromJSON(cJSON *v1_pod_disruption_budgetJSON){

    v1_pod_disruption_budget_t *v1_pod_disruption_budget_local_var = NULL;

    // define the local variable for v1_pod_disruption_budget->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_pod_disruption_budget->spec
    v1_pod_disruption_budget_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1_pod_disruption_budget->status
    v1_pod_disruption_budget_status_t *status_local_nonprim = NULL;

    // v1_pod_disruption_budget->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budgetJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_pod_disruption_budget->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budgetJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_pod_disruption_budget->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budgetJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_pod_disruption_budget->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budgetJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (spec) { 
    spec_local_nonprim = v1_pod_disruption_budget_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_pod_disruption_budget->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_pod_disruption_budgetJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1_pod_disruption_budget_status_parseFromJSON(status); //nonprimitive
    }


    v1_pod_disruption_budget_local_var = v1_pod_disruption_budget_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_pod_disruption_budget_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_pod_disruption_budget_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_pod_disruption_budget_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
