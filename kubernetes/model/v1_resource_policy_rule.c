#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_policy_rule.h"



static v1_resource_policy_rule_t *v1_resource_policy_rule_create_internal(
    list_t *api_groups,
    int cluster_scope,
    list_t *namespaces,
    list_t *resources,
    list_t *verbs
    ) {
    v1_resource_policy_rule_t *v1_resource_policy_rule_local_var = malloc(sizeof(v1_resource_policy_rule_t));
    if (!v1_resource_policy_rule_local_var) {
        return NULL;
    }
    v1_resource_policy_rule_local_var->api_groups = api_groups;
    v1_resource_policy_rule_local_var->cluster_scope = cluster_scope;
    v1_resource_policy_rule_local_var->namespaces = namespaces;
    v1_resource_policy_rule_local_var->resources = resources;
    v1_resource_policy_rule_local_var->verbs = verbs;

    v1_resource_policy_rule_local_var->_library_owned = 1;
    return v1_resource_policy_rule_local_var;
}

__attribute__((deprecated)) v1_resource_policy_rule_t *v1_resource_policy_rule_create(
    list_t *api_groups,
    int cluster_scope,
    list_t *namespaces,
    list_t *resources,
    list_t *verbs
    ) {
    return v1_resource_policy_rule_create_internal (
        api_groups,
        cluster_scope,
        namespaces,
        resources,
        verbs
        );
}

void v1_resource_policy_rule_free(v1_resource_policy_rule_t *v1_resource_policy_rule) {
    if(NULL == v1_resource_policy_rule){
        return ;
    }
    if(v1_resource_policy_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_resource_policy_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_policy_rule->api_groups) {
        list_ForEach(listEntry, v1_resource_policy_rule->api_groups) {
            free(listEntry->data);
        }
        list_freeList(v1_resource_policy_rule->api_groups);
        v1_resource_policy_rule->api_groups = NULL;
    }
    if (v1_resource_policy_rule->namespaces) {
        list_ForEach(listEntry, v1_resource_policy_rule->namespaces) {
            free(listEntry->data);
        }
        list_freeList(v1_resource_policy_rule->namespaces);
        v1_resource_policy_rule->namespaces = NULL;
    }
    if (v1_resource_policy_rule->resources) {
        list_ForEach(listEntry, v1_resource_policy_rule->resources) {
            free(listEntry->data);
        }
        list_freeList(v1_resource_policy_rule->resources);
        v1_resource_policy_rule->resources = NULL;
    }
    if (v1_resource_policy_rule->verbs) {
        list_ForEach(listEntry, v1_resource_policy_rule->verbs) {
            free(listEntry->data);
        }
        list_freeList(v1_resource_policy_rule->verbs);
        v1_resource_policy_rule->verbs = NULL;
    }
    free(v1_resource_policy_rule);
}

cJSON *v1_resource_policy_rule_convertToJSON(v1_resource_policy_rule_t *v1_resource_policy_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_policy_rule->api_groups
    if (!v1_resource_policy_rule->api_groups) {
        goto fail;
    }
    cJSON *api_groups = cJSON_AddArrayToObject(item, "apiGroups");
    if(api_groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *api_groupsListEntry;
    list_ForEach(api_groupsListEntry, v1_resource_policy_rule->api_groups) {
    if(cJSON_AddStringToObject(api_groups, "", api_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_resource_policy_rule->cluster_scope
    if(v1_resource_policy_rule->cluster_scope) {
    if(cJSON_AddBoolToObject(item, "clusterScope", v1_resource_policy_rule->cluster_scope) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_resource_policy_rule->namespaces
    if(v1_resource_policy_rule->namespaces) {
    cJSON *namespaces = cJSON_AddArrayToObject(item, "namespaces");
    if(namespaces == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *namespacesListEntry;
    list_ForEach(namespacesListEntry, v1_resource_policy_rule->namespaces) {
    if(cJSON_AddStringToObject(namespaces, "", namespacesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_resource_policy_rule->resources
    if (!v1_resource_policy_rule->resources) {
        goto fail;
    }
    cJSON *resources = cJSON_AddArrayToObject(item, "resources");
    if(resources == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *resourcesListEntry;
    list_ForEach(resourcesListEntry, v1_resource_policy_rule->resources) {
    if(cJSON_AddStringToObject(resources, "", resourcesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_resource_policy_rule->verbs
    if (!v1_resource_policy_rule->verbs) {
        goto fail;
    }
    cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1_resource_policy_rule->verbs) {
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

v1_resource_policy_rule_t *v1_resource_policy_rule_parseFromJSON(cJSON *v1_resource_policy_ruleJSON){

    v1_resource_policy_rule_t *v1_resource_policy_rule_local_var = NULL;

    // define the local list for v1_resource_policy_rule->api_groups
    list_t *api_groupsList = NULL;

    // define the local list for v1_resource_policy_rule->namespaces
    list_t *namespacesList = NULL;

    // define the local list for v1_resource_policy_rule->resources
    list_t *resourcesList = NULL;

    // define the local list for v1_resource_policy_rule->verbs
    list_t *verbsList = NULL;

    // v1_resource_policy_rule->api_groups
    cJSON *api_groups = cJSON_GetObjectItemCaseSensitive(v1_resource_policy_ruleJSON, "apiGroups");
    if (cJSON_IsNull(api_groups)) {
        api_groups = NULL;
    }
    if (!api_groups) {
        goto end;
    }

    
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

    // v1_resource_policy_rule->cluster_scope
    cJSON *cluster_scope = cJSON_GetObjectItemCaseSensitive(v1_resource_policy_ruleJSON, "clusterScope");
    if (cJSON_IsNull(cluster_scope)) {
        cluster_scope = NULL;
    }
    if (cluster_scope) { 
    if(!cJSON_IsBool(cluster_scope))
    {
    goto end; //Bool
    }
    }

    // v1_resource_policy_rule->namespaces
    cJSON *namespaces = cJSON_GetObjectItemCaseSensitive(v1_resource_policy_ruleJSON, "namespaces");
    if (cJSON_IsNull(namespaces)) {
        namespaces = NULL;
    }
    if (namespaces) { 
    cJSON *namespaces_local = NULL;
    if(!cJSON_IsArray(namespaces)) {
        goto end;//primitive container
    }
    namespacesList = list_createList();

    cJSON_ArrayForEach(namespaces_local, namespaces)
    {
        if(!cJSON_IsString(namespaces_local))
        {
            goto end;
        }
        list_addElement(namespacesList , strdup(namespaces_local->valuestring));
    }
    }

    // v1_resource_policy_rule->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_resource_policy_ruleJSON, "resources");
    if (cJSON_IsNull(resources)) {
        resources = NULL;
    }
    if (!resources) {
        goto end;
    }

    
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

    // v1_resource_policy_rule->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v1_resource_policy_ruleJSON, "verbs");
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


    v1_resource_policy_rule_local_var = v1_resource_policy_rule_create_internal (
        api_groupsList,
        cluster_scope ? cluster_scope->valueint : 0,
        namespaces ? namespacesList : NULL,
        resourcesList,
        verbsList
        );

    return v1_resource_policy_rule_local_var;
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
    if (namespacesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, namespacesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(namespacesList);
        namespacesList = NULL;
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
