#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "CustomObjectsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Creates a cluster scoped Custom object
//
object_t*
CustomObjectsAPI_createClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);



    // query parameters
    char *keyQuery_pretty = NULL;
    char * valueQuery_pretty = NULL;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Created");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_pretty){
        free(keyQuery_pretty);
        keyQuery_pretty = NULL;
    }
    if(valueQuery_pretty){
        free(valueQuery_pretty);
        valueQuery_pretty = NULL;
    }
    if(keyPairQuery_pretty){
        keyValuePair_free(keyPairQuery_pretty);
        keyPairQuery_pretty = NULL;
    }
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Creates a namespace scoped Custom object
//
object_t*
CustomObjectsAPI_createNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);



    // query parameters
    char *keyQuery_pretty = NULL;
    char * valueQuery_pretty = NULL;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Created");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_pretty){
        free(keyQuery_pretty);
        keyQuery_pretty = NULL;
    }
    if(valueQuery_pretty){
        free(valueQuery_pretty);
        valueQuery_pretty = NULL;
    }
    if(keyPairQuery_pretty){
        keyValuePair_free(keyPairQuery_pretty);
        keyPairQuery_pretty = NULL;
    }
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Deletes the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_deleteClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, char *dryRun, v1_delete_options_t *body)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}/{name}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", *gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", *orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete collection of cluster scoped custom objects
//
object_t*
CustomObjectsAPI_deleteCollectionClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *pretty, char *labelSelector, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, char *dryRun, v1_delete_options_t *body)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);



    // query parameters
    char *keyQuery_pretty = NULL;
    char * valueQuery_pretty = NULL;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", *gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", *orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_pretty){
        free(keyQuery_pretty);
        keyQuery_pretty = NULL;
    }
    if(valueQuery_pretty){
        free(valueQuery_pretty);
        valueQuery_pretty = NULL;
    }
    if(keyPairQuery_pretty){
        keyValuePair_free(keyPairQuery_pretty);
        keyPairQuery_pretty = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete collection of namespace scoped custom objects
//
object_t*
CustomObjectsAPI_deleteCollectionNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *pretty, char *labelSelector, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, char *dryRun, char *fieldSelector, v1_delete_options_t *body)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);



    // query parameters
    char *keyQuery_pretty = NULL;
    char * valueQuery_pretty = NULL;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", *gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", *orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_pretty){
        free(keyQuery_pretty);
        keyQuery_pretty = NULL;
    }
    if(valueQuery_pretty){
        free(valueQuery_pretty);
        valueQuery_pretty = NULL;
    }
    if(keyPairQuery_pretty){
        keyValuePair_free(keyPairQuery_pretty);
        keyPairQuery_pretty = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Deletes the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_deleteNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, char *dryRun, v1_delete_options_t *body)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", *gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", *orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// get available resources
//
v1_api_resource_list_t*
CustomObjectsAPI_getAPIResources(apiClient_t *apiClient, char *group, char *version)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}");

    if(!group)
        goto end;
    if(!version)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    v1_api_resource_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = v1_api_resource_list_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns a cluster scoped custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}/{name}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","A single Resource");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// read scale of the specified custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *plural, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}/{name}/scale");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// read status of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *plural, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}/{name}/status");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns a namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","A single Resource");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// read scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// read status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch cluster scoped custom objects
