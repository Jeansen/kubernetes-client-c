#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_selector.h"



static v1_node_selector_t *v1_node_selector_create_internal(
    list_t *node_selector_terms
    ) {
    v1_node_selector_t *v1_node_selector_local_var = malloc(sizeof(v1_node_selector_t));
    if (!v1_node_selector_local_var) {
        return NULL;
    }
    v1_node_selector_local_var->node_selector_terms = node_selector_terms;

    v1_node_selector_local_var->_library_owned = 1;
    return v1_node_selector_local_var;
}

__attribute__((deprecated)) v1_node_selector_t *v1_node_selector_create(
    list_t *node_selector_terms
    ) {
    return v1_node_selector_create_internal (
        node_selector_terms
        );
}

void v1_node_selector_free(v1_node_selector_t *v1_node_selector) {
    if(NULL == v1_node_selector){
        return ;
    }
    if(v1_node_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_selector->node_selector_terms) {
        list_ForEach(listEntry, v1_node_selector->node_selector_terms) {
            v1_node_selector_term_free(listEntry->data);
        }
        list_freeList(v1_node_selector->node_selector_terms);
        v1_node_selector->node_selector_terms = NULL;
    }
    free(v1_node_selector);
}

cJSON *v1_node_selector_convertToJSON(v1_node_selector_t *v1_node_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_selector->node_selector_terms
    if (!v1_node_selector->node_selector_terms) {
        goto fail;
    }
    cJSON *node_selector_terms = cJSON_AddArrayToObject(item, "nodeSelectorTerms");
    if(node_selector_terms == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *node_selector_termsListEntry;
    if (v1_node_selector->node_selector_terms) {
    list_ForEach(node_selector_termsListEntry, v1_node_selector->node_selector_terms) {
    cJSON *itemLocal = v1_node_selector_term_convertToJSON(node_selector_termsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(node_selector_terms, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_node_selector_t *v1_node_selector_parseFromJSON(cJSON *v1_node_selectorJSON){

    v1_node_selector_t *v1_node_selector_local_var = NULL;

    // define the local list for v1_node_selector->node_selector_terms
    list_t *node_selector_termsList = NULL;

    // v1_node_selector->node_selector_terms
    cJSON *node_selector_terms = cJSON_GetObjectItemCaseSensitive(v1_node_selectorJSON, "nodeSelectorTerms");
    if (cJSON_IsNull(node_selector_terms)) {
        node_selector_terms = NULL;
    }
    if (!node_selector_terms) {
        goto end;
    }

    
    cJSON *node_selector_terms_local_nonprimitive = NULL;
    if(!cJSON_IsArray(node_selector_terms)){
        goto end; //nonprimitive container
    }

    node_selector_termsList = list_createList();

    cJSON_ArrayForEach(node_selector_terms_local_nonprimitive,node_selector_terms )
    {
        if(!cJSON_IsObject(node_selector_terms_local_nonprimitive)){
            goto end;
        }
        v1_node_selector_term_t *node_selector_termsItem = v1_node_selector_term_parseFromJSON(node_selector_terms_local_nonprimitive);

        list_addElement(node_selector_termsList, node_selector_termsItem);
    }


    v1_node_selector_local_var = v1_node_selector_create_internal (
        node_selector_termsList
        );

    return v1_node_selector_local_var;
end:
    if (node_selector_termsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, node_selector_termsList) {
            v1_node_selector_term_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(node_selector_termsList);
        node_selector_termsList = NULL;
    }
    return NULL;

}
