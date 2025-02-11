#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_service_spec.h"



static v1_api_service_spec_t *v1_api_service_spec_create_internal(
    char *ca_bundle,
    char *group,
    int group_priority_minimum,
    int insecure_skip_tls_verify,
    apiregistration_v1_service_reference_t *service,
    char *version,
    int version_priority
    ) {
    v1_api_service_spec_t *v1_api_service_spec_local_var = malloc(sizeof(v1_api_service_spec_t));
    if (!v1_api_service_spec_local_var) {
        return NULL;
    }
    v1_api_service_spec_local_var->ca_bundle = ca_bundle;
    v1_api_service_spec_local_var->group = group;
    v1_api_service_spec_local_var->group_priority_minimum = group_priority_minimum;
    v1_api_service_spec_local_var->insecure_skip_tls_verify = insecure_skip_tls_verify;
    v1_api_service_spec_local_var->service = service;
    v1_api_service_spec_local_var->version = version;
    v1_api_service_spec_local_var->version_priority = version_priority;

    v1_api_service_spec_local_var->_library_owned = 1;
    return v1_api_service_spec_local_var;
}

__attribute__((deprecated)) v1_api_service_spec_t *v1_api_service_spec_create(
    char *ca_bundle,
    char *group,
    int group_priority_minimum,
    int insecure_skip_tls_verify,
    apiregistration_v1_service_reference_t *service,
    char *version,
    int version_priority
    ) {
    return v1_api_service_spec_create_internal (
        ca_bundle,
        group,
        group_priority_minimum,
        insecure_skip_tls_verify,
        service,
        version,
        version_priority
        );
}

void v1_api_service_spec_free(v1_api_service_spec_t *v1_api_service_spec) {
    if(NULL == v1_api_service_spec){
        return ;
    }
    if(v1_api_service_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_api_service_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_api_service_spec->ca_bundle) {
        free(v1_api_service_spec->ca_bundle);
        v1_api_service_spec->ca_bundle = NULL;
    }
    if (v1_api_service_spec->group) {
        free(v1_api_service_spec->group);
        v1_api_service_spec->group = NULL;
    }
    if (v1_api_service_spec->service) {
        apiregistration_v1_service_reference_free(v1_api_service_spec->service);
        v1_api_service_spec->service = NULL;
    }
    if (v1_api_service_spec->version) {
        free(v1_api_service_spec->version);
        v1_api_service_spec->version = NULL;
    }
    free(v1_api_service_spec);
}

cJSON *v1_api_service_spec_convertToJSON(v1_api_service_spec_t *v1_api_service_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_api_service_spec->ca_bundle
    if(v1_api_service_spec->ca_bundle) {
    if(cJSON_AddStringToObject(item, "caBundle", v1_api_service_spec->ca_bundle) == NULL) {
    goto fail; //ByteArray
    }
    }


    // v1_api_service_spec->group
    if(v1_api_service_spec->group) {
    if(cJSON_AddStringToObject(item, "group", v1_api_service_spec->group) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_service_spec->group_priority_minimum
    if (!v1_api_service_spec->group_priority_minimum) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "groupPriorityMinimum", v1_api_service_spec->group_priority_minimum) == NULL) {
    goto fail; //Numeric
    }


    // v1_api_service_spec->insecure_skip_tls_verify
    if(v1_api_service_spec->insecure_skip_tls_verify) {
    if(cJSON_AddBoolToObject(item, "insecureSkipTLSVerify", v1_api_service_spec->insecure_skip_tls_verify) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_api_service_spec->service
    if(v1_api_service_spec->service) {
    cJSON *service_local_JSON = apiregistration_v1_service_reference_convertToJSON(v1_api_service_spec->service);
    if(service_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "service", service_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_api_service_spec->version
    if(v1_api_service_spec->version) {
    if(cJSON_AddStringToObject(item, "version", v1_api_service_spec->version) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_service_spec->version_priority
    if (!v1_api_service_spec->version_priority) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "versionPriority", v1_api_service_spec->version_priority) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_api_service_spec_t *v1_api_service_spec_parseFromJSON(cJSON *v1_api_service_specJSON){

    v1_api_service_spec_t *v1_api_service_spec_local_var = NULL;

    // define the local variable for v1_api_service_spec->service
    apiregistration_v1_service_reference_t *service_local_nonprim = NULL;

    // v1_api_service_spec->ca_bundle
    cJSON *ca_bundle = cJSON_GetObjectItemCaseSensitive(v1_api_service_specJSON, "caBundle");
    if (cJSON_IsNull(ca_bundle)) {
        ca_bundle = NULL;
    }
    if (ca_bundle) { 
    if(!cJSON_IsString(ca_bundle))
    {
    goto end; //ByteArray
    }
    }

    // v1_api_service_spec->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1_api_service_specJSON, "group");
    if (cJSON_IsNull(group)) {
        group = NULL;
    }
    if (group) { 
    if(!cJSON_IsString(group) && !cJSON_IsNull(group))
    {
    goto end; //String
    }
    }

    // v1_api_service_spec->group_priority_minimum
    cJSON *group_priority_minimum = cJSON_GetObjectItemCaseSensitive(v1_api_service_specJSON, "groupPriorityMinimum");
    if (cJSON_IsNull(group_priority_minimum)) {
        group_priority_minimum = NULL;
    }
    if (!group_priority_minimum) {
        goto end;
    }

    
    if(!cJSON_IsNumber(group_priority_minimum))
    {
    goto end; //Numeric
    }

    // v1_api_service_spec->insecure_skip_tls_verify
    cJSON *insecure_skip_tls_verify = cJSON_GetObjectItemCaseSensitive(v1_api_service_specJSON, "insecureSkipTLSVerify");
    if (cJSON_IsNull(insecure_skip_tls_verify)) {
        insecure_skip_tls_verify = NULL;
    }
    if (insecure_skip_tls_verify) { 
    if(!cJSON_IsBool(insecure_skip_tls_verify))
    {
    goto end; //Bool
    }
    }

    // v1_api_service_spec->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(v1_api_service_specJSON, "service");
    if (cJSON_IsNull(service)) {
        service = NULL;
    }
    if (service) { 
    service_local_nonprim = apiregistration_v1_service_reference_parseFromJSON(service); //nonprimitive
    }

    // v1_api_service_spec->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1_api_service_specJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // v1_api_service_spec->version_priority
    cJSON *version_priority = cJSON_GetObjectItemCaseSensitive(v1_api_service_specJSON, "versionPriority");
    if (cJSON_IsNull(version_priority)) {
        version_priority = NULL;
    }
    if (!version_priority) {
        goto end;
    }

    
    if(!cJSON_IsNumber(version_priority))
    {
    goto end; //Numeric
    }


    v1_api_service_spec_local_var = v1_api_service_spec_create_internal (
        ca_bundle ? strdup(ca_bundle->valuestring) : NULL,
        group && !cJSON_IsNull(group) ? strdup(group->valuestring) : NULL,
        group_priority_minimum->valuedouble,
        insecure_skip_tls_verify ? insecure_skip_tls_verify->valueint : 0,
        service ? service_local_nonprim : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL,
        version_priority->valuedouble
        );

    return v1_api_service_spec_local_var;
end:
    if (service_local_nonprim) {
        apiregistration_v1_service_reference_free(service_local_nonprim);
        service_local_nonprim = NULL;
    }
    return NULL;

}
