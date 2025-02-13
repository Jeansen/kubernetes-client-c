#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ceph_fs_persistent_volume_source.h"



static v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source_create_internal(
    list_t *monitors,
    char *path,
    int read_only,
    char *secret_file,
    v1_secret_reference_t *secret_ref,
    char *user
    ) {
    v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source_local_var = malloc(sizeof(v1_ceph_fs_persistent_volume_source_t));
    if (!v1_ceph_fs_persistent_volume_source_local_var) {
        return NULL;
    }
    v1_ceph_fs_persistent_volume_source_local_var->monitors = monitors;
    v1_ceph_fs_persistent_volume_source_local_var->path = path;
    v1_ceph_fs_persistent_volume_source_local_var->read_only = read_only;
    v1_ceph_fs_persistent_volume_source_local_var->secret_file = secret_file;
    v1_ceph_fs_persistent_volume_source_local_var->secret_ref = secret_ref;
    v1_ceph_fs_persistent_volume_source_local_var->user = user;

    v1_ceph_fs_persistent_volume_source_local_var->_library_owned = 1;
    return v1_ceph_fs_persistent_volume_source_local_var;
}

__attribute__((deprecated)) v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source_create(
    list_t *monitors,
    char *path,
    int read_only,
    char *secret_file,
    v1_secret_reference_t *secret_ref,
    char *user
    ) {
    return v1_ceph_fs_persistent_volume_source_create_internal (
        monitors,
        path,
        read_only,
        secret_file,
        secret_ref,
        user
        );
}

void v1_ceph_fs_persistent_volume_source_free(v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source) {
    if(NULL == v1_ceph_fs_persistent_volume_source){
        return ;
    }
    if(v1_ceph_fs_persistent_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ceph_fs_persistent_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ceph_fs_persistent_volume_source->monitors) {
        list_ForEach(listEntry, v1_ceph_fs_persistent_volume_source->monitors) {
            free(listEntry->data);
        }
        list_freeList(v1_ceph_fs_persistent_volume_source->monitors);
        v1_ceph_fs_persistent_volume_source->monitors = NULL;
    }
    if (v1_ceph_fs_persistent_volume_source->path) {
        free(v1_ceph_fs_persistent_volume_source->path);
        v1_ceph_fs_persistent_volume_source->path = NULL;
    }
    if (v1_ceph_fs_persistent_volume_source->secret_file) {
        free(v1_ceph_fs_persistent_volume_source->secret_file);
        v1_ceph_fs_persistent_volume_source->secret_file = NULL;
    }
    if (v1_ceph_fs_persistent_volume_source->secret_ref) {
        v1_secret_reference_free(v1_ceph_fs_persistent_volume_source->secret_ref);
        v1_ceph_fs_persistent_volume_source->secret_ref = NULL;
    }
    if (v1_ceph_fs_persistent_volume_source->user) {
        free(v1_ceph_fs_persistent_volume_source->user);
        v1_ceph_fs_persistent_volume_source->user = NULL;
    }
    free(v1_ceph_fs_persistent_volume_source);
}

