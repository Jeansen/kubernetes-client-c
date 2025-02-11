#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_subject_rules_review_status.h"



static v1_subject_rules_review_status_t *v1_subject_rules_review_status_create_internal(
    char *evaluation_error,
    int incomplete,
    list_t *non_resource_rules,
    list_t *resource_rules
    ) {
    v1_subject_rules_review_status_t *v1_subject_rules_review_status_local_var = malloc(sizeof(v1_subject_rules_review_status_t));
    if (!v1_subject_rules_review_status_local_var) {
        return NULL;
    }
    v1_subject_rules_review_status_local_var->evaluation_error = evaluation_error;
    v1_subject_rules_review_status_local_var->incomplete = incomplete;
    v1_subject_rules_review_status_local_var->non_resource_rules = non_resource_rules;
    v1_subject_rules_review_status_local_var->resource_rules = resource_rules;

    v1_subject_rules_review_status_local_var->_library_owned = 1;
    return v1_subject_rules_review_status_local_var;
}

__attribute__((deprecated)) v1_subject_rules_review_status_t *v1_subject_rules_review_status_create(
    char *evaluation_error,
    int incomplete,
    list_t *non_resource_rules,
    list_t *resource_rules
    ) {
    return v1_subject_rules_review_status_create_internal (
        evaluation_error,
        incomplete,
        non_resource_rules,
        resource_rules
        );
}

void v1_subject_rules_review_status_free(v1_subject_rules_review_status_t *v1_subject_rules_review_status) {
    if(NULL == v1_subject_rules_review_status){
        return ;
    }
    if(v1_subject_rules_review_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_subject_rules_review_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_subject_rules_review_status->evaluation_error) {
        free(v1_subject_rules_review_status->evaluation_error);
        v1_subject_rules_review_status->evaluation_error = NULL;
    }
    if (v1_subject_rules_review_status->non_resource_rules) {
        list_ForEach(listEntry, v1_subject_rules_review_status->non_resource_rules) {
            v1_non_resource_rule_free(listEntry->data);
        }
        list_freeList(v1_subject_rules_review_status->non_resource_rules);
        v1_subject_rules_review_status->non_resource_rules = NULL;
    }
    if (v1_subject_rules_review_status->resource_rules) {
        list_ForEach(listEntry, v1_subject_rules_review_status->resource_rules) {
            v1_resource_rule_free(listEntry->data);
        }
        list_freeList(v1_subject_rules_review_status->resource_rules);
        v1_subject_rules_review_status->resource_rules = NULL;
    }
    free(v1_subject_rules_review_status);
}

