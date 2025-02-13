#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_external_documentation.h"



static v1_external_documentation_t *v1_external_documentation_create_internal(
    char *description,
    char *url
    ) {
    v1_external_documentation_t *v1_external_documentation_local_var = malloc(sizeof(v1_external_documentation_t));
    if (!v1_external_documentation_local_var) {
        return NULL;
    }
    v1_external_documentation_local_var->description = description;
    v1_external_documentation_local_var->url = url;

    v1_external_documentation_local_var->_library_owned = 1;
    return v1_external_documentation_local_var;
}

__attribute__((deprecated)) v1_external_documentation_t *v1_external_documentation_create(
    char *description,
    char *url
    ) {
    return v1_external_documentation_create_internal (
        description,
        url
        );
}

void v1_external_documentation_free(v1_external_documentation_t *v1_external_documentation) {
    if(NULL == v1_external_documentation){
        return ;
    }
    if(v1_external_documentation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_external_documentation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_external_documentation->description) {
        free(v1_external_documentation->description);
        v1_external_documentation->description = NULL;
    }
    if (v1_external_documentation->url) {
        free(v1_external_documentation->url);
        v1_external_documentation->url = NULL;
    }
    free(v1_external_documentation);
}

cJSON *v1_external_documentation_convertToJSON(v1_external_documentation_t *v1_external_documentation) {
    cJSON *item = cJSON_CreateObject();

    // v1_external_documentation->description
    if(v1_external_documentation->description) {
    if(cJSON_AddStringToObject(item, "description", v1_external_documentation->description) == NULL) {
    goto fail; //String
    }
    }


    // v1_external_documentation->url
    if(v1_external_documentation->url) {
    if(cJSON_AddStringToObject(item, "url", v1_external_documentation->url) == NULL) {
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

v1_external_documentation_t *v1_external_documentation_parseFromJSON(cJSON *v1_external_documentationJSON){

    v1_external_documentation_t *v1_external_documentation_local_var = NULL;

    // v1_external_documentation->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(v1_external_documentationJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // v1_external_documentation->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(v1_external_documentationJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }


    v1_external_documentation_local_var = v1_external_documentation_create_internal (
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL
        );

    return v1_external_documentation_local_var;
end:
    return NULL;

}
