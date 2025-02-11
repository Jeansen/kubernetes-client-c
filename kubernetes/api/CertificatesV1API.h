#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/object.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_certificate_signing_request.h"
#include "../model/v1_certificate_signing_request_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"


// create a CertificateSigningRequest
//
v1_certificate_signing_request_t*
CertificatesV1API_createCertificateSigningRequest(apiClient_t *apiClient, v1_certificate_signing_request_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete a CertificateSigningRequest
//
v1_status_t*
CertificatesV1API_deleteCertificateSigningRequest(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete collection of CertificateSigningRequest
//
v1_status_t*
CertificatesV1API_deleteCollectionCertificateSigningRequest(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
CertificatesV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind CertificateSigningRequest
//
v1_certificate_signing_request_list_t*
CertificatesV1API_listCertificateSigningRequest(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified CertificateSigningRequest
//
v1_certificate_signing_request_t*
CertificatesV1API_patchCertificateSigningRequest(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update approval of the specified CertificateSigningRequest
//
v1_certificate_signing_request_t*
CertificatesV1API_patchCertificateSigningRequestApproval(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified CertificateSigningRequest
//
v1_certificate_signing_request_t*
CertificatesV1API_patchCertificateSigningRequestStatus(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified CertificateSigningRequest
//
v1_certificate_signing_request_t*
CertificatesV1API_readCertificateSigningRequest(apiClient_t *apiClient, char *name, char *pretty);


// read approval of the specified CertificateSigningRequest
//
v1_certificate_signing_request_t*
CertificatesV1API_readCertificateSigningRequestApproval(apiClient_t *apiClient, char *name, char *pretty);


// read status of the specified CertificateSigningRequest
//
v1_certificate_signing_request_t*
CertificatesV1API_readCertificateSigningRequestStatus(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified CertificateSigningRequest
//
v1_certificate_signing_request_t*
CertificatesV1API_replaceCertificateSigningRequest(apiClient_t *apiClient, char *name, v1_certificate_signing_request_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace approval of the specified CertificateSigningRequest
//
v1_certificate_signing_request_t*
CertificatesV1API_replaceCertificateSigningRequestApproval(apiClient_t *apiClient, char *name, v1_certificate_signing_request_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified CertificateSigningRequest
//
v1_certificate_signing_request_t*
CertificatesV1API_replaceCertificateSigningRequestStatus(apiClient_t *apiClient, char *name, v1_certificate_signing_request_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