cJSON *v1_subject_rules_review_status_convertToJSON(v1_subject_rules_review_status_t *v1_subject_rules_review_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_subject_rules_review_status->evaluation_error
    if(v1_subject_rules_review_status->evaluation_error) {
    if(cJSON_AddStringToObject(item, "evaluationError", v1_subject_rules_review_status->evaluation_error) == NULL) {
    goto fail; //String
    }
    }


    // v1_subject_rules_review_status->incomplete
    if (!v1_subject_rules_review_status->incomplete) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "incomplete", v1_subject_rules_review_status->incomplete) == NULL) {
    goto fail; //Bool
    }


    // v1_subject_rules_review_status->non_resource_rules
    if (!v1_subject_rules_review_status->non_resource_rules) {
        goto fail;
    }
    cJSON *non_resource_rules = cJSON_AddArrayToObject(item, "nonResourceRules");
    if(non_resource_rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *non_resource_rulesListEntry;
    if (v1_subject_rules_review_status->non_resource_rules) {
    list_ForEach(non_resource_rulesListEntry, v1_subject_rules_review_status->non_resource_rules) {
    cJSON *itemLocal = v1_non_resource_rule_convertToJSON(non_resource_rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(non_resource_rules, itemLocal);
    }
    }


    // v1_subject_rules_review_status->resource_rules
    if (!v1_subject_rules_review_status->resource_rules) {
        goto fail;
    }
    cJSON *resource_rules = cJSON_AddArrayToObject(item, "resourceRules");
    if(resource_rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resource_rulesListEntry;
    if (v1_subject_rules_review_status->resource_rules) {
    list_ForEach(resource_rulesListEntry, v1_subject_rules_review_status->resource_rules) {
    cJSON *itemLocal = v1_resource_rule_convertToJSON(resource_rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resource_rules, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_subject_rules_review_status_t *v1_subject_rules_review_status_parseFromJSON(cJSON *v1_subject_rules_review_statusJSON){

    v1_subject_rules_review_status_t *v1_subject_rules_review_status_local_var = NULL;

    // define the local list for v1_subject_rules_review_status->non_resource_rules
    list_t *non_resource_rulesList = NULL;

    // define the local list for v1_subject_rules_review_status->resource_rules
    list_t *resource_rulesList = NULL;

    // v1_subject_rules_review_status->evaluation_error
    cJSON *evaluation_error = cJSON_GetObjectItemCaseSensitive(v1_subject_rules_review_statusJSON, "evaluationError");
    if (cJSON_IsNull(evaluation_error)) {
        evaluation_error = NULL;
    }
    if (evaluation_error) { 
    if(!cJSON_IsString(evaluation_error) && !cJSON_IsNull(evaluation_error))
    {
    goto end; //String
    }
    }

    // v1_subject_rules_review_status->incomplete
    cJSON *incomplete = cJSON_GetObjectItemCaseSensitive(v1_subject_rules_review_statusJSON, "incomplete");
    if (cJSON_IsNull(incomplete)) {
        incomplete = NULL;
    }
    if (!incomplete) {
        goto end;
    }

    
    if(!cJSON_IsBool(incomplete))
    {
    goto end; //Bool
    }

    // v1_subject_rules_review_status->non_resource_rules
    cJSON *non_resource_rules = cJSON_GetObjectItemCaseSensitive(v1_subject_rules_review_statusJSON, "nonResourceRules");
    if (cJSON_IsNull(non_resource_rules)) {
        non_resource_rules = NULL;
    }
    if (!non_resource_rules) {
        goto end;
    }

    
    cJSON *non_resource_rules_local_nonprimitive = NULL;
    if(!cJSON_IsArray(non_resource_rules)){
        goto end; //nonprimitive container
    }

    non_resource_rulesList = list_createList();

    cJSON_ArrayForEach(non_resource_rules_local_nonprimitive,non_resource_rules )
    {
        if(!cJSON_IsObject(non_resource_rules_local_nonprimitive)){
            goto end;
        }
        v1_non_resource_rule_t *non_resource_rulesItem = v1_non_resource_rule_parseFromJSON(non_resource_rules_local_nonprimitive);

        list_addElement(non_resource_rulesList, non_resource_rulesItem);
    }

    // v1_subject_rules_review_status->resource_rules
    cJSON *resource_rules = cJSON_GetObjectItemCaseSensitive(v1_subject_rules_review_statusJSON, "resourceRules");
    if (cJSON_IsNull(resource_rules)) {
        resource_rules = NULL;
    }
    if (!resource_rules) {
        goto end;
    }

    
    cJSON *resource_rules_local_nonprimitive = NULL;
    if(!cJSON_IsArray(resource_rules)){
        goto end; //nonprimitive container
    }

    resource_rulesList = list_createList();

    cJSON_ArrayForEach(resource_rules_local_nonprimitive,resource_rules )
    {
        if(!cJSON_IsObject(resource_rules_local_nonprimitive)){
            goto end;
        }
        v1_resource_rule_t *resource_rulesItem = v1_resource_rule_parseFromJSON(resource_rules_local_nonprimitive);

        list_addElement(resource_rulesList, resource_rulesItem);
    }


    v1_subject_rules_review_status_local_var = v1_subject_rules_review_status_create_internal (
        evaluation_error && !cJSON_IsNull(evaluation_error) ? strdup(evaluation_error->valuestring) : NULL,
        incomplete->valueint,
        non_resource_rulesList,
        resource_rulesList
        );

    return v1_subject_rules_review_status_local_var;
end:
    if (non_resource_rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, non_resource_rulesList) {
            v1_non_resource_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(non_resource_rulesList);
        non_resource_rulesList = NULL;
    }
    if (resource_rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resource_rulesList) {
            v1_resource_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resource_rulesList);
        resource_rulesList = NULL;
    }
    return NULL;

}
