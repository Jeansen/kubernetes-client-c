#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_probe.h"



static v1_probe_t *v1_probe_create_internal(
    v1_exec_action_t *exec,
    int failure_threshold,
    v1_grpc_action_t *grpc,
    v1_http_get_action_t *http_get,
    int initial_delay_seconds,
    int period_seconds,
    int success_threshold,
    v1_tcp_socket_action_t *tcp_socket,
    long termination_grace_period_seconds,
    int timeout_seconds
    ) {
    v1_probe_t *v1_probe_local_var = malloc(sizeof(v1_probe_t));
    if (!v1_probe_local_var) {
        return NULL;
    }
    v1_probe_local_var->exec = exec;
    v1_probe_local_var->failure_threshold = failure_threshold;
    v1_probe_local_var->grpc = grpc;
    v1_probe_local_var->http_get = http_get;
    v1_probe_local_var->initial_delay_seconds = initial_delay_seconds;
    v1_probe_local_var->period_seconds = period_seconds;
    v1_probe_local_var->success_threshold = success_threshold;
    v1_probe_local_var->tcp_socket = tcp_socket;
    v1_probe_local_var->termination_grace_period_seconds = termination_grace_period_seconds;
    v1_probe_local_var->timeout_seconds = timeout_seconds;

    v1_probe_local_var->_library_owned = 1;
    return v1_probe_local_var;
}

__attribute__((deprecated)) v1_probe_t *v1_probe_create(
    v1_exec_action_t *exec,
    int failure_threshold,
    v1_grpc_action_t *grpc,
    v1_http_get_action_t *http_get,
    int initial_delay_seconds,
    int period_seconds,
    int success_threshold,
    v1_tcp_socket_action_t *tcp_socket,
    long termination_grace_period_seconds,
    int timeout_seconds
    ) {
    return v1_probe_create_internal (
        exec,
        failure_threshold,
        grpc,
        http_get,
        initial_delay_seconds,
        period_seconds,
        success_threshold,
        tcp_socket,
        termination_grace_period_seconds,
        timeout_seconds
        );
}

void v1_probe_free(v1_probe_t *v1_probe) {
    if(NULL == v1_probe){
        return ;
    }
    if(v1_probe->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_probe_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_probe->exec) {
        v1_exec_action_free(v1_probe->exec);
        v1_probe->exec = NULL;
    }
    if (v1_probe->grpc) {
        v1_grpc_action_free(v1_probe->grpc);
        v1_probe->grpc = NULL;
    }
    if (v1_probe->http_get) {
        v1_http_get_action_free(v1_probe->http_get);
        v1_probe->http_get = NULL;
    }
    if (v1_probe->tcp_socket) {
        v1_tcp_socket_action_free(v1_probe->tcp_socket);
        v1_probe->tcp_socket = NULL;
    }
    free(v1_probe);
}

