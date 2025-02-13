#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_label_selector.h"



static v1_label_selector_t *v1_label_selector_create_internal(
    list_t *match_expressions,
    list_t* match_labels
    ) {
    v1_label_selector_t *v1_label_selector_local_var = malloc(sizeof(v1_label_selector_t));
    if (!v1_label_selector_local_var) {
        return NULL;
    }
    v1_label_selector_local_var->match_expressions = match_expressions;
    v1_label_selector_local_var->match_labels = match_labels;

    v1_label_selector_local_var->_library_owned = 1;
    return v1_label_selector_local_var;
}

__attribute__((deprecated)) v1_label_selector_t *v1_label_selector_create(
    list_t *match_expressions,
    list_t* match_labels
    ) {
    return v1_label_selector_create_internal (
        match_expressions,
        match_labels
        );
}

void v1_label_selector_free(v1_label_selector_t *v1_label_selector) {
    if(NULL == v1_label_selector){
        return ;
    }
    if(v1_label_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_label_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_label_selector->match_expressions) {
        list_ForEach(listEntry, v1_label_selector->match_expressions) {
            v1_label_selector_requirement_free(listEntry->data);
        }
        list_freeList(v1_label_selector->match_expressions);
        v1_label_selector->match_expressions = NULL;
    }
    if (v1_label_selector->match_labels) {
        list_ForEach(listEntry, v1_label_selector->match_labels) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_label_selector->match_labels);
        v1_label_selector->match_labels = NULL;
    }
    free(v1_label_selector);
}

cJSON *v1_label_selector_convertToJSON(v1_label_selector_t *v1_label_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_label_selector->match_expressions
    if(v1_label_selector->match_expressions) {
    cJSON *match_expressions = cJSON_AddArrayToObject(item, "matchExpressions");
    if(match_expressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_expressionsListEntry;
    if (v1_label_selector->match_expressions) {
    list_ForEach(match_expressionsListEntry, v1_label_selector->match_expressions) {
    cJSON *itemLocal = v1_label_selector_requirement_convertToJSON(match_expressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(match_expressions, itemLocal);
    }
    }
    }


    // v1_label_selector->match_labels
    if(v1_label_selector->match_labels) {
    cJSON *match_labels = cJSON_AddObjectToObject(item, "matchLabels");
    if(match_labels == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = match_labels;
    listEntry_t *match_labelsListEntry;
    if (v1_label_selector->match_labels) {
    list_ForEach(match_labelsListEntry, v1_label_selector->match_labels) {
        keyValuePair_t *localKeyValue = match_labelsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
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

v1_label_selector_t *v1_label_selector_parseFromJSON(cJSON *v1_label_selectorJSON){

    v1_label_selector_t *v1_label_selector_local_var = NULL;

    // define the local list for v1_label_selector->match_expressions
    list_t *match_expressionsList = NULL;

    // define the local map for v1_label_selector->match_labels
    list_t *match_labelsList = NULL;

    // v1_label_selector->match_expressions
    cJSON *match_expressions = cJSON_GetObjectItemCaseSensitive(v1_label_selectorJSON, "matchExpressions");
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
        v1_label_selector_requirement_t *match_expressionsItem = v1_label_selector_requirement_parseFromJSON(match_expressions_local_nonprimitive);

        list_addElement(match_expressionsList, match_expressionsItem);
    }
    }

    // v1_label_selector->match_labels
    cJSON *match_labels = cJSON_GetObjectItemCaseSensitive(v1_label_selectorJSON, "matchLabels");
    if (cJSON_IsNull(match_labels)) {
        match_labels = NULL;
    }
    if (match_labels) { 
    cJSON *match_labels_local_map = NULL;
    if(!cJSON_IsObject(match_labels) && !cJSON_IsNull(match_labels))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(match_labels))
    {
        match_labelsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(match_labels_local_map, match_labels)
        {
            cJSON *localMapObject = match_labels_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(match_labelsList , localMapKeyPair);
        }
    }
    }


    v1_label_selector_local_var = v1_label_selector_create_internal (
        match_expressions ? match_expressionsList : NULL,
        match_labels ? match_labelsList : NULL
        );

    return v1_label_selector_local_var;
end:
    if (match_expressionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_expressionsList) {
            v1_label_selector_requirement_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_expressionsList);
        match_expressionsList = NULL;
    }
    if (match_labelsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_labelsList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(match_labelsList);
        match_labelsList = NULL;
    }
    return NULL;

}