cJSON *v1_ceph_fs_persistent_volume_source_convertToJSON(v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_ceph_fs_persistent_volume_source->monitors
    if (!v1_ceph_fs_persistent_volume_source->monitors) {
        goto fail;
    }
    cJSON *monitors = cJSON_AddArrayToObject(item, "monitors");
    if(monitors == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *monitorsListEntry;
    list_ForEach(monitorsListEntry, v1_ceph_fs_persistent_volume_source->monitors) {
    if(cJSON_AddStringToObject(monitors, "", monitorsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_ceph_fs_persistent_volume_source->path
    if(v1_ceph_fs_persistent_volume_source->path) {
    if(cJSON_AddStringToObject(item, "path", v1_ceph_fs_persistent_volume_source->path) == NULL) {
    goto fail; //String
    }
    }


    // v1_ceph_fs_persistent_volume_source->read_only
    if(v1_ceph_fs_persistent_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", v1_ceph_fs_persistent_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_ceph_fs_persistent_volume_source->secret_file
    if(v1_ceph_fs_persistent_volume_source->secret_file) {
    if(cJSON_AddStringToObject(item, "secretFile", v1_ceph_fs_persistent_volume_source->secret_file) == NULL) {
    goto fail; //String
    }
    }


    // v1_ceph_fs_persistent_volume_source->secret_ref
    if(v1_ceph_fs_persistent_volume_source->secret_ref) {
    cJSON *secret_ref_local_JSON = v1_secret_reference_convertToJSON(v1_ceph_fs_persistent_volume_source->secret_ref);
    if(secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_ceph_fs_persistent_volume_source->user
    if(v1_ceph_fs_persistent_volume_source->user) {
    if(cJSON_AddStringToObject(item, "user", v1_ceph_fs_persistent_volume_source->user) == NULL) {
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

v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source_parseFromJSON(cJSON *v1_ceph_fs_persistent_volume_sourceJSON){

    v1_ceph_fs_persistent_volume_source_t *v1_ceph_fs_persistent_volume_source_local_var = NULL;

    // define the local list for v1_ceph_fs_persistent_volume_source->monitors
    list_t *monitorsList = NULL;

    // define the local variable for v1_ceph_fs_persistent_volume_source->secret_ref
    v1_secret_reference_t *secret_ref_local_nonprim = NULL;

    // v1_ceph_fs_persistent_volume_source->monitors
    cJSON *monitors = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_persistent_volume_sourceJSON, "monitors");
    if (cJSON_IsNull(monitors)) {
        monitors = NULL;
    }
    if (!monitors) {
        goto end;
    }

    
    cJSON *monitors_local = NULL;
    if(!cJSON_IsArray(monitors)) {
        goto end;//primitive container
    }
    monitorsList = list_createList();

    cJSON_ArrayForEach(monitors_local, monitors)
    {
        if(!cJSON_IsString(monitors_local))
        {
            goto end;
        }
        list_addElement(monitorsList , strdup(monitors_local->valuestring));
    }

    // v1_ceph_fs_persistent_volume_source->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_persistent_volume_sourceJSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (path) { 
    if(!cJSON_IsString(path) && !cJSON_IsNull(path))
    {
    goto end; //String
    }
    }

    // v1_ceph_fs_persistent_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_persistent_volume_sourceJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_ceph_fs_persistent_volume_source->secret_file
    cJSON *secret_file = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_persistent_volume_sourceJSON, "secretFile");
    if (cJSON_IsNull(secret_file)) {
        secret_file = NULL;
    }
    if (secret_file) { 
    if(!cJSON_IsString(secret_file) && !cJSON_IsNull(secret_file))
    {
    goto end; //String
    }
    }

    // v1_ceph_fs_persistent_volume_source->secret_ref
    cJSON *secret_ref = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_persistent_volume_sourceJSON, "secretRef");
    if (cJSON_IsNull(secret_ref)) {
        secret_ref = NULL;
    }
    if (secret_ref) { 
    secret_ref_local_nonprim = v1_secret_reference_parseFromJSON(secret_ref); //nonprimitive
    }

    // v1_ceph_fs_persistent_volume_source->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_ceph_fs_persistent_volume_sourceJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    if(!cJSON_IsString(user) && !cJSON_IsNull(user))
    {
    goto end; //String
    }
    }


    v1_ceph_fs_persistent_volume_source_local_var = v1_ceph_fs_persistent_volume_source_create_internal (
        monitorsList,
        path && !cJSON_IsNull(path) ? strdup(path->valuestring) : NULL,
        read_only ? read_only->valueint : 0,
        secret_file && !cJSON_IsNull(secret_file) ? strdup(secret_file->valuestring) : NULL,
        secret_ref ? secret_ref_local_nonprim : NULL,
        user && !cJSON_IsNull(user) ? strdup(user->valuestring) : NULL
        );

    return v1_ceph_fs_persistent_volume_source_local_var;
end:
    if (monitorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, monitorsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(monitorsList);
        monitorsList = NULL;
    }
    if (secret_ref_local_nonprim) {
        v1_secret_reference_free(secret_ref_local_nonprim);
        secret_ref_local_nonprim = NULL;
    }
    return NULL;

}
