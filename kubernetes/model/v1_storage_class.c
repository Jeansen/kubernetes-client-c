#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_storage_class.h"



static v1_storage_class_t *v1_storage_class_create_internal(
    int allow_volume_expansion,
    list_t *allowed_topologies,
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *mount_options,
    list_t* parameters,
    char *provisioner,
    char *reclaim_policy,
    char *volume_binding_mode
    ) {
    v1_storage_class_t *v1_storage_class_local_var = malloc(sizeof(v1_storage_class_t));
    if (!v1_storage_class_local_var) {
        return NULL;
    }
    v1_storage_class_local_var->allow_volume_expansion = allow_volume_expansion;
    v1_storage_class_local_var->allowed_topologies = allowed_topologies;
    v1_storage_class_local_var->api_version = api_version;
    v1_storage_class_local_var->kind = kind;
    v1_storage_class_local_var->metadata = metadata;
    v1_storage_class_local_var->mount_options = mount_options;
    v1_storage_class_local_var->parameters = parameters;
    v1_storage_class_local_var->provisioner = provisioner;
    v1_storage_class_local_var->reclaim_policy = reclaim_policy;
    v1_storage_class_local_var->volume_binding_mode = volume_binding_mode;

    v1_storage_class_local_var->_library_owned = 1;
    return v1_storage_class_local_var;
}

__attribute__((deprecated)) v1_storage_class_t *v1_storage_class_create(
    int allow_volume_expansion,
    list_t *allowed_topologies,
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *mount_options,
    list_t* parameters,
    char *provisioner,
    char *reclaim_policy,
    char *volume_binding_mode
    ) {
    return v1_storage_class_create_internal (
        allow_volume_expansion,
        allowed_topologies,
        api_version,
        kind,
        metadata,
        mount_options,
        parameters,
        provisioner,
        reclaim_policy,
        volume_binding_mode
        );
}

void v1_storage_class_free(v1_storage_class_t *v1_storage_class) {
    if(NULL == v1_storage_class){
        return ;
    }
    if(v1_storage_class->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_storage_class_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_storage_class->allowed_topologies) {
        list_ForEach(listEntry, v1_storage_class->allowed_topologies) {
            v1_topology_selector_term_free(listEntry->data);
        }
        list_freeList(v1_storage_class->allowed_topologies);
        v1_storage_class->allowed_topologies = NULL;
    }
    if (v1_storage_class->api_version) {
        free(v1_storage_class->api_version);
        v1_storage_class->api_version = NULL;
    }
    if (v1_storage_class->kind) {
        free(v1_storage_class->kind);
        v1_storage_class->kind = NULL;
    }
    if (v1_storage_class->metadata) {
        v1_object_meta_free(v1_storage_class->metadata);
        v1_storage_class->metadata = NULL;
    }
    if (v1_storage_class->mount_options) {
        list_ForEach(listEntry, v1_storage_class->mount_options) {
            free(listEntry->data);
        }
        list_freeList(v1_storage_class->mount_options);
        v1_storage_class->mount_options = NULL;
    }
    if (v1_storage_class->parameters) {
        list_ForEach(listEntry, v1_storage_class->parameters) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_storage_class->parameters);
        v1_storage_class->parameters = NULL;
    }
    if (v1_storage_class->provisioner) {
        free(v1_storage_class->provisioner);
        v1_storage_class->provisioner = NULL;
    }
    if (v1_storage_class->reclaim_policy) {
        free(v1_storage_class->reclaim_policy);
        v1_storage_class->reclaim_policy = NULL;
    }
    if (v1_storage_class->volume_binding_mode) {
        free(v1_storage_class->volume_binding_mode);
        v1_storage_class->volume_binding_mode = NULL;
    }
    free(v1_storage_class);
}

