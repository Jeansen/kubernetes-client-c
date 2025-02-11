#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_aggregation_rule.h"



static v1_aggregation_rule_t *v1_aggregation_rule_create_internal(
    list_t *cluster_role_selectors
    ) {
    v1_aggregation_rule_t *v1_aggregation_rule_local_var = malloc(sizeof(v1_aggregation_rule_t));
    if (!v1_aggregation_rule_local_var) {
        return NULL;
    }
    v1_aggregation_rule_local_var->cluster_role_selectors = cluster_role_selectors;

    v1_aggregation_rule_local_var->_library_owned = 1;
    return v1_aggregation_rule_local_var;
}

__attribute__((deprecated)) v1_aggregation_rule_t *v1_aggregation_rule_create(
    list_t *cluster_role_selectors
    ) {
    return v1_aggregation_rule_create_internal (
        cluster_role_selectors
        );
}

void v1_aggregation_rule_free(v1_aggregation_rule_t *v1_aggregation_rule) {
    if(NULL == v1_aggregation_rule){
        return ;
    }
    if(v1_aggregation_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_aggregation_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_aggregation_rule->cluster_role_selectors) {
        list_ForEach(listEntry, v1_aggregation_rule->cluster_role_selectors) {
            v1_label_selector_free(listEntry->data);
        }
        list_freeList(v1_aggregation_rule->cluster_role_selectors);
        v1_aggregation_rule->cluster_role_selectors = NULL;
    }
    free(v1_aggregation_rule);
}

cJSON *v1_aggregation_rule_convertToJSON(v1_aggregation_rule_t *v1_aggregation_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_aggregation_rule->cluster_role_selectors
    if(v1_aggregation_rule->cluster_role_selectors) {
    cJSON *cluster_role_selectors = cJSON_AddArrayToObject(item, "clusterRoleSelectors");
    if(cluster_role_selectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *cluster_role_selectorsListEntry;
    if (v1_aggregation_rule->cluster_role_selectors) {
    list_ForEach(cluster_role_selectorsListEntry, v1_aggregation_rule->cluster_role_selectors) {
    cJSON *itemLocal = v1_label_selector_convertToJSON(cluster_role_selectorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(cluster_role_selectors, itemLocal);
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

v1_aggregation_rule_t *v1_aggregation_rule_parseFromJSON(cJSON *v1_aggregation_ruleJSON){

    v1_aggregation_rule_t *v1_aggregation_rule_local_var = NULL;

    // define the local list for v1_aggregation_rule->cluster_role_selectors
    list_t *cluster_role_selectorsList = NULL;

    // v1_aggregation_rule->cluster_role_selectors
    cJSON *cluster_role_selectors = cJSON_GetObjectItemCaseSensitive(v1_aggregation_ruleJSON, "clusterRoleSelectors");
    if (cJSON_IsNull(cluster_role_selectors)) {
        cluster_role_selectors = NULL;
    }
    if (cluster_role_selectors) { 
    cJSON *cluster_role_selectors_local_nonprimitive = NULL;
    if(!cJSON_IsArray(cluster_role_selectors)){
        goto end; //nonprimitive container
    }

    cluster_role_selectorsList = list_createList();

    cJSON_ArrayForEach(cluster_role_selectors_local_nonprimitive,cluster_role_selectors )
    {
        if(!cJSON_IsObject(cluster_role_selectors_local_nonprimitive)){
            goto end;
        }
        v1_label_selector_t *cluster_role_selectorsItem = v1_label_selector_parseFromJSON(cluster_role_selectors_local_nonprimitive);

        list_addElement(cluster_role_selectorsList, cluster_role_selectorsItem);
    }
    }


    v1_aggregation_rule_local_var = v1_aggregation_rule_create_internal (
        cluster_role_selectors ? cluster_role_selectorsList : NULL
        );

    return v1_aggregation_rule_local_var;
end:
    if (cluster_role_selectorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, cluster_role_selectorsList) {
            v1_label_selector_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(cluster_role_selectorsList);
        cluster_role_selectorsList = NULL;
    }
    return NULL;

}
