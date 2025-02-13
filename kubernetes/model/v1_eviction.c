#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_eviction.h"



static v1_eviction_t *v1_eviction_create_internal(
    char *api_version,
    v1_delete_options_t *delete_options,
    char *kind,
    v1_object_meta_t *metadata
    ) {
    v1_eviction_t *v1_eviction_local_var = malloc(sizeof(v1_eviction_t));
    if (!v1_eviction_local_var) {
        return NULL;
    }
    v1_eviction_local_var->api_version = api_version;
    v1_eviction_local_var->delete_options = delete_options;
    v1_eviction_local_var->kind = kind;
    v1_eviction_local_var->metadata = metadata;

    v1_eviction_local_var->_library_owned = 1;
    return v1_eviction_local_var;
}

__attribute__((deprecated)) v1_eviction_t *v1_eviction_create(
    char *api_version,
    v1_delete_options_t *delete_options,
    char *kind,
    v1_object_meta_t *metadata
    ) {
    return v1_eviction_create_internal (
        api_version,
        delete_options,
        kind,
        metadata
        );
}

void v1_eviction_free(v1_eviction_t *v1_eviction) {
    if(NULL == v1_eviction){
        return ;
    }
    if(v1_eviction->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_eviction_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_eviction->api_version) {
        free(v1_eviction->api_version);
        v1_eviction->api_version = NULL;
    }
    if (v1_eviction->delete_options) {
        v1_delete_options_free(v1_eviction->delete_options);
        v1_eviction->delete_options = NULL;
    }
    if (v1_eviction->kind) {
        free(v1_eviction->kind);
        v1_eviction->kind = NULL;
    }
    if (v1_eviction->metadata) {
        v1_object_meta_free(v1_eviction->metadata);
        v1_eviction->metadata = NULL;
    }
    free(v1_eviction);
}

cJSON *v1_eviction_convertToJSON(v1_eviction_t *v1_eviction) {
    cJSON *item = cJSON_CreateObject();

    // v1_eviction->api_version
    if(v1_eviction->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_eviction->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_eviction->delete_options
    if(v1_eviction->delete_options) {
    cJSON *delete_options_local_JSON = v1_delete_options_convertToJSON(v1_eviction->delete_options);
    if(delete_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deleteOptions", delete_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_eviction->kind
    if(v1_eviction->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_eviction->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_eviction->metadata
    if(v1_eviction->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_eviction->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
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

v1_eviction_t *v1_eviction_parseFromJSON(cJSON *v1_evictionJSON){

    v1_eviction_t *v1_eviction_local_var = NULL;

    // define the local variable for v1_eviction->delete_options
    v1_delete_options_t *delete_options_local_nonprim = NULL;

    // define the local variable for v1_eviction->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // v1_eviction->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_evictionJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_eviction->delete_options
    cJSON *delete_options = cJSON_GetObjectItemCaseSensitive(v1_evictionJSON, "deleteOptions");
    if (cJSON_IsNull(delete_options)) {
        delete_options = NULL;
    }
    if (delete_options) { 
    delete_options_local_nonprim = v1_delete_options_parseFromJSON(delete_options); //nonprimitive
    }

    // v1_eviction->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_evictionJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_eviction->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_evictionJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1_eviction_local_var = v1_eviction_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        delete_options ? delete_options_local_nonprim : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1_eviction_local_var;
end:
    if (delete_options_local_nonprim) {
        v1_delete_options_free(delete_options_local_nonprim);
        delete_options_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
