#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_definition_status.h"



static v1_custom_resource_definition_status_t *v1_custom_resource_definition_status_create_internal(
    v1_custom_resource_definition_names_t *accepted_names,
    list_t *conditions,
    list_t *stored_versions
    ) {
    v1_custom_resource_definition_status_t *v1_custom_resource_definition_status_local_var = malloc(sizeof(v1_custom_resource_definition_status_t));
    if (!v1_custom_resource_definition_status_local_var) {
        return NULL;
    }
    v1_custom_resource_definition_status_local_var->accepted_names = accepted_names;
    v1_custom_resource_definition_status_local_var->conditions = conditions;
    v1_custom_resource_definition_status_local_var->stored_versions = stored_versions;

    v1_custom_resource_definition_status_local_var->_library_owned = 1;
    return v1_custom_resource_definition_status_local_var;
}

__attribute__((deprecated)) v1_custom_resource_definition_status_t *v1_custom_resource_definition_status_create(
    v1_custom_resource_definition_names_t *accepted_names,
    list_t *conditions,
    list_t *stored_versions
    ) {
    return v1_custom_resource_definition_status_create_internal (
        accepted_names,
        conditions,
        stored_versions
        );
}

void v1_custom_resource_definition_status_free(v1_custom_resource_definition_status_t *v1_custom_resource_definition_status) {
    if(NULL == v1_custom_resource_definition_status){
        return ;
    }
    if(v1_custom_resource_definition_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_custom_resource_definition_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_definition_status->accepted_names) {
        v1_custom_resource_definition_names_free(v1_custom_resource_definition_status->accepted_names);
        v1_custom_resource_definition_status->accepted_names = NULL;
    }
    if (v1_custom_resource_definition_status->conditions) {
        list_ForEach(listEntry, v1_custom_resource_definition_status->conditions) {
            v1_custom_resource_definition_condition_free(listEntry->data);
        }
        list_freeList(v1_custom_resource_definition_status->conditions);
        v1_custom_resource_definition_status->conditions = NULL;
    }
    if (v1_custom_resource_definition_status->stored_versions) {
        list_ForEach(listEntry, v1_custom_resource_definition_status->stored_versions) {
            free(listEntry->data);
        }
        list_freeList(v1_custom_resource_definition_status->stored_versions);
        v1_custom_resource_definition_status->stored_versions = NULL;
    }
    free(v1_custom_resource_definition_status);
}

cJSON *v1_custom_resource_definition_status_convertToJSON(v1_custom_resource_definition_status_t *v1_custom_resource_definition_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_custom_resource_definition_status->accepted_names
    if(v1_custom_resource_definition_status->accepted_names) {
    cJSON *accepted_names_local_JSON = v1_custom_resource_definition_names_convertToJSON(v1_custom_resource_definition_status->accepted_names);
    if(accepted_names_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "acceptedNames", accepted_names_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_custom_resource_definition_status->conditions
    if(v1_custom_resource_definition_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_custom_resource_definition_status->conditions) {
    list_ForEach(conditionsListEntry, v1_custom_resource_definition_status->conditions) {
    cJSON *itemLocal = v1_custom_resource_definition_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_custom_resource_definition_status->stored_versions
    if(v1_custom_resource_definition_status->stored_versions) {
    cJSON *stored_versions = cJSON_AddArrayToObject(item, "storedVersions");
    if(stored_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *stored_versionsListEntry;
    list_ForEach(stored_versionsListEntry, v1_custom_resource_definition_status->stored_versions) {
    if(cJSON_AddStringToObject(stored_versions, "", stored_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_custom_resource_definition_status_t *v1_custom_resource_definition_status_parseFromJSON(cJSON *v1_custom_resource_definition_statusJSON){

    v1_custom_resource_definition_status_t *v1_custom_resource_definition_status_local_var = NULL;

    // define the local variable for v1_custom_resource_definition_status->accepted_names
    v1_custom_resource_definition_names_t *accepted_names_local_nonprim = NULL;

    // define the local list for v1_custom_resource_definition_status->conditions
    list_t *conditionsList = NULL;

    // define the local list for v1_custom_resource_definition_status->stored_versions
    list_t *stored_versionsList = NULL;

    // v1_custom_resource_definition_status->accepted_names
    cJSON *accepted_names = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_statusJSON, "acceptedNames");
    if (cJSON_IsNull(accepted_names)) {
        accepted_names = NULL;
    }
    if (accepted_names) { 
    accepted_names_local_nonprim = v1_custom_resource_definition_names_parseFromJSON(accepted_names); //nonprimitive
    }

    // v1_custom_resource_definition_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_statusJSON, "conditions");
    if (cJSON_IsNull(conditions)) {
        conditions = NULL;
    }
    if (conditions) { 
    cJSON *conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_custom_resource_definition_condition_t *conditionsItem = v1_custom_resource_definition_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_custom_resource_definition_status->stored_versions
    cJSON *stored_versions = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_statusJSON, "storedVersions");
    if (cJSON_IsNull(stored_versions)) {
        stored_versions = NULL;
    }
    if (stored_versions) { 
    cJSON *stored_versions_local = NULL;
    if(!cJSON_IsArray(stored_versions)) {
        goto end;//primitive container
    }
    stored_versionsList = list_createList();

    cJSON_ArrayForEach(stored_versions_local, stored_versions)
    {
        if(!cJSON_IsString(stored_versions_local))
        {
            goto end;
        }
        list_addElement(stored_versionsList , strdup(stored_versions_local->valuestring));
    }
    }


    v1_custom_resource_definition_status_local_var = v1_custom_resource_definition_status_create_internal (
        accepted_names ? accepted_names_local_nonprim : NULL,
        conditions ? conditionsList : NULL,
        stored_versions ? stored_versionsList : NULL
        );

    return v1_custom_resource_definition_status_local_var;
end:
    if (accepted_names_local_nonprim) {
        v1_custom_resource_definition_names_free(accepted_names_local_nonprim);
        accepted_names_local_nonprim = NULL;
    }
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_custom_resource_definition_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (stored_versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, stored_versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(stored_versionsList);
        stored_versionsList = NULL;
    }
    return NULL;

}
