#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_limit_range_spec.h"



static v1_limit_range_spec_t *v1_limit_range_spec_create_internal(
    list_t *limits
    ) {
    v1_limit_range_spec_t *v1_limit_range_spec_local_var = malloc(sizeof(v1_limit_range_spec_t));
    if (!v1_limit_range_spec_local_var) {
        return NULL;
    }
    v1_limit_range_spec_local_var->limits = limits;

    v1_limit_range_spec_local_var->_library_owned = 1;
    return v1_limit_range_spec_local_var;
}

__attribute__((deprecated)) v1_limit_range_spec_t *v1_limit_range_spec_create(
    list_t *limits
    ) {
    return v1_limit_range_spec_create_internal (
        limits
        );
}

void v1_limit_range_spec_free(v1_limit_range_spec_t *v1_limit_range_spec) {
    if(NULL == v1_limit_range_spec){
        return ;
    }
    if(v1_limit_range_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_limit_range_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_limit_range_spec->limits) {
        list_ForEach(listEntry, v1_limit_range_spec->limits) {
            v1_limit_range_item_free(listEntry->data);
        }
        list_freeList(v1_limit_range_spec->limits);
        v1_limit_range_spec->limits = NULL;
    }
    free(v1_limit_range_spec);
}

cJSON *v1_limit_range_spec_convertToJSON(v1_limit_range_spec_t *v1_limit_range_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_limit_range_spec->limits
    if (!v1_limit_range_spec->limits) {
        goto fail;
    }
    cJSON *limits = cJSON_AddArrayToObject(item, "limits");
    if(limits == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *limitsListEntry;
    if (v1_limit_range_spec->limits) {
    list_ForEach(limitsListEntry, v1_limit_range_spec->limits) {
    cJSON *itemLocal = v1_limit_range_item_convertToJSON(limitsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(limits, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_limit_range_spec_t *v1_limit_range_spec_parseFromJSON(cJSON *v1_limit_range_specJSON){

    v1_limit_range_spec_t *v1_limit_range_spec_local_var = NULL;

    // define the local list for v1_limit_range_spec->limits
    list_t *limitsList = NULL;

    // v1_limit_range_spec->limits
    cJSON *limits = cJSON_GetObjectItemCaseSensitive(v1_limit_range_specJSON, "limits");
    if (cJSON_IsNull(limits)) {
        limits = NULL;
    }
    if (!limits) {
        goto end;
    }

    
    cJSON *limits_local_nonprimitive = NULL;
    if(!cJSON_IsArray(limits)){
        goto end; //nonprimitive container
    }

    limitsList = list_createList();

    cJSON_ArrayForEach(limits_local_nonprimitive,limits )
    {
        if(!cJSON_IsObject(limits_local_nonprimitive)){
            goto end;
        }
        v1_limit_range_item_t *limitsItem = v1_limit_range_item_parseFromJSON(limits_local_nonprimitive);

        list_addElement(limitsList, limitsItem);
    }


    v1_limit_range_spec_local_var = v1_limit_range_spec_create_internal (
        limitsList
        );

    return v1_limit_range_spec_local_var;
end:
    if (limitsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, limitsList) {
            v1_limit_range_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(limitsList);
        limitsList = NULL;
    }
    return NULL;

}
