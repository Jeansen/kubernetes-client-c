#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_namespace.h"



static v1_namespace_t *v1_namespace_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_namespace_spec_t *spec,
    v1_namespace_status_t *status
    ) {
    v1_namespace_t *v1_namespace_local_var = malloc(sizeof(v1_namespace_t));
    if (!v1_namespace_local_var) {
        return NULL;
    }
    v1_namespace_local_var->api_version = api_version;
    v1_namespace_local_var->kind = kind;
    v1_namespace_local_var->metadata = metadata;
    v1_namespace_local_var->spec = spec;
    v1_namespace_local_var->status = status;

    v1_namespace_local_var->_library_owned = 1;
    return v1_namespace_local_var;
}

__attribute__((deprecated)) v1_namespace_t *v1_namespace_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_namespace_spec_t *spec,
    v1_namespace_status_t *status
    ) {
    return v1_namespace_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
}

void v1_namespace_free(v1_namespace_t *v1_namespace) {
    if(NULL == v1_namespace){
        return ;
    }
    if(v1_namespace->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_namespace_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_namespace->api_version) {
        free(v1_namespace->api_version);
        v1_namespace->api_version = NULL;
    }
    if (v1_namespace->kind) {
        free(v1_namespace->kind);
        v1_namespace->kind = NULL;
    }
    if (v1_namespace->metadata) {
        v1_object_meta_free(v1_namespace->metadata);
        v1_namespace->metadata = NULL;
    }
    if (v1_namespace->spec) {
        v1_namespace_spec_free(v1_namespace->spec);
        v1_namespace->spec = NULL;
    }
    if (v1_namespace->status) {
        v1_namespace_status_free(v1_namespace->status);
        v1_namespace->status = NULL;
    }
    free(v1_namespace);
}

cJSON *v1_namespace_convertToJSON(v1_namespace_t *v1_namespace) {
    cJSON *item = cJSON_CreateObject();

    // v1_namespace->api_version
    if(v1_namespace->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_namespace->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_namespace->kind
    if(v1_namespace->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_namespace->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_namespace->metadata
    if(v1_namespace->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_namespace->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_namespace->spec
    if(v1_namespace->spec) {
    cJSON *spec_local_JSON = v1_namespace_spec_convertToJSON(v1_namespace->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_namespace->status
    if(v1_namespace->status) {
    cJSON *status_local_JSON = v1_namespace_status_convertToJSON(v1_namespace->status);
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

v1_namespace_t *v1_namespace_parseFromJSON(cJSON *v1_namespaceJSON){

    v1_namespace_t *v1_namespace_local_var = NULL;

    // define the local variable for v1_namespace->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_namespace->spec
    v1_namespace_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1_namespace->status
    v1_namespace_status_t *status_local_nonprim = NULL;

    // v1_namespace->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_namespaceJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_namespace->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_namespaceJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_namespace->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_namespaceJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_namespace->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_namespaceJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (spec) { 
    spec_local_nonprim = v1_namespace_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_namespace->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_namespaceJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1_namespace_status_parseFromJSON(status); //nonprimitive
    }


    v1_namespace_local_var = v1_namespace_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_namespace_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_namespace_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_namespace_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
