#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_json_patch.h"



static v1alpha1_json_patch_t *v1alpha1_json_patch_create_internal(
    char *expression
    ) {
    v1alpha1_json_patch_t *v1alpha1_json_patch_local_var = malloc(sizeof(v1alpha1_json_patch_t));
    if (!v1alpha1_json_patch_local_var) {
        return NULL;
    }
    v1alpha1_json_patch_local_var->expression = expression;

    v1alpha1_json_patch_local_var->_library_owned = 1;
    return v1alpha1_json_patch_local_var;
}

__attribute__((deprecated)) v1alpha1_json_patch_t *v1alpha1_json_patch_create(
    char *expression
    ) {
    return v1alpha1_json_patch_create_internal (
        expression
        );
}

void v1alpha1_json_patch_free(v1alpha1_json_patch_t *v1alpha1_json_patch) {
    if(NULL == v1alpha1_json_patch){
        return ;
    }
    if(v1alpha1_json_patch->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_json_patch_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_json_patch->expression) {
        free(v1alpha1_json_patch->expression);
        v1alpha1_json_patch->expression = NULL;
    }
    free(v1alpha1_json_patch);
}

cJSON *v1alpha1_json_patch_convertToJSON(v1alpha1_json_patch_t *v1alpha1_json_patch) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_json_patch->expression
    if(v1alpha1_json_patch->expression) {
    if(cJSON_AddStringToObject(item, "expression", v1alpha1_json_patch->expression) == NULL) {
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

v1alpha1_json_patch_t *v1alpha1_json_patch_parseFromJSON(cJSON *v1alpha1_json_patchJSON){

    v1alpha1_json_patch_t *v1alpha1_json_patch_local_var = NULL;

    // v1alpha1_json_patch->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1alpha1_json_patchJSON, "expression");
    if (cJSON_IsNull(expression)) {
        expression = NULL;
    }
    if (expression) { 
    if(!cJSON_IsString(expression) && !cJSON_IsNull(expression))
    {
    goto end; //String
    }
    }


    v1alpha1_json_patch_local_var = v1alpha1_json_patch_create_internal (
        expression && !cJSON_IsNull(expression) ? strdup(expression->valuestring) : NULL
        );

    return v1alpha1_json_patch_local_var;
end:
    return NULL;

}
