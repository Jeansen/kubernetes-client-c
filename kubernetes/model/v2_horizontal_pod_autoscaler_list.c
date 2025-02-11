#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_horizontal_pod_autoscaler_list.h"



static v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list_create_internal(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list_local_var = malloc(sizeof(v2_horizontal_pod_autoscaler_list_t));
    if (!v2_horizontal_pod_autoscaler_list_local_var) {
        return NULL;
    }
    v2_horizontal_pod_autoscaler_list_local_var->api_version = api_version;
    v2_horizontal_pod_autoscaler_list_local_var->items = items;
    v2_horizontal_pod_autoscaler_list_local_var->kind = kind;
    v2_horizontal_pod_autoscaler_list_local_var->metadata = metadata;

    v2_horizontal_pod_autoscaler_list_local_var->_library_owned = 1;
    return v2_horizontal_pod_autoscaler_list_local_var;
}

__attribute__((deprecated)) v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
    ) {
    return v2_horizontal_pod_autoscaler_list_create_internal (
        api_version,
        items,
        kind,
        metadata
        );
}

void v2_horizontal_pod_autoscaler_list_free(v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list) {
    if(NULL == v2_horizontal_pod_autoscaler_list){
        return ;
    }
    if(v2_horizontal_pod_autoscaler_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_horizontal_pod_autoscaler_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_horizontal_pod_autoscaler_list->api_version) {
        free(v2_horizontal_pod_autoscaler_list->api_version);
        v2_horizontal_pod_autoscaler_list->api_version = NULL;
    }
    if (v2_horizontal_pod_autoscaler_list->items) {
        list_ForEach(listEntry, v2_horizontal_pod_autoscaler_list->items) {
            v2_horizontal_pod_autoscaler_free(listEntry->data);
        }
        list_freeList(v2_horizontal_pod_autoscaler_list->items);
        v2_horizontal_pod_autoscaler_list->items = NULL;
    }
    if (v2_horizontal_pod_autoscaler_list->kind) {
        free(v2_horizontal_pod_autoscaler_list->kind);
        v2_horizontal_pod_autoscaler_list->kind = NULL;
    }
    if (v2_horizontal_pod_autoscaler_list->metadata) {
        v1_list_meta_free(v2_horizontal_pod_autoscaler_list->metadata);
        v2_horizontal_pod_autoscaler_list->metadata = NULL;
    }
    free(v2_horizontal_pod_autoscaler_list);
}

cJSON *v2_horizontal_pod_autoscaler_list_convertToJSON(v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list) {
    cJSON *item = cJSON_CreateObject();

    // v2_horizontal_pod_autoscaler_list->api_version
    if(v2_horizontal_pod_autoscaler_list->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v2_horizontal_pod_autoscaler_list->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v2_horizontal_pod_autoscaler_list->items
    if (!v2_horizontal_pod_autoscaler_list->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (v2_horizontal_pod_autoscaler_list->items) {
    list_ForEach(itemsListEntry, v2_horizontal_pod_autoscaler_list->items) {
    cJSON *itemLocal = v2_horizontal_pod_autoscaler_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // v2_horizontal_pod_autoscaler_list->kind
    if(v2_horizontal_pod_autoscaler_list->kind) {
    if(cJSON_AddStringToObject(item, "kind", v2_horizontal_pod_autoscaler_list->kind) == NULL) {
    goto fail; //String
    }
    }


    // v2_horizontal_pod_autoscaler_list->metadata
    if(v2_horizontal_pod_autoscaler_list->metadata) {
    cJSON *metadata_local_JSON = v1_list_meta_convertToJSON(v2_horizontal_pod_autoscaler_list->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
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

v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list_parseFromJSON(cJSON *v2_horizontal_pod_autoscaler_listJSON){

    v2_horizontal_pod_autoscaler_list_t *v2_horizontal_pod_autoscaler_list_local_var = NULL;

    // define the local list for v2_horizontal_pod_autoscaler_list->items
    list_t *itemsList = NULL;

    // define the local variable for v2_horizontal_pod_autoscaler_list->metadata
    v1_list_meta_t *metadata_local_nonprim = NULL;

    // v2_horizontal_pod_autoscaler_list->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_listJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v2_horizontal_pod_autoscaler_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_listJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    if (!items) {
        goto end;
    }

    
    cJSON *items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_createList();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        v2_horizontal_pod_autoscaler_t *itemsItem = v2_horizontal_pod_autoscaler_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // v2_horizontal_pod_autoscaler_list->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_listJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v2_horizontal_pod_autoscaler_list->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_listJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_list_meta_parseFromJSON(metadata); //nonprimitive
    }


    v2_horizontal_pod_autoscaler_list_local_var = v2_horizontal_pod_autoscaler_list_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        itemsList,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v2_horizontal_pod_autoscaler_list_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            v2_horizontal_pod_autoscaler_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_list_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
