#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_validation.h"



static v1_custom_resource_validation_t *v1_custom_resource_validation_create_internal(
    v1_json_schema_props_t *open_apiv3_schema
    ) {
    v1_custom_resource_validation_t *v1_custom_resource_validation_local_var = malloc(sizeof(v1_custom_resource_validation_t));
    if (!v1_custom_resource_validation_local_var) {
        return NULL;
    }
    v1_custom_resource_validation_local_var->open_apiv3_schema = open_apiv3_schema;

    v1_custom_resource_validation_local_var->_library_owned = 1;
    return v1_custom_resource_validation_local_var;
}

__attribute__((deprecated)) v1_custom_resource_validation_t *v1_custom_resource_validation_create(
    v1_json_schema_props_t *open_apiv3_schema
    ) {
    return v1_custom_resource_validation_create_internal (
        open_apiv3_schema
        );
}

void v1_custom_resource_validation_free(v1_custom_resource_validation_t *v1_custom_resource_validation) {
    if(NULL == v1_custom_resource_validation){
        return ;
    }
    if(v1_custom_resource_validation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_custom_resource_validation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_validation->open_apiv3_schema) {
        v1_json_schema_props_free(v1_custom_resource_validation->open_apiv3_schema);
        v1_custom_resource_validation->open_apiv3_schema = NULL;
    }
    free(v1_custom_resource_validation);
}

cJSON *v1_custom_resource_validation_convertToJSON(v1_custom_resource_validation_t *v1_custom_resource_validation) {
    cJSON *item = cJSON_CreateObject();

    // v1_custom_resource_validation->open_apiv3_schema
    if(v1_custom_resource_validation->open_apiv3_schema) {
    cJSON *open_apiv3_schema_local_JSON = v1_json_schema_props_convertToJSON(v1_custom_resource_validation->open_apiv3_schema);
    if(open_apiv3_schema_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "openAPIV3Schema", open_apiv3_schema_local_JSON);
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

v1_custom_resource_validation_t *v1_custom_resource_validation_parseFromJSON(cJSON *v1_custom_resource_validationJSON){

    v1_custom_resource_validation_t *v1_custom_resource_validation_local_var = NULL;

    // define the local variable for v1_custom_resource_validation->open_apiv3_schema
    v1_json_schema_props_t *open_apiv3_schema_local_nonprim = NULL;

    // v1_custom_resource_validation->open_apiv3_schema
    cJSON *open_apiv3_schema = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_validationJSON, "openAPIV3Schema");
    if (cJSON_IsNull(open_apiv3_schema)) {
        open_apiv3_schema = NULL;
    }
    if (open_apiv3_schema) { 
    open_apiv3_schema_local_nonprim = v1_json_schema_props_parseFromJSON(open_apiv3_schema); //nonprimitive
    }


    v1_custom_resource_validation_local_var = v1_custom_resource_validation_create_internal (
        open_apiv3_schema ? open_apiv3_schema_local_nonprim : NULL
        );

    return v1_custom_resource_validation_local_var;
end:
    if (open_apiv3_schema_local_nonprim) {
        v1_json_schema_props_free(open_apiv3_schema_local_nonprim);
        open_apiv3_schema_local_nonprim = NULL;
    }
    return NULL;

}