cJSON *v1_storage_class_convertToJSON(v1_storage_class_t *v1_storage_class) {
    cJSON *item = cJSON_CreateObject();

    // v1_storage_class->allow_volume_expansion
    if(v1_storage_class->allow_volume_expansion) {
    if(cJSON_AddBoolToObject(item, "allowVolumeExpansion", v1_storage_class->allow_volume_expansion) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_storage_class->allowed_topologies
    if(v1_storage_class->allowed_topologies) {
    cJSON *allowed_topologies = cJSON_AddArrayToObject(item, "allowedTopologies");
    if(allowed_topologies == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_topologiesListEntry;
    if (v1_storage_class->allowed_topologies) {
    list_ForEach(allowed_topologiesListEntry, v1_storage_class->allowed_topologies) {
    cJSON *itemLocal = v1_topology_selector_term_convertToJSON(allowed_topologiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowed_topologies, itemLocal);
    }
    }
    }


    // v1_storage_class->api_version
    if(v1_storage_class->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_storage_class->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_storage_class->kind
    if(v1_storage_class->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_storage_class->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_storage_class->metadata
    if(v1_storage_class->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_storage_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_storage_class->mount_options
    if(v1_storage_class->mount_options) {
    cJSON *mount_options = cJSON_AddArrayToObject(item, "mountOptions");
    if(mount_options == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *mount_optionsListEntry;
    list_ForEach(mount_optionsListEntry, v1_storage_class->mount_options) {
    if(cJSON_AddStringToObject(mount_options, "", mount_optionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_storage_class->parameters
    if(v1_storage_class->parameters) {
    cJSON *parameters = cJSON_AddObjectToObject(item, "parameters");
    if(parameters == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = parameters;
    listEntry_t *parametersListEntry;
    if (v1_storage_class->parameters) {
    list_ForEach(parametersListEntry, v1_storage_class->parameters) {
        keyValuePair_t *localKeyValue = parametersListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_storage_class->provisioner
    if (!v1_storage_class->provisioner) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provisioner", v1_storage_class->provisioner) == NULL) {
    goto fail; //String
    }


    // v1_storage_class->reclaim_policy
    if(v1_storage_class->reclaim_policy) {
    if(cJSON_AddStringToObject(item, "reclaimPolicy", v1_storage_class->reclaim_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_storage_class->volume_binding_mode
    if(v1_storage_class->volume_binding_mode) {
    if(cJSON_AddStringToObject(item, "volumeBindingMode", v1_storage_class->volume_binding_mode) == NULL) {
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

v1_storage_class_t *v1_storage_class_parseFromJSON(cJSON *v1_storage_classJSON){

    v1_storage_class_t *v1_storage_class_local_var = NULL;

    // define the local list for v1_storage_class->allowed_topologies
    list_t *allowed_topologiesList = NULL;

    // define the local variable for v1_storage_class->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local list for v1_storage_class->mount_options
    list_t *mount_optionsList = NULL;

    // define the local map for v1_storage_class->parameters
    list_t *parametersList = NULL;

    // v1_storage_class->allow_volume_expansion
    cJSON *allow_volume_expansion = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "allowVolumeExpansion");
    if (cJSON_IsNull(allow_volume_expansion)) {
        allow_volume_expansion = NULL;
    }
    if (allow_volume_expansion) { 
    if(!cJSON_IsBool(allow_volume_expansion))
    {
    goto end; //Bool
    }
    }

    // v1_storage_class->allowed_topologies
    cJSON *allowed_topologies = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "allowedTopologies");
    if (cJSON_IsNull(allowed_topologies)) {
        allowed_topologies = NULL;
    }
    if (allowed_topologies) { 
    cJSON *allowed_topologies_local_nonprimitive = NULL;
    if(!cJSON_IsArray(allowed_topologies)){
        goto end; //nonprimitive container
    }

    allowed_topologiesList = list_createList();

    cJSON_ArrayForEach(allowed_topologies_local_nonprimitive,allowed_topologies )
    {
        if(!cJSON_IsObject(allowed_topologies_local_nonprimitive)){
            goto end;
        }
        v1_topology_selector_term_t *allowed_topologiesItem = v1_topology_selector_term_parseFromJSON(allowed_topologies_local_nonprimitive);

        list_addElement(allowed_topologiesList, allowed_topologiesItem);
    }
    }

    // v1_storage_class->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_storage_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_storage_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_storage_class->mount_options
    cJSON *mount_options = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "mountOptions");
    if (cJSON_IsNull(mount_options)) {
        mount_options = NULL;
    }
    if (mount_options) { 
    cJSON *mount_options_local = NULL;
    if(!cJSON_IsArray(mount_options)) {
        goto end;//primitive container
    }
    mount_optionsList = list_createList();

    cJSON_ArrayForEach(mount_options_local, mount_options)
    {
        if(!cJSON_IsString(mount_options_local))
        {
            goto end;
        }
        list_addElement(mount_optionsList , strdup(mount_options_local->valuestring));
    }
    }

    // v1_storage_class->parameters
    cJSON *parameters = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "parameters");
    if (cJSON_IsNull(parameters)) {
        parameters = NULL;
    }
    if (parameters) { 
    cJSON *parameters_local_map = NULL;
    if(!cJSON_IsObject(parameters) && !cJSON_IsNull(parameters))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(parameters))
    {
        parametersList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(parameters_local_map, parameters)
        {
            cJSON *localMapObject = parameters_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(parametersList , localMapKeyPair);
        }
    }
    }

    // v1_storage_class->provisioner
    cJSON *provisioner = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "provisioner");
    if (cJSON_IsNull(provisioner)) {
        provisioner = NULL;
    }
    if (!provisioner) {
        goto end;
    }

    
    if(!cJSON_IsString(provisioner))
    {
    goto end; //String
    }

    // v1_storage_class->reclaim_policy
    cJSON *reclaim_policy = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "reclaimPolicy");
    if (cJSON_IsNull(reclaim_policy)) {
        reclaim_policy = NULL;
    }
    if (reclaim_policy) { 
    if(!cJSON_IsString(reclaim_policy) && !cJSON_IsNull(reclaim_policy))
    {
    goto end; //String
    }
    }

    // v1_storage_class->volume_binding_mode
    cJSON *volume_binding_mode = cJSON_GetObjectItemCaseSensitive(v1_storage_classJSON, "volumeBindingMode");
    if (cJSON_IsNull(volume_binding_mode)) {
        volume_binding_mode = NULL;
    }
    if (volume_binding_mode) { 
    if(!cJSON_IsString(volume_binding_mode) && !cJSON_IsNull(volume_binding_mode))
    {
    goto end; //String
    }
    }


    v1_storage_class_local_var = v1_storage_class_create_internal (
        allow_volume_expansion ? allow_volume_expansion->valueint : 0,
        allowed_topologies ? allowed_topologiesList : NULL,
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        mount_options ? mount_optionsList : NULL,
        parameters ? parametersList : NULL,
        strdup(provisioner->valuestring),
        reclaim_policy && !cJSON_IsNull(reclaim_policy) ? strdup(reclaim_policy->valuestring) : NULL,
        volume_binding_mode && !cJSON_IsNull(volume_binding_mode) ? strdup(volume_binding_mode->valuestring) : NULL
        );

    return v1_storage_class_local_var;
end:
    if (allowed_topologiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_topologiesList) {
            v1_topology_selector_term_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_topologiesList);
        allowed_topologiesList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (mount_optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, mount_optionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(mount_optionsList);
        mount_optionsList = NULL;
    }
    if (parametersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, parametersList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(parametersList);
        parametersList = NULL;
    }
    return NULL;

}
