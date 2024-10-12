#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/object.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_runtime_class.h"
#include "../model/v1_runtime_class_list.h"
#include "../model/v1_status.h"


// create a RuntimeClass
//
v1_runtime_class_t*
NodeV1API_createRuntimeClass(apiClient_t *apiClient, v1_runtime_class_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of RuntimeClass
//
v1_status_t*
NodeV1API_deleteCollectionRuntimeClass(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a RuntimeClass
//
v1_status_t*
NodeV1API_deleteRuntimeClass(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
NodeV1API_getAPIResources_24(apiClient_t *apiClient);


// list or watch objects of kind RuntimeClass
//
v1_runtime_class_list_t*
NodeV1API_listRuntimeClass(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified RuntimeClass
//
v1_runtime_class_t*
NodeV1API_patchRuntimeClass(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified RuntimeClass
//
v1_runtime_class_t*
NodeV1API_readRuntimeClass(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified RuntimeClass
//
v1_runtime_class_t*
NodeV1API_replaceRuntimeClass(apiClient_t *apiClient, char *name, v1_runtime_class_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


