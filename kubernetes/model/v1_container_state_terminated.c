#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_state_terminated.h"



static v1_container_state_terminated_t *v1_container_state_terminated_create_internal(
    char *container_id,
    int exit_code,
    char *finished_at,
    char *message,
    char *reason,
    int signal,
    char *started_at
    ) {
    v1_container_state_terminated_t *v1_container_state_terminated_local_var = malloc(sizeof(v1_container_state_terminated_t));
    if (!v1_container_state_terminated_local_var) {
        return NULL;
    }
    v1_container_state_terminated_local_var->container_id = container_id;
    v1_container_state_terminated_local_var->exit_code = exit_code;
    v1_container_state_terminated_local_var->finished_at = finished_at;
    v1_container_state_terminated_local_var->message = message;
    v1_container_state_terminated_local_var->reason = reason;
    v1_container_state_terminated_local_var->signal = signal;
    v1_container_state_terminated_local_var->started_at = started_at;

    v1_container_state_terminated_local_var->_library_owned = 1;
    return v1_container_state_terminated_local_var;
}

__attribute__((deprecated)) v1_container_state_terminated_t *v1_container_state_terminated_create(
    char *container_id,
    int exit_code,
    char *finished_at,
    char *message,
    char *reason,
    int signal,
    char *started_at
    ) {
    return v1_container_state_terminated_create_internal (
        container_id,
        exit_code,
        finished_at,
        message,
        reason,
        signal,
        started_at
        );
}

void v1_container_state_terminated_free(v1_container_state_terminated_t *v1_container_state_terminated) {
    if(NULL == v1_container_state_terminated){
        return ;
    }
    if(v1_container_state_terminated->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_container_state_terminated_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_state_terminated->container_id) {
        free(v1_container_state_terminated->container_id);
        v1_container_state_terminated->container_id = NULL;
    }
    if (v1_container_state_terminated->finished_at) {
        free(v1_container_state_terminated->finished_at);
        v1_container_state_terminated->finished_at = NULL;
    }
    if (v1_container_state_terminated->message) {
        free(v1_container_state_terminated->message);
        v1_container_state_terminated->message = NULL;
    }
    if (v1_container_state_terminated->reason) {
        free(v1_container_state_terminated->reason);
        v1_container_state_terminated->reason = NULL;
    }
    if (v1_container_state_terminated->started_at) {
        free(v1_container_state_terminated->started_at);
        v1_container_state_terminated->started_at = NULL;
    }
    free(v1_container_state_terminated);
}

cJSON *v1_container_state_terminated_convertToJSON(v1_container_state_terminated_t *v1_container_state_terminated) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_state_terminated->container_id
    if(v1_container_state_terminated->container_id) {
    if(cJSON_AddStringToObject(item, "containerID", v1_container_state_terminated->container_id) == NULL) {
    goto fail; //String
    }
    }


    // v1_container_state_terminated->exit_code
    if (!v1_container_state_terminated->exit_code) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "exitCode", v1_container_state_terminated->exit_code) == NULL) {
    goto fail; //Numeric
    }


    // v1_container_state_terminated->finished_at
    if(v1_container_state_terminated->finished_at) {
    if(cJSON_AddStringToObject(item, "finishedAt", v1_container_state_terminated->finished_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_container_state_terminated->message
    if(v1_container_state_terminated->message) {
    if(cJSON_AddStringToObject(item, "message", v1_container_state_terminated->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_container_state_terminated->reason
    if(v1_container_state_terminated->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_container_state_terminated->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1_container_state_terminated->signal
    if(v1_container_state_terminated->signal) {
    if(cJSON_AddNumberToObject(item, "signal", v1_container_state_terminated->signal) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_container_state_terminated->started_at
    if(v1_container_state_terminated->started_at) {
    if(cJSON_AddStringToObject(item, "startedAt", v1_container_state_terminated->started_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_container_state_terminated_t *v1_container_state_terminated_parseFromJSON(cJSON *v1_container_state_terminatedJSON){

    v1_container_state_terminated_t *v1_container_state_terminated_local_var = NULL;

    // v1_container_state_terminated->container_id
    cJSON *container_id = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "containerID");
    if (cJSON_IsNull(container_id)) {
        container_id = NULL;
    }
    if (container_id) { 
    if(!cJSON_IsString(container_id) && !cJSON_IsNull(container_id))
    {
    goto end; //String
    }
    }

    // v1_container_state_terminated->exit_code
    cJSON *exit_code = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "exitCode");
    if (cJSON_IsNull(exit_code)) {
        exit_code = NULL;
    }
    if (!exit_code) {
        goto end;
    }

    
    if(!cJSON_IsNumber(exit_code))
    {
    goto end; //Numeric
    }

    // v1_container_state_terminated->finished_at
    cJSON *finished_at = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "finishedAt");
    if (cJSON_IsNull(finished_at)) {
        finished_at = NULL;
    }
    if (finished_at) { 
    if(!cJSON_IsString(finished_at) && !cJSON_IsNull(finished_at))
    {
    goto end; //DateTime
    }
    }

    // v1_container_state_terminated->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_container_state_terminated->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1_container_state_terminated->signal
    cJSON *signal = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "signal");
    if (cJSON_IsNull(signal)) {
        signal = NULL;
    }
    if (signal) { 
    if(!cJSON_IsNumber(signal))
    {
    goto end; //Numeric
    }
    }

    // v1_container_state_terminated->started_at
    cJSON *started_at = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "startedAt");
    if (cJSON_IsNull(started_at)) {
        started_at = NULL;
    }
    if (started_at) { 
    if(!cJSON_IsString(started_at) && !cJSON_IsNull(started_at))
    {
    goto end; //DateTime
    }
    }


    v1_container_state_terminated_local_var = v1_container_state_terminated_create_internal (
        container_id && !cJSON_IsNull(container_id) ? strdup(container_id->valuestring) : NULL,
        exit_code->valuedouble,
        finished_at && !cJSON_IsNull(finished_at) ? strdup(finished_at->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        signal ? signal->valuedouble : 0,
        started_at && !cJSON_IsNull(started_at) ? strdup(started_at->valuestring) : NULL
        );

    return v1_container_state_terminated_local_var;
end:
    return NULL;

}
