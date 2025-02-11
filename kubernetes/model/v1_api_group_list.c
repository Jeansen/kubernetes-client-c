#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_group_list.h"



static v1_api_group_list_t *v1_api_group_list_create_internal(
    char *api_version,
    list_t *groups,
    char *kind
    ) {
    v1_api_group_list_t *v1_api_group_list_local_var = malloc(sizeof(v1_api_group_list_t));
    if (!v1_api_group_list_local_var) {
        return NULL;
    }
    v1_api_group_list_local_var->api_version = api_version;
    v1_api_group_list_local_var->groups = groups;
    v1_api_group_list_local_var->kind = kind;

    v1_api_group_list_local_var->_library_owned = 1;
    return v1_api_group_list_local_var;
}

__attribute__((deprecated)) v1_api_group_list_t *v1_api_group_list_create(
    char *api_version,
    list_t *groups,
    char *kind
    ) {
    return v1_api_group_list_create_internal (
        api_version,
        groups,
        kind
        );
}

void v1_api_group_list_free(v1_api_group_list_t *v1_api_group_list) {
    if(NULL == v1_api_group_list){
        return ;
    }
    if(v1_api_group_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_api_group_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_api_group_list->api_version) {
        free(v1_api_group_list->api_version);
        v1_api_group_list->api_version = NULL;
    }
    if (v1_api_group_list->groups) {
        list_ForEach(listEntry, v1_api_group_list->groups) {
            v1_api_group_free(listEntry->data);
        }
        list_freeList(v1_api_group_list->groups);
        v1_api_group_list->groups = NULL;
    }
    if (v1_api_group_list->kind) {
        free(v1_api_group_list->kind);
        v1_api_group_list->kind = NULL;
    }
    free(v1_api_group_list);
}

cJSON *v1_api_group_list_convertToJSON(v1_api_group_list_t *v1_api_group_list) {
    cJSON *item = cJSON_CreateObject();

    // v1_api_group_list->api_version
    if(v1_api_group_list->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_api_group_list->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_group_list->groups
    if (!v1_api_group_list->groups) {
        goto fail;
    }
    cJSON *groups = cJSON_AddArrayToObject(item, "groups");
    if(groups == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *groupsListEntry;
    if (v1_api_group_list->groups) {
    list_ForEach(groupsListEntry, v1_api_group_list->groups) {
    cJSON *itemLocal = v1_api_group_convertToJSON(groupsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(groups, itemLocal);
    }
    }


    // v1_api_group_list->kind
    if(v1_api_group_list->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_api_group_list->kind) == NULL) {
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

v1_api_group_list_t *v1_api_group_list_parseFromJSON(cJSON *v1_api_group_listJSON){

    v1_api_group_list_t *v1_api_group_list_local_var = NULL;

    // define the local list for v1_api_group_list->groups
    list_t *groupsList = NULL;

    // v1_api_group_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_api_group_listJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_api_group_list->groups
    cJSON *groups = cJSON_GetObjectItemCaseSensitive(v1_api_group_listJSON, "groups");
    if (cJSON_IsNull(groups)) {
        groups = NULL;
    }
    if (!groups) {
        goto end;
    }

    
    cJSON *groups_local_nonprimitive = NULL;
    if(!cJSON_IsArray(groups)){
        goto end; //nonprimitive container
    }

    groupsList = list_createList();

    cJSON_ArrayForEach(groups_local_nonprimitive,groups )
    {
        if(!cJSON_IsObject(groups_local_nonprimitive)){
            goto end;
        }
        v1_api_group_t *groupsItem = v1_api_group_parseFromJSON(groups_local_nonprimitive);

        list_addElement(groupsList, groupsItem);
    }

    // v1_api_group_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_api_group_listJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }


    v1_api_group_list_local_var = v1_api_group_list_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        groupsList,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL
        );

    return v1_api_group_list_local_var;
end:
    if (groupsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, groupsList) {
            v1_api_group_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(groupsList);
        groupsList = NULL;
    }
    return NULL;

}
