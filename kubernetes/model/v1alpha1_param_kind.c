#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_param_kind.h"



static v1alpha1_param_kind_t *v1alpha1_param_kind_create_internal(
    char *api_version,
    char *kind
    ) {
    v1alpha1_param_kind_t *v1alpha1_param_kind_local_var = malloc(sizeof(v1alpha1_param_kind_t));
    if (!v1alpha1_param_kind_local_var) {
        return NULL;
    }
    v1alpha1_param_kind_local_var->api_version = api_version;
    v1alpha1_param_kind_local_var->kind = kind;

    v1alpha1_param_kind_local_var->_library_owned = 1;
    return v1alpha1_param_kind_local_var;
}

__attribute__((deprecated)) v1alpha1_param_kind_t *v1alpha1_param_kind_create(
    char *api_version,
    char *kind
    ) {
    return v1alpha1_param_kind_create_internal (
        api_version,
        kind
        );
}

void v1alpha1_param_kind_free(v1alpha1_param_kind_t *v1alpha1_param_kind) {
    if(NULL == v1alpha1_param_kind){
        return ;
    }
    if(v1alpha1_param_kind->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_param_kind_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_param_kind->api_version) {
        free(v1alpha1_param_kind->api_version);
        v1alpha1_param_kind->api_version = NULL;
    }
    if (v1alpha1_param_kind->kind) {
        free(v1alpha1_param_kind->kind);
        v1alpha1_param_kind->kind = NULL;
    }
    free(v1alpha1_param_kind);
}

cJSON *v1alpha1_param_kind_convertToJSON(v1alpha1_param_kind_t *v1alpha1_param_kind) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_param_kind->api_version
    if(v1alpha1_param_kind->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_param_kind->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_param_kind->kind
    if(v1alpha1_param_kind->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_param_kind->kind) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_param_kind_t *v1alpha1_param_kind_parseFromJSON(cJSON *v1alpha1_param_kindJSON){

    v1alpha1_param_kind_t *v1alpha1_param_kind_local_var = NULL;

    // v1alpha1_param_kind->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_param_kindJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_param_kind->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_param_kindJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }


    v1alpha1_param_kind_local_var = v1alpha1_param_kind_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL
        );

    return v1alpha1_param_kind_local_var;
end:
    return NULL;

}
