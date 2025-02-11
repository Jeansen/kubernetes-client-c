#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_policy_rules_with_subjects.h"



static v1_policy_rules_with_subjects_t *v1_policy_rules_with_subjects_create_internal(
    list_t *non_resource_rules,
    list_t *resource_rules,
    list_t *subjects
    ) {
    v1_policy_rules_with_subjects_t *v1_policy_rules_with_subjects_local_var = malloc(sizeof(v1_policy_rules_with_subjects_t));
    if (!v1_policy_rules_with_subjects_local_var) {
        return NULL;
    }
    v1_policy_rules_with_subjects_local_var->non_resource_rules = non_resource_rules;
    v1_policy_rules_with_subjects_local_var->resource_rules = resource_rules;
    v1_policy_rules_with_subjects_local_var->subjects = subjects;

    v1_policy_rules_with_subjects_local_var->_library_owned = 1;
    return v1_policy_rules_with_subjects_local_var;
}

__attribute__((deprecated)) v1_policy_rules_with_subjects_t *v1_policy_rules_with_subjects_create(
    list_t *non_resource_rules,
    list_t *resource_rules,
    list_t *subjects
    ) {
    return v1_policy_rules_with_subjects_create_internal (
        non_resource_rules,
        resource_rules,
        subjects
        );
}

void v1_policy_rules_with_subjects_free(v1_policy_rules_with_subjects_t *v1_policy_rules_with_subjects) {
    if(NULL == v1_policy_rules_with_subjects){
        return ;
    }
    if(v1_policy_rules_with_subjects->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_policy_rules_with_subjects_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_policy_rules_with_subjects->non_resource_rules) {
        list_ForEach(listEntry, v1_policy_rules_with_subjects->non_resource_rules) {
            v1_non_resource_policy_rule_free(listEntry->data);
        }
        list_freeList(v1_policy_rules_with_subjects->non_resource_rules);
        v1_policy_rules_with_subjects->non_resource_rules = NULL;
    }
    if (v1_policy_rules_with_subjects->resource_rules) {
        list_ForEach(listEntry, v1_policy_rules_with_subjects->resource_rules) {
            v1_resource_policy_rule_free(listEntry->data);
        }
        list_freeList(v1_policy_rules_with_subjects->resource_rules);
        v1_policy_rules_with_subjects->resource_rules = NULL;
    }
    if (v1_policy_rules_with_subjects->subjects) {
        list_ForEach(listEntry, v1_policy_rules_with_subjects->subjects) {
            flowcontrol_v1_subject_free(listEntry->data);
        }
        list_freeList(v1_policy_rules_with_subjects->subjects);
        v1_policy_rules_with_subjects->subjects = NULL;
    }
    free(v1_policy_rules_with_subjects);
}

