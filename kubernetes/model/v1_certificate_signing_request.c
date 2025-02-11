#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_certificate_signing_request.h"



static v1_certificate_signing_request_t *v1_certificate_signing_request_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_certificate_signing_request_spec_t *spec,
    v1_certificate_signing_request_status_t *status
    ) {
    v1_certificate_signing_request_t *v1_certificate_signing_request_local_var = malloc(sizeof(v1_certificate_signing_request_t));
    if (!v1_certificate_signing_request_local_var) {
        return NULL;
    }
    v1_certificate_signing_request_local_var->api_version = api_version;
    v1_certificate_signing_request_local_var->kind = kind;
    v1_certificate_signing_request_local_var->metadata = metadata;
    v1_certificate_signing_request_local_var->spec = spec;
    v1_certificate_signing_request_local_var->status = status;

    v1_certificate_signing_request_local_var->_library_owned = 1;
    return v1_certificate_signing_request_local_var;
}

__attribute__((deprecated)) v1_certificate_signing_request_t *v1_certificate_signing_request_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_certificate_signing_request_spec_t *spec,
    v1_certificate_signing_request_status_t *status
    ) {
    return v1_certificate_signing_request_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
}

void v1_certificate_signing_request_free(v1_certificate_signing_request_t *v1_certificate_signing_request) {
    if(NULL == v1_certificate_signing_request){
        return ;
    }
    if(v1_certificate_signing_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_certificate_signing_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_certificate_signing_request->api_version) {
        free(v1_certificate_signing_request->api_version);
        v1_certificate_signing_request->api_version = NULL;
    }
    if (v1_certificate_signing_request->kind) {
        free(v1_certificate_signing_request->kind);
        v1_certificate_signing_request->kind = NULL;
    }
    if (v1_certificate_signing_request->metadata) {
        v1_object_meta_free(v1_certificate_signing_request->metadata);
        v1_certificate_signing_request->metadata = NULL;
    }
    if (v1_certificate_signing_request->spec) {
        v1_certificate_signing_request_spec_free(v1_certificate_signing_request->spec);
        v1_certificate_signing_request->spec = NULL;
    }
    if (v1_certificate_signing_request->status) {
        v1_certificate_signing_request_status_free(v1_certificate_signing_request->status);
        v1_certificate_signing_request->status = NULL;
    }
    free(v1_certificate_signing_request);
}

cJSON *v1_certificate_signing_request_convertToJSON(v1_certificate_signing_request_t *v1_certificate_signing_request) {
    cJSON *item = cJSON_CreateObject();

    // v1_certificate_signing_request->api_version
    if(v1_certificate_signing_request->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_certificate_signing_request->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_certificate_signing_request->kind
    if(v1_certificate_signing_request->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_certificate_signing_request->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_certificate_signing_request->metadata
    if(v1_certificate_signing_request->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_certificate_signing_request->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_certificate_signing_request->spec
    if (!v1_certificate_signing_request->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1_certificate_signing_request_spec_convertToJSON(v1_certificate_signing_request->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_certificate_signing_request->status
    if(v1_certificate_signing_request->status) {
    cJSON *status_local_JSON = v1_certificate_signing_request_status_convertToJSON(v1_certificate_signing_request->status);
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

v1_certificate_signing_request_t *v1_certificate_signing_request_parseFromJSON(cJSON *v1_certificate_signing_requestJSON){

    v1_certificate_signing_request_t *v1_certificate_signing_request_local_var = NULL;

    // define the local variable for v1_certificate_signing_request->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_certificate_signing_request->spec
    v1_certificate_signing_request_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1_certificate_signing_request->status
    v1_certificate_signing_request_status_t *status_local_nonprim = NULL;

    // v1_certificate_signing_request->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_requestJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_certificate_signing_request->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_requestJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_certificate_signing_request->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_requestJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_certificate_signing_request->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_requestJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1_certificate_signing_request_spec_parseFromJSON(spec); //nonprimitive

    // v1_certificate_signing_request->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_certificate_signing_requestJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1_certificate_signing_request_status_parseFromJSON(status); //nonprimitive
    }


    v1_certificate_signing_request_local_var = v1_certificate_signing_request_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return v1_certificate_signing_request_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_certificate_signing_request_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_certificate_signing_request_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