cJSON *v1_probe_convertToJSON(v1_probe_t *v1_probe) {
    cJSON *item = cJSON_CreateObject();

    // v1_probe->exec
    if(v1_probe->exec) {
    cJSON *exec_local_JSON = v1_exec_action_convertToJSON(v1_probe->exec);
    if(exec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "exec", exec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_probe->failure_threshold
    if(v1_probe->failure_threshold) {
    if(cJSON_AddNumberToObject(item, "failureThreshold", v1_probe->failure_threshold) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_probe->grpc
    if(v1_probe->grpc) {
    cJSON *grpc_local_JSON = v1_grpc_action_convertToJSON(v1_probe->grpc);
    if(grpc_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "grpc", grpc_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_probe->http_get
    if(v1_probe->http_get) {
    cJSON *http_get_local_JSON = v1_http_get_action_convertToJSON(v1_probe->http_get);
    if(http_get_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "httpGet", http_get_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_probe->initial_delay_seconds
    if(v1_probe->initial_delay_seconds) {
    if(cJSON_AddNumberToObject(item, "initialDelaySeconds", v1_probe->initial_delay_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_probe->period_seconds
    if(v1_probe->period_seconds) {
    if(cJSON_AddNumberToObject(item, "periodSeconds", v1_probe->period_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_probe->success_threshold
    if(v1_probe->success_threshold) {
    if(cJSON_AddNumberToObject(item, "successThreshold", v1_probe->success_threshold) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_probe->tcp_socket
    if(v1_probe->tcp_socket) {
    cJSON *tcp_socket_local_JSON = v1_tcp_socket_action_convertToJSON(v1_probe->tcp_socket);
    if(tcp_socket_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "tcpSocket", tcp_socket_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_probe->termination_grace_period_seconds
    if(v1_probe->termination_grace_period_seconds) {
    if(cJSON_AddNumberToObject(item, "terminationGracePeriodSeconds", v1_probe->termination_grace_period_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_probe->timeout_seconds
    if(v1_probe->timeout_seconds) {
    if(cJSON_AddNumberToObject(item, "timeoutSeconds", v1_probe->timeout_seconds) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_probe_t *v1_probe_parseFromJSON(cJSON *v1_probeJSON){

    v1_probe_t *v1_probe_local_var = NULL;

    // define the local variable for v1_probe->exec
    v1_exec_action_t *exec_local_nonprim = NULL;

    // define the local variable for v1_probe->grpc
    v1_grpc_action_t *grpc_local_nonprim = NULL;

    // define the local variable for v1_probe->http_get
    v1_http_get_action_t *http_get_local_nonprim = NULL;

    // define the local variable for v1_probe->tcp_socket
    v1_tcp_socket_action_t *tcp_socket_local_nonprim = NULL;

    // v1_probe->exec
    cJSON *exec = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "exec");
    if (cJSON_IsNull(exec)) {
        exec = NULL;
    }
    if (exec) { 
    exec_local_nonprim = v1_exec_action_parseFromJSON(exec); //nonprimitive
    }

    // v1_probe->failure_threshold
    cJSON *failure_threshold = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "failureThreshold");
    if (cJSON_IsNull(failure_threshold)) {
        failure_threshold = NULL;
    }
    if (failure_threshold) { 
    if(!cJSON_IsNumber(failure_threshold))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->grpc
    cJSON *grpc = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "grpc");
    if (cJSON_IsNull(grpc)) {
        grpc = NULL;
    }
    if (grpc) { 
    grpc_local_nonprim = v1_grpc_action_parseFromJSON(grpc); //nonprimitive
    }

    // v1_probe->http_get
    cJSON *http_get = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "httpGet");
    if (cJSON_IsNull(http_get)) {
        http_get = NULL;
    }
    if (http_get) { 
    http_get_local_nonprim = v1_http_get_action_parseFromJSON(http_get); //nonprimitive
    }

    // v1_probe->initial_delay_seconds
    cJSON *initial_delay_seconds = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "initialDelaySeconds");
    if (cJSON_IsNull(initial_delay_seconds)) {
        initial_delay_seconds = NULL;
    }
    if (initial_delay_seconds) { 
    if(!cJSON_IsNumber(initial_delay_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->period_seconds
    cJSON *period_seconds = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "periodSeconds");
    if (cJSON_IsNull(period_seconds)) {
        period_seconds = NULL;
    }
    if (period_seconds) { 
    if(!cJSON_IsNumber(period_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->success_threshold
    cJSON *success_threshold = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "successThreshold");
    if (cJSON_IsNull(success_threshold)) {
        success_threshold = NULL;
    }
    if (success_threshold) { 
    if(!cJSON_IsNumber(success_threshold))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->tcp_socket
    cJSON *tcp_socket = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "tcpSocket");
    if (cJSON_IsNull(tcp_socket)) {
        tcp_socket = NULL;
    }
    if (tcp_socket) { 
    tcp_socket_local_nonprim = v1_tcp_socket_action_parseFromJSON(tcp_socket); //nonprimitive
    }

    // v1_probe->termination_grace_period_seconds
    cJSON *termination_grace_period_seconds = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "terminationGracePeriodSeconds");
    if (cJSON_IsNull(termination_grace_period_seconds)) {
        termination_grace_period_seconds = NULL;
    }
    if (termination_grace_period_seconds) { 
    if(!cJSON_IsNumber(termination_grace_period_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_probe->timeout_seconds
    cJSON *timeout_seconds = cJSON_GetObjectItemCaseSensitive(v1_probeJSON, "timeoutSeconds");
    if (cJSON_IsNull(timeout_seconds)) {
        timeout_seconds = NULL;
    }
    if (timeout_seconds) { 
    if(!cJSON_IsNumber(timeout_seconds))
    {
    goto end; //Numeric
    }
    }


    v1_probe_local_var = v1_probe_create_internal (
        exec ? exec_local_nonprim : NULL,
        failure_threshold ? failure_threshold->valuedouble : 0,
        grpc ? grpc_local_nonprim : NULL,
        http_get ? http_get_local_nonprim : NULL,
        initial_delay_seconds ? initial_delay_seconds->valuedouble : 0,
        period_seconds ? period_seconds->valuedouble : 0,
        success_threshold ? success_threshold->valuedouble : 0,
        tcp_socket ? tcp_socket_local_nonprim : NULL,
        termination_grace_period_seconds ? termination_grace_period_seconds->valuedouble : 0,
        timeout_seconds ? timeout_seconds->valuedouble : 0
        );

    return v1_probe_local_var;
end:
    if (exec_local_nonprim) {
        v1_exec_action_free(exec_local_nonprim);
        exec_local_nonprim = NULL;
    }
    if (grpc_local_nonprim) {
        v1_grpc_action_free(grpc_local_nonprim);
        grpc_local_nonprim = NULL;
    }
    if (http_get_local_nonprim) {
        v1_http_get_action_free(http_get_local_nonprim);
        http_get_local_nonprim = NULL;
    }
    if (tcp_socket_local_nonprim) {
        v1_tcp_socket_action_free(tcp_socket_local_nonprim);
        tcp_socket_local_nonprim = NULL;
    }
    return NULL;

}
