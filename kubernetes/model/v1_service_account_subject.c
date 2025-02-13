#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_account_subject.h"



static v1_service_account_subject_t *v1_service_account_subject_create_internal(
    char *name,
    char *_namespace
    ) {
    v1_service_account_subject_t *v1_service_account_subject_local_var = malloc(sizeof(v1_service_account_subject_t));
    if (!v1_service_account_subject_local_var) {
        return NULL;
    }
    v1_service_account_subject_local_var->name = name;
    v1_service_account_subject_local_var->_namespace = _namespace;

    v1_service_account_subject_local_var->_library_owned = 1;
    return v1_service_account_subject_local_var;
}

__attribute__((deprecated)) v1_service_account_subject_t *v1_service_account_subject_create(
    char *name,
    char *_namespace
    ) {
    return v1_service_account_subject_create_internal (
        name,
        _namespace
        );
}

void v1_service_account_subject_free(v1_service_account_subject_t *v1_service_account_subject) {
    if(NULL == v1_service_account_subject){
        return ;
    }
    if(v1_service_account_subject->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_service_account_subject_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_account_subject->name) {
        free(v1_service_account_subject->name);
        v1_service_account_subject->name = NULL;
    }
    if (v1_service_account_subject->_namespace) {
        free(v1_service_account_subject->_namespace);
        v1_service_account_subject->_namespace = NULL;
    }
    free(v1_service_account_subject);
}

cJSON *v1_service_account_subject_convertToJSON(v1_service_account_subject_t *v1_service_account_subject) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_account_subject->name
    if (!v1_service_account_subject->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_service_account_subject->name) == NULL) {
    goto fail; //String
    }


    // v1_service_account_subject->_namespace
    if (!v1_service_account_subject->_namespace) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "namespace", v1_service_account_subject->_namespace) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_service_account_subject_t *v1_service_account_subject_parseFromJSON(cJSON *v1_service_account_subjectJSON){

    v1_service_account_subject_t *v1_service_account_subject_local_var = NULL;

    // v1_service_account_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_service_account_subjectJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_service_account_subject->_namespace
    cJSON *_namespace = cJSON_GetObjectItemCaseSensitive(v1_service_account_subjectJSON, "namespace");
    if (cJSON_IsNull(_namespace)) {
        _namespace = NULL;
    }
    if (!_namespace) {
        goto end;
    }

    
    if(!cJSON_IsString(_namespace))
    {
    goto end; //String
    }


    v1_service_account_subject_local_var = v1_service_account_subject_create_internal (
        strdup(name->valuestring),
        strdup(_namespace->valuestring)
        );

    return v1_service_account_subject_local_var;
end:
    return NULL;

}
