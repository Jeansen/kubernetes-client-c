#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_policy_rule.h"



static v1_policy_rule_t *v1_policy_rule_create_internal(
    list_t *api_groups,
    list_t *non_resource_urls,
    list_t *resource_names,
    list_t *resources,
    list_t *verbs
    ) {
    v1_policy_rule_t *v1_policy_rule_local_var = malloc(sizeof(v1_policy_rule_t));
    if (!v1_policy_rule_local_var) {
        return NULL;
    }
    v1_policy_rule_local_var->api_groups = api_groups;
    v1_policy_rule_local_var->non_resource_urls = non_resource_urls;
    v1_policy_rule_local_var->resource_names = resource_names;
    v1_policy_rule_local_var->resources = resources;
    v1_policy_rule_local_var->verbs = verbs;

    v1_policy_rule_local_var->_library_owned = 1;
    return v1_policy_rule_local_var;
}

__attribute__((deprecated)) v1_policy_rule_t *v1_policy_rule_create(
    list_t *api_groups,
    list_t *non_resource_urls,
    list_t *resource_names,
    list_t *resources,
    list_t *verbs
    ) {
    return v1_policy_rule_create_internal (
        api_groups,
        non_resource_urls,
        resource_names,
        resources,
        verbs
        );
}

void v1_policy_rule_free(v1_policy_rule_t *v1_policy_rule) {
    if(NULL == v1_policy_rule){
        return ;
    }
    if(v1_policy_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_policy_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_policy_rule->api_groups) {
        list_ForEach(listEntry, v1_policy_rule->api_groups) {
            free(listEntry->data);
        }
        list_freeList(v1_policy_rule->api_groups);
        v1_policy_rule->api_groups = NULL;
    }
    if (v1_policy_rule->non_resource_urls) {
        list_ForEach(listEntry, v1_policy_rule->non_resource_urls) {
            free(listEntry->data);
        }
        list_freeList(v1_policy_rule->non_resource_urls);
        v1_policy_rule->non_resource_urls = NULL;
    }
    if (v1_policy_rule->resource_names) {
        list_ForEach(listEntry, v1_policy_rule->resource_names) {
            free(listEntry->data);
        }
        list_freeList(v1_policy_rule->resource_names);
        v1_policy_rule->resource_names = NULL;
    }
    if (v1_policy_rule->resources) {
        list_ForEach(listEntry, v1_policy_rule->resources) {
            free(listEntry->data);
        }
        list_freeList(v1_policy_rule->resources);
        v1_policy_rule->resources = NULL;
    }
    if (v1_policy_rule->verbs) {
        list_ForEach(listEntry, v1_policy_rule->verbs) {
            free(listEntry->data);
        }
        list_freeList(v1_policy_rule->verbs);
        v1_policy_rule->verbs = NULL;
    }
    free(v1_policy_rule);
}

