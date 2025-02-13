#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_git_repo_volume_source.h"



static v1_git_repo_volume_source_t *v1_git_repo_volume_source_create_internal(
    char *directory,
    char *repository,
    char *revision
    ) {
    v1_git_repo_volume_source_t *v1_git_repo_volume_source_local_var = malloc(sizeof(v1_git_repo_volume_source_t));
    if (!v1_git_repo_volume_source_local_var) {
        return NULL;
    }
    v1_git_repo_volume_source_local_var->directory = directory;
    v1_git_repo_volume_source_local_var->repository = repository;
    v1_git_repo_volume_source_local_var->revision = revision;

    v1_git_repo_volume_source_local_var->_library_owned = 1;
    return v1_git_repo_volume_source_local_var;
}

__attribute__((deprecated)) v1_git_repo_volume_source_t *v1_git_repo_volume_source_create(
    char *directory,
    char *repository,
    char *revision
    ) {
    return v1_git_repo_volume_source_create_internal (
        directory,
        repository,
        revision
        );
}

void v1_git_repo_volume_source_free(v1_git_repo_volume_source_t *v1_git_repo_volume_source) {
    if(NULL == v1_git_repo_volume_source){
        return ;
    }
    if(v1_git_repo_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_git_repo_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_git_repo_volume_source->directory) {
        free(v1_git_repo_volume_source->directory);
        v1_git_repo_volume_source->directory = NULL;
    }
    if (v1_git_repo_volume_source->repository) {
        free(v1_git_repo_volume_source->repository);
        v1_git_repo_volume_source->repository = NULL;
    }
    if (v1_git_repo_volume_source->revision) {
        free(v1_git_repo_volume_source->revision);
        v1_git_repo_volume_source->revision = NULL;
    }
    free(v1_git_repo_volume_source);
}

cJSON *v1_git_repo_volume_source_convertToJSON(v1_git_repo_volume_source_t *v1_git_repo_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_git_repo_volume_source->directory
    if(v1_git_repo_volume_source->directory) {
    if(cJSON_AddStringToObject(item, "directory", v1_git_repo_volume_source->directory) == NULL) {
    goto fail; //String
    }
    }


    // v1_git_repo_volume_source->repository
    if (!v1_git_repo_volume_source->repository) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "repository", v1_git_repo_volume_source->repository) == NULL) {
    goto fail; //String
    }


    // v1_git_repo_volume_source->revision
    if(v1_git_repo_volume_source->revision) {
    if(cJSON_AddStringToObject(item, "revision", v1_git_repo_volume_source->revision) == NULL) {
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

v1_git_repo_volume_source_t *v1_git_repo_volume_source_parseFromJSON(cJSON *v1_git_repo_volume_sourceJSON){

    v1_git_repo_volume_source_t *v1_git_repo_volume_source_local_var = NULL;

    // v1_git_repo_volume_source->directory
    cJSON *directory = cJSON_GetObjectItemCaseSensitive(v1_git_repo_volume_sourceJSON, "directory");
    if (cJSON_IsNull(directory)) {
        directory = NULL;
    }
    if (directory) { 
    if(!cJSON_IsString(directory) && !cJSON_IsNull(directory))
    {
    goto end; //String
    }
    }

    // v1_git_repo_volume_source->repository
    cJSON *repository = cJSON_GetObjectItemCaseSensitive(v1_git_repo_volume_sourceJSON, "repository");
    if (cJSON_IsNull(repository)) {
        repository = NULL;
    }
    if (!repository) {
        goto end;
    }

    
    if(!cJSON_IsString(repository))
    {
    goto end; //String
    }

    // v1_git_repo_volume_source->revision
    cJSON *revision = cJSON_GetObjectItemCaseSensitive(v1_git_repo_volume_sourceJSON, "revision");
    if (cJSON_IsNull(revision)) {
        revision = NULL;
    }
    if (revision) { 
    if(!cJSON_IsString(revision) && !cJSON_IsNull(revision))
    {
    goto end; //String
    }
    }


    v1_git_repo_volume_source_local_var = v1_git_repo_volume_source_create_internal (
        directory && !cJSON_IsNull(directory) ? strdup(directory->valuestring) : NULL,
        strdup(repository->valuestring),
        revision && !cJSON_IsNull(revision) ? strdup(revision->valuestring) : NULL
        );

    return v1_git_repo_volume_source_local_var;
end:
    return NULL;

}