cJSON *v1_policy_rules_with_subjects_convertToJSON(v1_policy_rules_with_subjects_t *v1_policy_rules_with_subjects) {
    cJSON *item = cJSON_CreateObject();

    // v1_policy_rules_with_subjects->non_resource_rules
    if(v1_policy_rules_with_subjects->non_resource_rules) {
    cJSON *non_resource_rules = cJSON_AddArrayToObject(item, "nonResourceRules");
    if(non_resource_rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *non_resource_rulesListEntry;
    if (v1_policy_rules_with_subjects->non_resource_rules) {
    list_ForEach(non_resource_rulesListEntry, v1_policy_rules_with_subjects->non_resource_rules) {
    cJSON *itemLocal = v1_non_resource_policy_rule_convertToJSON(non_resource_rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(non_resource_rules, itemLocal);
    }
    }
    }


    // v1_policy_rules_with_subjects->resource_rules
    if(v1_policy_rules_with_subjects->resource_rules) {
    cJSON *resource_rules = cJSON_AddArrayToObject(item, "resourceRules");
    if(resource_rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resource_rulesListEntry;
    if (v1_policy_rules_with_subjects->resource_rules) {
    list_ForEach(resource_rulesListEntry, v1_policy_rules_with_subjects->resource_rules) {
    cJSON *itemLocal = v1_resource_policy_rule_convertToJSON(resource_rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resource_rules, itemLocal);
    }
    }
    }


    // v1_policy_rules_with_subjects->subjects
    if (!v1_policy_rules_with_subjects->subjects) {
        goto fail;
    }
    cJSON *subjects = cJSON_AddArrayToObject(item, "subjects");
    if(subjects == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *subjectsListEntry;
    if (v1_policy_rules_with_subjects->subjects) {
    list_ForEach(subjectsListEntry, v1_policy_rules_with_subjects->subjects) {
    cJSON *itemLocal = flowcontrol_v1_subject_convertToJSON(subjectsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(subjects, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_policy_rules_with_subjects_t *v1_policy_rules_with_subjects_parseFromJSON(cJSON *v1_policy_rules_with_subjectsJSON){

    v1_policy_rules_with_subjects_t *v1_policy_rules_with_subjects_local_var = NULL;

    // define the local list for v1_policy_rules_with_subjects->non_resource_rules
    list_t *non_resource_rulesList = NULL;

    // define the local list for v1_policy_rules_with_subjects->resource_rules
    list_t *resource_rulesList = NULL;

    // define the local list for v1_policy_rules_with_subjects->subjects
    list_t *subjectsList = NULL;

    // v1_policy_rules_with_subjects->non_resource_rules
    cJSON *non_resource_rules = cJSON_GetObjectItemCaseSensitive(v1_policy_rules_with_subjectsJSON, "nonResourceRules");
    if (cJSON_IsNull(non_resource_rules)) {
        non_resource_rules = NULL;
    }
    if (non_resource_rules) { 
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
        v1_non_resource_policy_rule_t *non_resource_rulesItem = v1_non_resource_policy_rule_parseFromJSON(non_resource_rules_local_nonprimitive);

        list_addElement(non_resource_rulesList, non_resource_rulesItem);
    }
    }

    // v1_policy_rules_with_subjects->resource_rules
    cJSON *resource_rules = cJSON_GetObjectItemCaseSensitive(v1_policy_rules_with_subjectsJSON, "resourceRules");
    if (cJSON_IsNull(resource_rules)) {
        resource_rules = NULL;
    }
    if (resource_rules) { 
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
        v1_resource_policy_rule_t *resource_rulesItem = v1_resource_policy_rule_parseFromJSON(resource_rules_local_nonprimitive);

        list_addElement(resource_rulesList, resource_rulesItem);
    }
    }

    // v1_policy_rules_with_subjects->subjects
    cJSON *subjects = cJSON_GetObjectItemCaseSensitive(v1_policy_rules_with_subjectsJSON, "subjects");
    if (cJSON_IsNull(subjects)) {
        subjects = NULL;
    }
    if (!subjects) {
        goto end;
    }

    
    cJSON *subjects_local_nonprimitive = NULL;
    if(!cJSON_IsArray(subjects)){
        goto end; //nonprimitive container
    }

    subjectsList = list_createList();

    cJSON_ArrayForEach(subjects_local_nonprimitive,subjects )
    {
        if(!cJSON_IsObject(subjects_local_nonprimitive)){
            goto end;
        }
        flowcontrol_v1_subject_t *subjectsItem = flowcontrol_v1_subject_parseFromJSON(subjects_local_nonprimitive);

        list_addElement(subjectsList, subjectsItem);
    }


    v1_policy_rules_with_subjects_local_var = v1_policy_rules_with_subjects_create_internal (
        non_resource_rules ? non_resource_rulesList : NULL,
        resource_rules ? resource_rulesList : NULL,
        subjectsList
        );

    return v1_policy_rules_with_subjects_local_var;
end:
    if (non_resource_rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, non_resource_rulesList) {
            v1_non_resource_policy_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(non_resource_rulesList);
        non_resource_rulesList = NULL;
    }
    if (resource_rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resource_rulesList) {
            v1_resource_policy_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resource_rulesList);
        resource_rulesList = NULL;
    }
    if (subjectsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, subjectsList) {
            flowcontrol_v1_subject_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(subjectsList);
        subjectsList = NULL;
    }
    return NULL;

}
