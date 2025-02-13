#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scheduling.h"



static v1_scheduling_t *v1_scheduling_create_internal(
    list_t* node_selector,
    list_t *tolerations
    ) {
    v1_scheduling_t *v1_scheduling_local_var = malloc(sizeof(v1_scheduling_t));
    if (!v1_scheduling_local_var) {
        return NULL;
    }
    v1_scheduling_local_var->node_selector = node_selector;
    v1_scheduling_local_var->tolerations = tolerations;

    v1_scheduling_local_var->_library_owned = 1;
    return v1_scheduling_local_var;
}

__attribute__((deprecated)) v1_scheduling_t *v1_scheduling_create(
    list_t* node_selector,
    list_t *tolerations
    ) {
    return v1_scheduling_create_internal (
        node_selector,
        tolerations
        );
}

void v1_scheduling_free(v1_scheduling_t *v1_scheduling) {
    if(NULL == v1_scheduling){
        return ;
    }
    if(v1_scheduling->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_scheduling_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_scheduling->node_selector) {
        list_ForEach(listEntry, v1_scheduling->node_selector) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_scheduling->node_selector);
        v1_scheduling->node_selector = NULL;
    }
    if (v1_scheduling->tolerations) {
        list_ForEach(listEntry, v1_scheduling->tolerations) {
            v1_toleration_free(listEntry->data);
        }
        list_freeList(v1_scheduling->tolerations);
        v1_scheduling->tolerations = NULL;
    }
    free(v1_scheduling);
}

cJSON *v1_scheduling_convertToJSON(v1_scheduling_t *v1_scheduling) {
    cJSON *item = cJSON_CreateObject();

    // v1_scheduling->node_selector
    if(v1_scheduling->node_selector) {
    cJSON *node_selector = cJSON_AddObjectToObject(item, "nodeSelector");
    if(node_selector == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = node_selector;
    listEntry_t *node_selectorListEntry;
    if (v1_scheduling->node_selector) {
    list_ForEach(node_selectorListEntry, v1_scheduling->node_selector) {
        keyValuePair_t *localKeyValue = node_selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_scheduling->tolerations
    if(v1_scheduling->tolerations) {
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1_scheduling->tolerations) {
    list_ForEach(tolerationsListEntry, v1_scheduling->tolerations) {
    cJSON *itemLocal = v1_toleration_convertToJSON(tolerationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tolerations, itemLocal);
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

v1_scheduling_t *v1_scheduling_parseFromJSON(cJSON *v1_schedulingJSON){

    v1_scheduling_t *v1_scheduling_local_var = NULL;

    // define the local map for v1_scheduling->node_selector
    list_t *node_selectorList = NULL;

    // define the local list for v1_scheduling->tolerations
    list_t *tolerationsList = NULL;

    // v1_scheduling->node_selector
    cJSON *node_selector = cJSON_GetObjectItemCaseSensitive(v1_schedulingJSON, "nodeSelector");
    if (cJSON_IsNull(node_selector)) {
        node_selector = NULL;
    }
    if (node_selector) { 
    cJSON *node_selector_local_map = NULL;
    if(!cJSON_IsObject(node_selector) && !cJSON_IsNull(node_selector))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(node_selector))
    {
        node_selectorList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(node_selector_local_map, node_selector)
        {
            cJSON *localMapObject = node_selector_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(node_selectorList , localMapKeyPair);
        }
    }
    }

    // v1_scheduling->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1_schedulingJSON, "tolerations");
    if (cJSON_IsNull(tolerations)) {
        tolerations = NULL;
    }
    if (tolerations) { 
    cJSON *tolerations_local_nonprimitive = NULL;
    if(!cJSON_IsArray(tolerations)){
        goto end; //nonprimitive container
    }

    tolerationsList = list_createList();

    cJSON_ArrayForEach(tolerations_local_nonprimitive,tolerations )
    {
        if(!cJSON_IsObject(tolerations_local_nonprimitive)){
            goto end;
        }
        v1_toleration_t *tolerationsItem = v1_toleration_parseFromJSON(tolerations_local_nonprimitive);

        list_addElement(tolerationsList, tolerationsItem);
    }
    }


    v1_scheduling_local_var = v1_scheduling_create_internal (
        node_selector ? node_selectorList : NULL,
        tolerations ? tolerationsList : NULL
        );

    return v1_scheduling_local_var;
end:
    if (node_selectorList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, node_selectorList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(node_selectorList);
        node_selectorList = NULL;
    }
    if (tolerationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tolerationsList) {
            v1_toleration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tolerationsList);
        tolerationsList = NULL;
    }
    return NULL;

}