cJSON *v1_policy_rule_convertToJSON(v1_policy_rule_t *v1_policy_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_policy_rule->api_groups
    if(v1_policy_rule->api_groups) {
    cJSON *api_groups = cJSON_AddArrayToObject(item, "apiGroups");
    if(api_groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *api_groupsListEntry;
    list_ForEach(api_groupsListEntry, v1_policy_rule->api_groups) {
    if(cJSON_AddStringToObject(api_groups, "", api_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_policy_rule->non_resource_urls
    if(v1_policy_rule->non_resource_urls) {
    cJSON *non_resource_urls = cJSON_AddArrayToObject(item, "nonResourceURLs");
    if(non_resource_urls == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *non_resource_urlsListEntry;
    list_ForEach(non_resource_urlsListEntry, v1_policy_rule->non_resource_urls) {
    if(cJSON_AddStringToObject(non_resource_urls, "", non_resource_urlsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_policy_rule->resource_names
    if(v1_policy_rule->resource_names) {
    cJSON *resource_names = cJSON_AddArrayToObject(item, "resourceNames");
    if(resource_names == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *resource_namesListEntry;
    list_ForEach(resource_namesListEntry, v1_policy_rule->resource_names) {
    if(cJSON_AddStringToObject(resource_names, "", resource_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_policy_rule->resources
    if(v1_policy_rule->resources) {
    cJSON *resources = cJSON_AddArrayToObject(item, "resources");
    if(resources == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *resourcesListEntry;
    list_ForEach(resourcesListEntry, v1_policy_rule->resources) {
    if(cJSON_AddStringToObject(resources, "", resourcesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_policy_rule->verbs
    if (!v1_policy_rule->verbs) {
        goto fail;
    }
    cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1_policy_rule->verbs) {
    if(cJSON_AddStringToObject(verbs, "", verbsListEntry->data) == NULL)
    {
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

v1_policy_rule_t *v1_policy_rule_parseFromJSON(cJSON *v1_policy_ruleJSON){

    v1_policy_rule_t *v1_policy_rule_local_var = NULL;

    // define the local list for v1_policy_rule->api_groups
    list_t *api_groupsList = NULL;

    // define the local list for v1_policy_rule->non_resource_urls
    list_t *non_resource_urlsList = NULL;

    // define the local list for v1_policy_rule->resource_names
    list_t *resource_namesList = NULL;

    // define the local list for v1_policy_rule->resources
    list_t *resourcesList = NULL;

    // define the local list for v1_policy_rule->verbs
    list_t *verbsList = NULL;

    // v1_policy_rule->api_groups
    cJSON *api_groups = cJSON_GetObjectItemCaseSensitive(v1_policy_ruleJSON, "apiGroups");
    if (cJSON_IsNull(api_groups)) {
        api_groups = NULL;
    }
    if (api_groups) { 
    cJSON *api_groups_local = NULL;
    if(!cJSON_IsArray(api_groups)) {
        goto end;//primitive container
    }
    api_groupsList = list_createList();

    cJSON_ArrayForEach(api_groups_local, api_groups)
    {
        if(!cJSON_IsString(api_groups_local))
        {
            goto end;
        }
        list_addElement(api_groupsList , strdup(api_groups_local->valuestring));
    }
    }

    // v1_policy_rule->non_resource_urls
    cJSON *non_resource_urls = cJSON_GetObjectItemCaseSensitive(v1_policy_ruleJSON, "nonResourceURLs");
    if (cJSON_IsNull(non_resource_urls)) {
        non_resource_urls = NULL;
    }
    if (non_resource_urls) { 
    cJSON *non_resource_urls_local = NULL;
    if(!cJSON_IsArray(non_resource_urls)) {
        goto end;//primitive container
    }
    non_resource_urlsList = list_createList();

    cJSON_ArrayForEach(non_resource_urls_local, non_resource_urls)
    {
        if(!cJSON_IsString(non_resource_urls_local))
        {
            goto end;
        }
        list_addElement(non_resource_urlsList , strdup(non_resource_urls_local->valuestring));
    }
    }

    // v1_policy_rule->resource_names
    cJSON *resource_names = cJSON_GetObjectItemCaseSensitive(v1_policy_ruleJSON, "resourceNames");
    if (cJSON_IsNull(resource_names)) {
        resource_names = NULL;
    }
    if (resource_names) { 
    cJSON *resource_names_local = NULL;
    if(!cJSON_IsArray(resource_names)) {
        goto end;//primitive container
    }
    resource_namesList = list_createList();

    cJSON_ArrayForEach(resource_names_local, resource_names)
    {
        if(!cJSON_IsString(resource_names_local))
        {
            goto end;
        }
        list_addElement(resource_namesList , strdup(resource_names_local->valuestring));
    }
    }

    // v1_policy_rule->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_policy_ruleJSON, "resources");
    if (cJSON_IsNull(resources)) {
        resources = NULL;
    }
    if (resources) { 
    cJSON *resources_local = NULL;
    if(!cJSON_IsArray(resources)) {
        goto end;//primitive container
    }
    resourcesList = list_createList();

    cJSON_ArrayForEach(resources_local, resources)
    {
        if(!cJSON_IsString(resources_local))
        {
            goto end;
        }
        list_addElement(resourcesList , strdup(resources_local->valuestring));
    }
    }

    // v1_policy_rule->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v1_policy_ruleJSON, "verbs");
    if (cJSON_IsNull(verbs)) {
        verbs = NULL;
    }
    if (!verbs) {
        goto end;
    }

    
    cJSON *verbs_local = NULL;
    if(!cJSON_IsArray(verbs)) {
        goto end;//primitive container
    }
    verbsList = list_createList();

    cJSON_ArrayForEach(verbs_local, verbs)
    {
        if(!cJSON_IsString(verbs_local))
        {
            goto end;
        }
        list_addElement(verbsList , strdup(verbs_local->valuestring));
    }


    v1_policy_rule_local_var = v1_policy_rule_create_internal (
        api_groups ? api_groupsList : NULL,
        non_resource_urls ? non_resource_urlsList : NULL,
        resource_names ? resource_namesList : NULL,
        resources ? resourcesList : NULL,
        verbsList
        );

    return v1_policy_rule_local_var;
end:
    if (api_groupsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, api_groupsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(api_groupsList);
        api_groupsList = NULL;
    }
    if (non_resource_urlsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, non_resource_urlsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(non_resource_urlsList);
        non_resource_urlsList = NULL;
    }
    if (resource_namesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resource_namesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resource_namesList);
        resource_namesList = NULL;
    }
    if (resourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resourcesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resourcesList);
        resourcesList = NULL;
    }
    if (verbsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, verbsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(verbsList);
        verbsList = NULL;
    }
    return NULL;

}
