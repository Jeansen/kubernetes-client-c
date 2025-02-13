#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_validating_webhook_configuration.h"



static v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *webhooks
    ) {
    v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_local_var = malloc(sizeof(v1_validating_webhook_configuration_t));
    if (!v1_validating_webhook_configuration_local_var) {
        return NULL;
    }
    v1_validating_webhook_configuration_local_var->api_version = api_version;
    v1_validating_webhook_configuration_local_var->kind = kind;
    v1_validating_webhook_configuration_local_var->metadata = metadata;
    v1_validating_webhook_configuration_local_var->webhooks = webhooks;

    v1_validating_webhook_configuration_local_var->_library_owned = 1;
    return v1_validating_webhook_configuration_local_var;
}

__attribute__((deprecated)) v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *webhooks
    ) {
    return v1_validating_webhook_configuration_create_internal (
        api_version,
        kind,
        metadata,
        webhooks
        );
}

void v1_validating_webhook_configuration_free(v1_validating_webhook_configuration_t *v1_validating_webhook_configuration) {
    if(NULL == v1_validating_webhook_configuration){
        return ;
    }
    if(v1_validating_webhook_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_validating_webhook_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_validating_webhook_configuration->api_version) {
        free(v1_validating_webhook_configuration->api_version);
        v1_validating_webhook_configuration->api_version = NULL;
    }
    if (v1_validating_webhook_configuration->kind) {
        free(v1_validating_webhook_configuration->kind);
        v1_validating_webhook_configuration->kind = NULL;
    }
    if (v1_validating_webhook_configuration->metadata) {
        v1_object_meta_free(v1_validating_webhook_configuration->metadata);
        v1_validating_webhook_configuration->metadata = NULL;
    }
    if (v1_validating_webhook_configuration->webhooks) {
        list_ForEach(listEntry, v1_validating_webhook_configuration->webhooks) {
            v1_validating_webhook_free(listEntry->data);
        }
        list_freeList(v1_validating_webhook_configuration->webhooks);
        v1_validating_webhook_configuration->webhooks = NULL;
    }
    free(v1_validating_webhook_configuration);
}

cJSON *v1_validating_webhook_configuration_convertToJSON(v1_validating_webhook_configuration_t *v1_validating_webhook_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1_validating_webhook_configuration->api_version
    if(v1_validating_webhook_configuration->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_validating_webhook_configuration->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_validating_webhook_configuration->kind
    if(v1_validating_webhook_configuration->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_validating_webhook_configuration->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_validating_webhook_configuration->metadata
    if(v1_validating_webhook_configuration->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_validating_webhook_configuration->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_validating_webhook_configuration->webhooks
    if(v1_validating_webhook_configuration->webhooks) {
    cJSON *webhooks = cJSON_AddArrayToObject(item, "webhooks");
    if(webhooks == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *webhooksListEntry;
    if (v1_validating_webhook_configuration->webhooks) {
    list_ForEach(webhooksListEntry, v1_validating_webhook_configuration->webhooks) {
    cJSON *itemLocal = v1_validating_webhook_convertToJSON(webhooksListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(webhooks, itemLocal);
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

v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_parseFromJSON(cJSON *v1_validating_webhook_configurationJSON){

    v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_local_var = NULL;

    // define the local variable for v1_validating_webhook_configuration->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local list for v1_validating_webhook_configuration->webhooks
    list_t *webhooksList = NULL;

    // v1_validating_webhook_configuration->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_validating_webhook_configurationJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_validating_webhook_configuration->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_validating_webhook_configurationJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_validating_webhook_configuration->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_validating_webhook_configurationJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_validating_webhook_configuration->webhooks
    cJSON *webhooks = cJSON_GetObjectItemCaseSensitive(v1_validating_webhook_configurationJSON, "webhooks");
    if (cJSON_IsNull(webhooks)) {
        webhooks = NULL;
    }
    if (webhooks) { 
    cJSON *webhooks_local_nonprimitive = NULL;
    if(!cJSON_IsArray(webhooks)){
        goto end; //nonprimitive container
    }

    webhooksList = list_createList();

    cJSON_ArrayForEach(webhooks_local_nonprimitive,webhooks )
    {
        if(!cJSON_IsObject(webhooks_local_nonprimitive)){
            goto end;
        }
        v1_validating_webhook_t *webhooksItem = v1_validating_webhook_parseFromJSON(webhooks_local_nonprimitive);

        list_addElement(webhooksList, webhooksItem);
    }
    }


    v1_validating_webhook_configuration_local_var = v1_validating_webhook_configuration_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        webhooks ? webhooksList : NULL
        );

    return v1_validating_webhook_configuration_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (webhooksList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, webhooksList) {
            v1_validating_webhook_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(webhooksList);
        webhooksList = NULL;
    }
    return NULL;

}
