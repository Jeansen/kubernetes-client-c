#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scope_selector.h"



static v1_scope_selector_t *v1_scope_selector_create_internal(
    list_t *match_expressions
    ) {
    v1_scope_selector_t *v1_scope_selector_local_var = malloc(sizeof(v1_scope_selector_t));
    if (!v1_scope_selector_local_var) {
        return NULL;
    }
    v1_scope_selector_local_var->match_expressions = match_expressions;

    v1_scope_selector_local_var->_library_owned = 1;
    return v1_scope_selector_local_var;
}

__attribute__((deprecated)) v1_scope_selector_t *v1_scope_selector_create(
    list_t *match_expressions
    ) {
    return v1_scope_selector_create_internal (
        match_expressions
        );
}

void v1_scope_selector_free(v1_scope_selector_t *v1_scope_selector) {
    if(NULL == v1_scope_selector){
        return ;
    }
    if(v1_scope_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_scope_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_scope_selector->match_expressions) {
        list_ForEach(listEntry, v1_scope_selector->match_expressions) {
            v1_scoped_resource_selector_requirement_free(listEntry->data);
        }
        list_freeList(v1_scope_selector->match_expressions);
        v1_scope_selector->match_expressions = NULL;
    }
    free(v1_scope_selector);
}

cJSON *v1_scope_selector_convertToJSON(v1_scope_selector_t *v1_scope_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_scope_selector->match_expressions
    if(v1_scope_selector->match_expressions) {
    cJSON *match_expressions = cJSON_AddArrayToObject(item, "matchExpressions");
    if(match_expressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_expressionsListEntry;
    if (v1_scope_selector->match_expressions) {
    list_ForEach(match_expressionsListEntry, v1_scope_selector->match_expressions) {
    cJSON *itemLocal = v1_scoped_resource_selector_requirement_convertToJSON(match_expressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(match_expressions, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_scope_selector_t *v1_scope_selector_parseFromJSON(cJSON *v1_scope_selectorJSON){

    v1_scope_selector_t *v1_scope_selector_local_var = NULL;

    // define the local list for v1_scope_selector->match_expressions
    list_t *match_expressionsList = NULL;

    // v1_scope_selector->match_expressions
    cJSON *match_expressions = cJSON_GetObjectItemCaseSensitive(v1_scope_selectorJSON, "matchExpressions");
    if (cJSON_IsNull(match_expressions)) {
        match_expressions = NULL;
    }
    if (match_expressions) { 
    cJSON *match_expressions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(match_expressions)){
        goto end; //nonprimitive container
    }

    match_expressionsList = list_createList();

    cJSON_ArrayForEach(match_expressions_local_nonprimitive,match_expressions )
    {
        if(!cJSON_IsObject(match_expressions_local_nonprimitive)){
            goto end;
        }
        v1_scoped_resource_selector_requirement_t *match_expressionsItem = v1_scoped_resource_selector_requirement_parseFromJSON(match_expressions_local_nonprimitive);

        list_addElement(match_expressionsList, match_expressionsItem);
    }
    }


    v1_scope_selector_local_var = v1_scope_selector_create_internal (
        match_expressions ? match_expressionsList : NULL
        );

    return v1_scope_selector_local_var;
end:
    if (match_expressionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_expressionsList) {
            v1_scoped_resource_selector_requirement_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_expressionsList);
        match_expressionsList = NULL;
    }
    return NULL;

}
