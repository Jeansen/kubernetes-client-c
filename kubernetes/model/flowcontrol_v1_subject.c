#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "flowcontrol_v1_subject.h"



static flowcontrol_v1_subject_t *flowcontrol_v1_subject_create_internal(
    v1_group_subject_t *group,
    char *kind,
    v1_service_account_subject_t *service_account,
    v1_user_subject_t *user
    ) {
    flowcontrol_v1_subject_t *flowcontrol_v1_subject_local_var = malloc(sizeof(flowcontrol_v1_subject_t));
    if (!flowcontrol_v1_subject_local_var) {
        return NULL;
    }
    flowcontrol_v1_subject_local_var->group = group;
    flowcontrol_v1_subject_local_var->kind = kind;
    flowcontrol_v1_subject_local_var->service_account = service_account;
    flowcontrol_v1_subject_local_var->user = user;

    flowcontrol_v1_subject_local_var->_library_owned = 1;
    return flowcontrol_v1_subject_local_var;
}

__attribute__((deprecated)) flowcontrol_v1_subject_t *flowcontrol_v1_subject_create(
    v1_group_subject_t *group,
    char *kind,
    v1_service_account_subject_t *service_account,
    v1_user_subject_t *user
    ) {
    return flowcontrol_v1_subject_create_internal (
        group,
        kind,
        service_account,
        user
        );
}

void flowcontrol_v1_subject_free(flowcontrol_v1_subject_t *flowcontrol_v1_subject) {
    if(NULL == flowcontrol_v1_subject){
        return ;
    }
    if(flowcontrol_v1_subject->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "flowcontrol_v1_subject_free");
        return ;
    }
    listEntry_t *listEntry;
    if (flowcontrol_v1_subject->group) {
        v1_group_subject_free(flowcontrol_v1_subject->group);
        flowcontrol_v1_subject->group = NULL;
    }
    if (flowcontrol_v1_subject->kind) {
        free(flowcontrol_v1_subject->kind);
        flowcontrol_v1_subject->kind = NULL;
    }
    if (flowcontrol_v1_subject->service_account) {
        v1_service_account_subject_free(flowcontrol_v1_subject->service_account);
        flowcontrol_v1_subject->service_account = NULL;
    }
    if (flowcontrol_v1_subject->user) {
        v1_user_subject_free(flowcontrol_v1_subject->user);
        flowcontrol_v1_subject->user = NULL;
    }
    free(flowcontrol_v1_subject);
}

cJSON *flowcontrol_v1_subject_convertToJSON(flowcontrol_v1_subject_t *flowcontrol_v1_subject) {
    cJSON *item = cJSON_CreateObject();

    // flowcontrol_v1_subject->group
    if(flowcontrol_v1_subject->group) {
    cJSON *group_local_JSON = v1_group_subject_convertToJSON(flowcontrol_v1_subject->group);
    if(group_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "group", group_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // flowcontrol_v1_subject->kind
    if (!flowcontrol_v1_subject->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", flowcontrol_v1_subject->kind) == NULL) {
    goto fail; //String
    }


    // flowcontrol_v1_subject->service_account
    if(flowcontrol_v1_subject->service_account) {
    cJSON *service_account_local_JSON = v1_service_account_subject_convertToJSON(flowcontrol_v1_subject->service_account);
    if(service_account_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "serviceAccount", service_account_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // flowcontrol_v1_subject->user
    if(flowcontrol_v1_subject->user) {
    cJSON *user_local_JSON = v1_user_subject_convertToJSON(flowcontrol_v1_subject->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
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

flowcontrol_v1_subject_t *flowcontrol_v1_subject_parseFromJSON(cJSON *flowcontrol_v1_subjectJSON){

    flowcontrol_v1_subject_t *flowcontrol_v1_subject_local_var = NULL;

    // define the local variable for flowcontrol_v1_subject->group
    v1_group_subject_t *group_local_nonprim = NULL;

    // define the local variable for flowcontrol_v1_subject->service_account
    v1_service_account_subject_t *service_account_local_nonprim = NULL;

    // define the local variable for flowcontrol_v1_subject->user
    v1_user_subject_t *user_local_nonprim = NULL;

    // flowcontrol_v1_subject->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(flowcontrol_v1_subjectJSON, "group");
    if (cJSON_IsNull(group)) {
        group = NULL;
    }
    if (group) { 
    group_local_nonprim = v1_group_subject_parseFromJSON(group); //nonprimitive
    }

    // flowcontrol_v1_subject->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(flowcontrol_v1_subjectJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // flowcontrol_v1_subject->service_account
    cJSON *service_account = cJSON_GetObjectItemCaseSensitive(flowcontrol_v1_subjectJSON, "serviceAccount");
    if (cJSON_IsNull(service_account)) {
        service_account = NULL;
    }
    if (service_account) { 
    service_account_local_nonprim = v1_service_account_subject_parseFromJSON(service_account); //nonprimitive
    }

    // flowcontrol_v1_subject->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(flowcontrol_v1_subjectJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    user_local_nonprim = v1_user_subject_parseFromJSON(user); //nonprimitive
    }


    flowcontrol_v1_subject_local_var = flowcontrol_v1_subject_create_internal (
        group ? group_local_nonprim : NULL,
        strdup(kind->valuestring),
        service_account ? service_account_local_nonprim : NULL,
        user ? user_local_nonprim : NULL
        );

    return flowcontrol_v1_subject_local_var;
end:
    if (group_local_nonprim) {
        v1_group_subject_free(group_local_nonprim);
        group_local_nonprim = NULL;
    }
    if (service_account_local_nonprim) {
        v1_service_account_subject_free(service_account_local_nonprim);
        service_account_local_nonprim = NULL;
    }
    if (user_local_nonprim) {
        v1_user_subject_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
