#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_rule.h"



static v1_ingress_rule_t *v1_ingress_rule_create_internal(
    char *host,
    v1_http_ingress_rule_value_t *http
    ) {
    v1_ingress_rule_t *v1_ingress_rule_local_var = malloc(sizeof(v1_ingress_rule_t));
    if (!v1_ingress_rule_local_var) {
        return NULL;
    }
    v1_ingress_rule_local_var->host = host;
    v1_ingress_rule_local_var->http = http;

    v1_ingress_rule_local_var->_library_owned = 1;
    return v1_ingress_rule_local_var;
}

__attribute__((deprecated)) v1_ingress_rule_t *v1_ingress_rule_create(
    char *host,
    v1_http_ingress_rule_value_t *http
    ) {
    return v1_ingress_rule_create_internal (
        host,
        http
        );
}

void v1_ingress_rule_free(v1_ingress_rule_t *v1_ingress_rule) {
    if(NULL == v1_ingress_rule){
        return ;
    }
    if(v1_ingress_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ingress_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_rule->host) {
        free(v1_ingress_rule->host);
        v1_ingress_rule->host = NULL;
    }
    if (v1_ingress_rule->http) {
        v1_http_ingress_rule_value_free(v1_ingress_rule->http);
        v1_ingress_rule->http = NULL;
    }
    free(v1_ingress_rule);
}

cJSON *v1_ingress_rule_convertToJSON(v1_ingress_rule_t *v1_ingress_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_rule->host
    if(v1_ingress_rule->host) {
    if(cJSON_AddStringToObject(item, "host", v1_ingress_rule->host) == NULL) {
    goto fail; //String
    }
    }


    // v1_ingress_rule->http
    if(v1_ingress_rule->http) {
    cJSON *http_local_JSON = v1_http_ingress_rule_value_convertToJSON(v1_ingress_rule->http);
    if(http_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "http", http_local_JSON);
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

v1_ingress_rule_t *v1_ingress_rule_parseFromJSON(cJSON *v1_ingress_ruleJSON){

    v1_ingress_rule_t *v1_ingress_rule_local_var = NULL;

    // define the local variable for v1_ingress_rule->http
    v1_http_ingress_rule_value_t *http_local_nonprim = NULL;

    // v1_ingress_rule->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(v1_ingress_ruleJSON, "host");
    if (cJSON_IsNull(host)) {
        host = NULL;
    }
    if (host) { 
    if(!cJSON_IsString(host) && !cJSON_IsNull(host))
    {
    goto end; //String
    }
    }

    // v1_ingress_rule->http
    cJSON *http = cJSON_GetObjectItemCaseSensitive(v1_ingress_ruleJSON, "http");
    if (cJSON_IsNull(http)) {
        http = NULL;
    }
    if (http) { 
    http_local_nonprim = v1_http_ingress_rule_value_parseFromJSON(http); //nonprimitive
    }


    v1_ingress_rule_local_var = v1_ingress_rule_create_internal (
        host && !cJSON_IsNull(host) ? strdup(host->valuestring) : NULL,
        http ? http_local_nonprim : NULL
        );

    return v1_ingress_rule_local_var;
end:
    if (http_local_nonprim) {
        v1_http_ingress_rule_value_free(http_local_nonprim);
        http_local_nonprim = NULL;
    }
    return NULL;

}
