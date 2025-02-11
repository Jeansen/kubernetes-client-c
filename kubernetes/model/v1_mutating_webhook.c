#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_mutating_webhook.h"



static v1_mutating_webhook_t *v1_mutating_webhook_create_internal(
    list_t *admission_review_versions,
    admissionregistration_v1_webhook_client_config_t *client_config,
    char *failure_policy,
    list_t *match_conditions,
    char *match_policy,
    char *name,
    v1_label_selector_t *namespace_selector,
    v1_label_selector_t *object_selector,
    char *reinvocation_policy,
    list_t *rules,
    char *side_effects,
    int timeout_seconds
    ) {
    v1_mutating_webhook_t *v1_mutating_webhook_local_var = malloc(sizeof(v1_mutating_webhook_t));
    if (!v1_mutating_webhook_local_var) {
        return NULL;
    }
    v1_mutating_webhook_local_var->admission_review_versions = admission_review_versions;
    v1_mutating_webhook_local_var->client_config = client_config;
    v1_mutating_webhook_local_var->failure_policy = failure_policy;
    v1_mutating_webhook_local_var->match_conditions = match_conditions;
    v1_mutating_webhook_local_var->match_policy = match_policy;
    v1_mutating_webhook_local_var->name = name;
    v1_mutating_webhook_local_var->namespace_selector = namespace_selector;
    v1_mutating_webhook_local_var->object_selector = object_selector;
    v1_mutating_webhook_local_var->reinvocation_policy = reinvocation_policy;
    v1_mutating_webhook_local_var->rules = rules;
    v1_mutating_webhook_local_var->side_effects = side_effects;
    v1_mutating_webhook_local_var->timeout_seconds = timeout_seconds;

    v1_mutating_webhook_local_var->_library_owned = 1;
    return v1_mutating_webhook_local_var;
}

__attribute__((deprecated)) v1_mutating_webhook_t *v1_mutating_webhook_create(
    list_t *admission_review_versions,
    admissionregistration_v1_webhook_client_config_t *client_config,
    char *failure_policy,
    list_t *match_conditions,
    char *match_policy,
    char *name,
    v1_label_selector_t *namespace_selector,
    v1_label_selector_t *object_selector,
    char *reinvocation_policy,
    list_t *rules,
    char *side_effects,
    int timeout_seconds
    ) {
    return v1_mutating_webhook_create_internal (
        admission_review_versions,
        client_config,
        failure_policy,
        match_conditions,
        match_policy,
        name,
        namespace_selector,
        object_selector,
        reinvocation_policy,
        rules,
        side_effects,
        timeout_seconds
        );
}

void v1_mutating_webhook_free(v1_mutating_webhook_t *v1_mutating_webhook) {
    if(NULL == v1_mutating_webhook){
        return ;
    }
    if(v1_mutating_webhook->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_mutating_webhook_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_mutating_webhook->admission_review_versions) {
        list_ForEach(listEntry, v1_mutating_webhook->admission_review_versions) {
            free(listEntry->data);
        }
        list_freeList(v1_mutating_webhook->admission_review_versions);
        v1_mutating_webhook->admission_review_versions = NULL;
    }
    if (v1_mutating_webhook->client_config) {
        admissionregistration_v1_webhook_client_config_free(v1_mutating_webhook->client_config);
        v1_mutating_webhook->client_config = NULL;
    }
    if (v1_mutating_webhook->failure_policy) {
        free(v1_mutating_webhook->failure_policy);
        v1_mutating_webhook->failure_policy = NULL;
    }
    if (v1_mutating_webhook->match_conditions) {
        list_ForEach(listEntry, v1_mutating_webhook->match_conditions) {
            v1_match_condition_free(listEntry->data);
        }
        list_freeList(v1_mutating_webhook->match_conditions);
        v1_mutating_webhook->match_conditions = NULL;
    }
    if (v1_mutating_webhook->match_policy) {
        free(v1_mutating_webhook->match_policy);
        v1_mutating_webhook->match_policy = NULL;
    }
    if (v1_mutating_webhook->name) {
        free(v1_mutating_webhook->name);
        v1_mutating_webhook->name = NULL;
    }
    if (v1_mutating_webhook->namespace_selector) {
        v1_label_selector_free(v1_mutating_webhook->namespace_selector);
        v1_mutating_webhook->namespace_selector = NULL;
    }
    if (v1_mutating_webhook->object_selector) {
        v1_label_selector_free(v1_mutating_webhook->object_selector);
        v1_mutating_webhook->object_selector = NULL;
    }
    if (v1_mutating_webhook->reinvocation_policy) {
        free(v1_mutating_webhook->reinvocation_policy);
        v1_mutating_webhook->reinvocation_policy = NULL;
    }
    if (v1_mutating_webhook->rules) {
        list_ForEach(listEntry, v1_mutating_webhook->rules) {
            v1_rule_with_operations_free(listEntry->data);
        }
        list_freeList(v1_mutating_webhook->rules);
        v1_mutating_webhook->rules = NULL;
    }
    if (v1_mutating_webhook->side_effects) {
        free(v1_mutating_webhook->side_effects);
        v1_mutating_webhook->side_effects = NULL;
    }
    free(v1_mutating_webhook);
}