//
object_t*
CustomObjectsAPI_listClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *timeoutSeconds, int *watch)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);



    // query parameters
    char *keyQuery_pretty = NULL;
    char * valueQuery_pretty = NULL;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", *allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_resourceVersionMatch = NULL;
    char * valueQuery_resourceVersionMatch = NULL;
    keyValuePair_t *keyPairQuery_resourceVersionMatch = 0;
    if (resourceVersionMatch)
    {
        keyQuery_resourceVersionMatch = strdup("resourceVersionMatch");
        valueQuery_resourceVersionMatch = strdup((resourceVersionMatch));
        keyPairQuery_resourceVersionMatch = keyValuePair_create(keyQuery_resourceVersionMatch, valueQuery_resourceVersionMatch);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersionMatch);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", *timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", *watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    if(keyQuery_pretty){
        free(keyQuery_pretty);
        keyQuery_pretty = NULL;
    }
    if(valueQuery_pretty){
        free(valueQuery_pretty);
        valueQuery_pretty = NULL;
    }
    if(keyPairQuery_pretty){
        keyValuePair_free(keyPairQuery_pretty);
        keyPairQuery_pretty = NULL;
    }
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_resourceVersionMatch){
        free(keyQuery_resourceVersionMatch);
        keyQuery_resourceVersionMatch = NULL;
    }
    if(valueQuery_resourceVersionMatch){
        free(valueQuery_resourceVersionMatch);
        valueQuery_resourceVersionMatch = NULL;
    }
    if(keyPairQuery_resourceVersionMatch){
        keyValuePair_free(keyPairQuery_resourceVersionMatch);
        keyPairQuery_resourceVersionMatch = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch namespace scoped custom objects
//
object_t*
CustomObjectsAPI_listCustomObjectForAllNamespaces(apiClient_t *apiClient, char *group, char *version, char *resource_plural, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *timeoutSeconds, int *watch)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{resource_plural}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!resource_plural)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(resource_plural)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(resource_plural)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_resource_plural = strlen(group)+3 + strlen(version)+3 + strlen(resource_plural)+3 + sizeof("{ resource_plural }") - 1;
    if(resource_plural == NULL) {
        goto end;
    }
    char* localVarToReplace_resource_plural = malloc(sizeOfPathParams_resource_plural);
    sprintf(localVarToReplace_resource_plural, "{%s}", "resource_plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_resource_plural, resource_plural);



    // query parameters
    char *keyQuery_pretty = NULL;
    char * valueQuery_pretty = NULL;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", *allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_resourceVersionMatch = NULL;
    char * valueQuery_resourceVersionMatch = NULL;
    keyValuePair_t *keyPairQuery_resourceVersionMatch = 0;
    if (resourceVersionMatch)
    {
        keyQuery_resourceVersionMatch = strdup("resourceVersionMatch");
        valueQuery_resourceVersionMatch = strdup((resourceVersionMatch));
        keyPairQuery_resourceVersionMatch = keyValuePair_create(keyQuery_resourceVersionMatch, valueQuery_resourceVersionMatch);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersionMatch);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", *timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", *watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_resource_plural);
    if(keyQuery_pretty){
        free(keyQuery_pretty);
        keyQuery_pretty = NULL;
    }
    if(valueQuery_pretty){
        free(valueQuery_pretty);
        valueQuery_pretty = NULL;
    }
    if(keyPairQuery_pretty){
        keyValuePair_free(keyPairQuery_pretty);
        keyPairQuery_pretty = NULL;
    }
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_resourceVersionMatch){
        free(keyQuery_resourceVersionMatch);
        keyQuery_resourceVersionMatch = NULL;
    }
    if(valueQuery_resourceVersionMatch){
        free(valueQuery_resourceVersionMatch);
        valueQuery_resourceVersionMatch = NULL;
    }
    if(keyPairQuery_resourceVersionMatch){
        keyValuePair_free(keyPairQuery_resourceVersionMatch);
        keyPairQuery_resourceVersionMatch = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch namespace scoped custom objects
//
object_t*
CustomObjectsAPI_listNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *timeoutSeconds, int *watch)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);



    // query parameters
    char *keyQuery_pretty = NULL;
    char * valueQuery_pretty = NULL;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", *allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_resourceVersionMatch = NULL;
    char * valueQuery_resourceVersionMatch = NULL;
    keyValuePair_t *keyPairQuery_resourceVersionMatch = 0;
    if (resourceVersionMatch)
    {
        keyQuery_resourceVersionMatch = strdup("resourceVersionMatch");
        valueQuery_resourceVersionMatch = strdup((resourceVersionMatch));
        keyPairQuery_resourceVersionMatch = keyValuePair_create(keyQuery_resourceVersionMatch, valueQuery_resourceVersionMatch);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersionMatch);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", *timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", *watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    if(keyQuery_pretty){
        free(keyQuery_pretty);
        keyQuery_pretty = NULL;
    }
    if(valueQuery_pretty){
        free(valueQuery_pretty);
        valueQuery_pretty = NULL;
    }
    if(keyPairQuery_pretty){
        keyValuePair_free(keyPairQuery_pretty);
        keyPairQuery_pretty = NULL;
    }
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_resourceVersionMatch){
        free(keyQuery_resourceVersionMatch);
        keyQuery_resourceVersionMatch = NULL;
    }
    if(valueQuery_resourceVersionMatch){
        free(valueQuery_resourceVersionMatch);
        valueQuery_resourceVersionMatch = NULL;
    }
    if(keyPairQuery_resourceVersionMatch){
        keyValuePair_free(keyPairQuery_resourceVersionMatch);
        keyPairQuery_resourceVersionMatch = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// patch the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}/{name}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // query parameters
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", *force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update scale of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}/{name}/scale");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // query parameters
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", *force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update status of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}/{name}/status");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // query parameters
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", *force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// patch the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // query parameters
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", *force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // query parameters
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", *force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // query parameters
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", *force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}/{name}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace scale of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}/{name}/scale");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Created");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace status of the cluster scoped specified custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/{plural}/{name}/status");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Created");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Created");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status");

    if(!group)
        goto end;
    if(!version)
        goto end;
    if(!_namespace)
        goto end;
    if(!plural)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ group }") - 1;
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ version }") - 1;
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams__namespace = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ namespace }") - 1;
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ plural }") - 1;
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(_namespace)+3 + strlen(plural)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_fieldValidation = NULL;
    char * valueQuery_fieldValidation = NULL;
    keyValuePair_t *keyPairQuery_fieldValidation = 0;
    if (fieldValidation)
    {
        keyQuery_fieldValidation = strdup("fieldValidation");
        valueQuery_fieldValidation = strdup((fieldValidation));
        keyPairQuery_fieldValidation = keyValuePair_create(keyQuery_fieldValidation, valueQuery_fieldValidation);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldValidation);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Created");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
        cJSON_Delete(CustomObjectsAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace__namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_fieldValidation){
        free(keyQuery_fieldValidation);
        keyQuery_fieldValidation = NULL;
    }
    if(valueQuery_fieldValidation){
        free(valueQuery_fieldValidation);
        valueQuery_fieldValidation = NULL;
    }
    if(keyPairQuery_fieldValidation){
        keyValuePair_free(keyPairQuery_fieldValidation);
        keyPairQuery_fieldValidation = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

