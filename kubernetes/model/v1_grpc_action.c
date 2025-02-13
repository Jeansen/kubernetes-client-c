#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_grpc_action.h"



static v1_grpc_action_t *v1_grpc_action_create_internal(
    int port,
    char *service
    ) {
    v1_grpc_action_t *v1_grpc_action_local_var = malloc(sizeof(v1_grpc_action_t));
    if (!v1_grpc_action_local_var) {
        return NULL;
    }
    v1_grpc_action_local_var->port = port;
    v1_grpc_action_local_var->service = service;

    v1_grpc_action_local_var->_library_owned = 1;
    return v1_grpc_action_local_var;
}

__attribute__((deprecated)) v1_grpc_action_t *v1_grpc_action_create(
    int port,
    char *service
    ) {
    return v1_grpc_action_create_internal (
        port,
        service
        );
}

void v1_grpc_action_free(v1_grpc_action_t *v1_grpc_action) {
    if(NULL == v1_grpc_action){
        return ;
    }
    if(v1_grpc_action->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_grpc_action_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_grpc_action->service) {
        free(v1_grpc_action->service);
        v1_grpc_action->service = NULL;
    }
    free(v1_grpc_action);
}

cJSON *v1_grpc_action_convertToJSON(v1_grpc_action_t *v1_grpc_action) {
    cJSON *item = cJSON_CreateObject();

    // v1_grpc_action->port
    if (!v1_grpc_action->port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "port", v1_grpc_action->port) == NULL) {
    goto fail; //Numeric
    }


    // v1_grpc_action->service
    if(v1_grpc_action->service) {
    if(cJSON_AddStringToObject(item, "service", v1_grpc_action->service) == NULL) {
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

v1_grpc_action_t *v1_grpc_action_parseFromJSON(cJSON *v1_grpc_actionJSON){

    v1_grpc_action_t *v1_grpc_action_local_var = NULL;

    // v1_grpc_action->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_grpc_actionJSON, "port");
    if (cJSON_IsNull(port)) {
        port = NULL;
    }
    if (!port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }

    // v1_grpc_action->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(v1_grpc_actionJSON, "service");
    if (cJSON_IsNull(service)) {
        service = NULL;
    }
    if (service) { 
    if(!cJSON_IsString(service) && !cJSON_IsNull(service))
    {
    goto end; //String
    }
    }


    v1_grpc_action_local_var = v1_grpc_action_create_internal (
        port->valuedouble,
        service && !cJSON_IsNull(service) ? strdup(service->valuestring) : NULL
        );

    return v1_grpc_action_local_var;
end:
    return NULL;

}