cJSON *v1_mutating_webhook_convertToJSON(v1_mutating_webhook_t *v1_mutating_webhook) {
    cJSON *item = cJSON_CreateObject();

    // v1_mutating_webhook->admission_review_versions
    if (!v1_mutating_webhook->admission_review_versions) {
        goto fail;
    }
    cJSON *admission_review_versions = cJSON_AddArrayToObject(item, "admissionReviewVersions");
    if(admission_review_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *admission_review_versionsListEntry;
    list_ForEach(admission_review_versionsListEntry, v1_mutating_webhook->admission_review_versions) {
    if(cJSON_AddStringToObject(admission_review_versions, "", admission_review_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_mutating_webhook->client_config
    if (!v1_mutating_webhook->client_config) {
        goto fail;
    }
    cJSON *client_config_local_JSON = admissionregistration_v1_webhook_client_config_convertToJSON(v1_mutating_webhook->client_config);
    if(client_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clientConfig", client_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_mutating_webhook->failure_policy
    if(v1_mutating_webhook->failure_policy) {
    if(cJSON_AddStringToObject(item, "failurePolicy", v1_mutating_webhook->failure_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_mutating_webhook->match_conditions
    if(v1_mutating_webhook->match_conditions) {
    cJSON *match_conditions = cJSON_AddArrayToObject(item, "matchConditions");
    if(match_conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_conditionsListEntry;
    if (v1_mutating_webhook->match_conditions) {
    list_ForEach(match_conditionsListEntry, v1_mutating_webhook->match_conditions) {
    cJSON *itemLocal = v1_match_condition_convertToJSON(match_conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(match_conditions, itemLocal);
    }
    }
    }


    // v1_mutating_webhook->match_policy
    if(v1_mutating_webhook->match_policy) {
    if(cJSON_AddStringToObject(item, "matchPolicy", v1_mutating_webhook->match_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_mutating_webhook->name
    if (!v1_mutating_webhook->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_mutating_webhook->name) == NULL) {
    goto fail; //String
    }


    // v1_mutating_webhook->namespace_selector
    if(v1_mutating_webhook->namespace_selector) {
    cJSON *namespace_selector_local_JSON = v1_label_selector_convertToJSON(v1_mutating_webhook->namespace_selector);
    if(namespace_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "namespaceSelector", namespace_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_mutating_webhook->object_selector
    if(v1_mutating_webhook->object_selector) {
    cJSON *object_selector_local_JSON = v1_label_selector_convertToJSON(v1_mutating_webhook->object_selector);
    if(object_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "objectSelector", object_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_mutating_webhook->reinvocation_policy
    if(v1_mutating_webhook->reinvocation_policy) {
    if(cJSON_AddStringToObject(item, "reinvocationPolicy", v1_mutating_webhook->reinvocation_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_mutating_webhook->rules
    if(v1_mutating_webhook->rules) {
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1_mutating_webhook->rules) {
    list_ForEach(rulesListEntry, v1_mutating_webhook->rules) {
    cJSON *itemLocal = v1_rule_with_operations_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
    }
    }
    }


    // v1_mutating_webhook->side_effects
    if (!v1_mutating_webhook->side_effects) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sideEffects", v1_mutating_webhook->side_effects) == NULL) {
    goto fail; //String
    }


    // v1_mutating_webhook->timeout_seconds
    if(v1_mutating_webhook->timeout_seconds) {
    if(cJSON_AddNumberToObject(item, "timeoutSeconds", v1_mutating_webhook->timeout_seconds) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_mutating_webhook_t *v1_mutating_webhook_parseFromJSON(cJSON *v1_mutating_webhookJSON){

    v1_mutating_webhook_t *v1_mutating_webhook_local_var = NULL;

    // define the local list for v1_mutating_webhook->admission_review_versions
    list_t *admission_review_versionsList = NULL;

    // define the local variable for v1_mutating_webhook->client_config
    admissionregistration_v1_webhook_client_config_t *client_config_local_nonprim = NULL;

    // define the local list for v1_mutating_webhook->match_conditions
    list_t *match_conditionsList = NULL;

    // define the local variable for v1_mutating_webhook->namespace_selector
    v1_label_selector_t *namespace_selector_local_nonprim = NULL;

    // define the local variable for v1_mutating_webhook->object_selector
    v1_label_selector_t *object_selector_local_nonprim = NULL;

    // define the local list for v1_mutating_webhook->rules
    list_t *rulesList = NULL;

    // v1_mutating_webhook->admission_review_versions
    cJSON *admission_review_versions = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "admissionReviewVersions");
    if (cJSON_IsNull(admission_review_versions)) {
        admission_review_versions = NULL;
    }
    if (!admission_review_versions) {
        goto end;
    }

    
    cJSON *admission_review_versions_local = NULL;
    if(!cJSON_IsArray(admission_review_versions)) {
        goto end;//primitive container
    }
    admission_review_versionsList = list_createList();

    cJSON_ArrayForEach(admission_review_versions_local, admission_review_versions)
    {
        if(!cJSON_IsString(admission_review_versions_local))
        {
            goto end;
        }
        list_addElement(admission_review_versionsList , strdup(admission_review_versions_local->valuestring));
    }

    // v1_mutating_webhook->client_config
    cJSON *client_config = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "clientConfig");
    if (cJSON_IsNull(client_config)) {
        client_config = NULL;
    }
    if (!client_config) {
        goto end;
    }

    
    client_config_local_nonprim = admissionregistration_v1_webhook_client_config_parseFromJSON(client_config); //nonprimitive

    // v1_mutating_webhook->failure_policy
    cJSON *failure_policy = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "failurePolicy");
    if (cJSON_IsNull(failure_policy)) {
        failure_policy = NULL;
    }
    if (failure_policy) { 
    if(!cJSON_IsString(failure_policy) && !cJSON_IsNull(failure_policy))
    {
    goto end; //String
    }
    }

    // v1_mutating_webhook->match_conditions
    cJSON *match_conditions = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "matchConditions");
    if (cJSON_IsNull(match_conditions)) {
        match_conditions = NULL;
    }
    if (match_conditions) { 
    cJSON *match_conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(match_conditions)){
        goto end; //nonprimitive container
    }

    match_conditionsList = list_createList();

    cJSON_ArrayForEach(match_conditions_local_nonprimitive,match_conditions )
    {
        if(!cJSON_IsObject(match_conditions_local_nonprimitive)){
            goto end;
        }
        v1_match_condition_t *match_conditionsItem = v1_match_condition_parseFromJSON(match_conditions_local_nonprimitive);

        list_addElement(match_conditionsList, match_conditionsItem);
    }
    }

    // v1_mutating_webhook->match_policy
    cJSON *match_policy = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "matchPolicy");
    if (cJSON_IsNull(match_policy)) {
        match_policy = NULL;
    }
    if (match_policy) { 
    if(!cJSON_IsString(match_policy) && !cJSON_IsNull(match_policy))
    {
    goto end; //String
    }
    }

    // v1_mutating_webhook->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "name");
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

    // v1_mutating_webhook->namespace_selector
    cJSON *namespace_selector = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "namespaceSelector");
    if (cJSON_IsNull(namespace_selector)) {
        namespace_selector = NULL;
    }
    if (namespace_selector) { 
    namespace_selector_local_nonprim = v1_label_selector_parseFromJSON(namespace_selector); //nonprimitive
    }

    // v1_mutating_webhook->object_selector
    cJSON *object_selector = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "objectSelector");
    if (cJSON_IsNull(object_selector)) {
        object_selector = NULL;
    }
    if (object_selector) { 
    object_selector_local_nonprim = v1_label_selector_parseFromJSON(object_selector); //nonprimitive
    }

    // v1_mutating_webhook->reinvocation_policy
    cJSON *reinvocation_policy = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "reinvocationPolicy");
    if (cJSON_IsNull(reinvocation_policy)) {
        reinvocation_policy = NULL;
    }
    if (reinvocation_policy) { 
    if(!cJSON_IsString(reinvocation_policy) && !cJSON_IsNull(reinvocation_policy))
    {
    goto end; //String
    }
    }

    // v1_mutating_webhook->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "rules");
    if (cJSON_IsNull(rules)) {
        rules = NULL;
    }
    if (rules) { 
    cJSON *rules_local_nonprimitive = NULL;
    if(!cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_createList();

    cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        v1_rule_with_operations_t *rulesItem = v1_rule_with_operations_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }

    // v1_mutating_webhook->side_effects
    cJSON *side_effects = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "sideEffects");
    if (cJSON_IsNull(side_effects)) {
        side_effects = NULL;
    }
    if (!side_effects) {
        goto end;
    }

    
    if(!cJSON_IsString(side_effects))
    {
    goto end; //String
    }

    // v1_mutating_webhook->timeout_seconds
    cJSON *timeout_seconds = cJSON_GetObjectItemCaseSensitive(v1_mutating_webhookJSON, "timeoutSeconds");
    if (cJSON_IsNull(timeout_seconds)) {
        timeout_seconds = NULL;
    }
    if (timeout_seconds) { 
    if(!cJSON_IsNumber(timeout_seconds))
    {
    goto end; //Numeric
    }
    }


    v1_mutating_webhook_local_var = v1_mutating_webhook_create_internal (
        admission_review_versionsList,
        client_config_local_nonprim,
        failure_policy && !cJSON_IsNull(failure_policy) ? strdup(failure_policy->valuestring) : NULL,
        match_conditions ? match_conditionsList : NULL,
        match_policy && !cJSON_IsNull(match_policy) ? strdup(match_policy->valuestring) : NULL,
        strdup(name->valuestring),
        namespace_selector ? namespace_selector_local_nonprim : NULL,
        object_selector ? object_selector_local_nonprim : NULL,
        reinvocation_policy && !cJSON_IsNull(reinvocation_policy) ? strdup(reinvocation_policy->valuestring) : NULL,
        rules ? rulesList : NULL,
        strdup(side_effects->valuestring),
        timeout_seconds ? timeout_seconds->valuedouble : 0
        );

    return v1_mutating_webhook_local_var;
end:
    if (admission_review_versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, admission_review_versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(admission_review_versionsList);
        admission_review_versionsList = NULL;
    }
    if (client_config_local_nonprim) {
        admissionregistration_v1_webhook_client_config_free(client_config_local_nonprim);
        client_config_local_nonprim = NULL;
    }
    if (match_conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_conditionsList) {
            v1_match_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_conditionsList);
        match_conditionsList = NULL;
    }
    if (namespace_selector_local_nonprim) {
        v1_label_selector_free(namespace_selector_local_nonprim);
        namespace_selector_local_nonprim = NULL;
    }
    if (object_selector_local_nonprim) {
        v1_label_selector_free(object_selector_local_nonprim);
        object_selector_local_nonprim = NULL;
    }
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            v1_rule_with_operations_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    return NULL;

}
