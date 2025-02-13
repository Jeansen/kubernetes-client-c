#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_spec.h"



static v1_ingress_spec_t *v1_ingress_spec_create_internal(
    v1_ingress_backend_t *default_backend,
    char *ingress_class_name,
    list_t *rules,
    list_t *tls
    ) {
    v1_ingress_spec_t *v1_ingress_spec_local_var = malloc(sizeof(v1_ingress_spec_t));
    if (!v1_ingress_spec_local_var) {
        return NULL;
    }
    v1_ingress_spec_local_var->default_backend = default_backend;
    v1_ingress_spec_local_var->ingress_class_name = ingress_class_name;
    v1_ingress_spec_local_var->rules = rules;
    v1_ingress_spec_local_var->tls = tls;

    v1_ingress_spec_local_var->_library_owned = 1;
    return v1_ingress_spec_local_var;
}

__attribute__((deprecated)) v1_ingress_spec_t *v1_ingress_spec_create(
    v1_ingress_backend_t *default_backend,
    char *ingress_class_name,
    list_t *rules,
    list_t *tls
    ) {
    return v1_ingress_spec_create_internal (
        default_backend,
        ingress_class_name,
        rules,
        tls
        );
}

void v1_ingress_spec_free(v1_ingress_spec_t *v1_ingress_spec) {
    if(NULL == v1_ingress_spec){
        return ;
    }
    if(v1_ingress_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ingress_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_spec->default_backend) {
        v1_ingress_backend_free(v1_ingress_spec->default_backend);
        v1_ingress_spec->default_backend = NULL;
    }
    if (v1_ingress_spec->ingress_class_name) {
        free(v1_ingress_spec->ingress_class_name);
        v1_ingress_spec->ingress_class_name = NULL;
    }
    if (v1_ingress_spec->rules) {
        list_ForEach(listEntry, v1_ingress_spec->rules) {
            v1_ingress_rule_free(listEntry->data);
        }
        list_freeList(v1_ingress_spec->rules);
        v1_ingress_spec->rules = NULL;
    }
    if (v1_ingress_spec->tls) {
        list_ForEach(listEntry, v1_ingress_spec->tls) {
            v1_ingress_tls_free(listEntry->data);
        }
        list_freeList(v1_ingress_spec->tls);
        v1_ingress_spec->tls = NULL;
    }
    free(v1_ingress_spec);
}

cJSON *v1_ingress_spec_convertToJSON(v1_ingress_spec_t *v1_ingress_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_spec->default_backend
    if(v1_ingress_spec->default_backend) {
    cJSON *default_backend_local_JSON = v1_ingress_backend_convertToJSON(v1_ingress_spec->default_backend);
    if(default_backend_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "defaultBackend", default_backend_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_ingress_spec->ingress_class_name
    if(v1_ingress_spec->ingress_class_name) {
    if(cJSON_AddStringToObject(item, "ingressClassName", v1_ingress_spec->ingress_class_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_ingress_spec->rules
    if(v1_ingress_spec->rules) {
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (v1_ingress_spec->rules) {
    list_ForEach(rulesListEntry, v1_ingress_spec->rules) {
    cJSON *itemLocal = v1_ingress_rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
    }
    }
    }


    // v1_ingress_spec->tls
    if(v1_ingress_spec->tls) {
    cJSON *tls = cJSON_AddArrayToObject(item, "tls");
    if(tls == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tlsListEntry;
    if (v1_ingress_spec->tls) {
    list_ForEach(tlsListEntry, v1_ingress_spec->tls) {
    cJSON *itemLocal = v1_ingress_tls_convertToJSON(tlsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tls, itemLocal);
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

v1_ingress_spec_t *v1_ingress_spec_parseFromJSON(cJSON *v1_ingress_specJSON){

    v1_ingress_spec_t *v1_ingress_spec_local_var = NULL;

    // define the local variable for v1_ingress_spec->default_backend
    v1_ingress_backend_t *default_backend_local_nonprim = NULL;

    // define the local list for v1_ingress_spec->rules
    list_t *rulesList = NULL;

    // define the local list for v1_ingress_spec->tls
    list_t *tlsList = NULL;

    // v1_ingress_spec->default_backend
    cJSON *default_backend = cJSON_GetObjectItemCaseSensitive(v1_ingress_specJSON, "defaultBackend");
    if (cJSON_IsNull(default_backend)) {
        default_backend = NULL;
    }
    if (default_backend) { 
    default_backend_local_nonprim = v1_ingress_backend_parseFromJSON(default_backend); //nonprimitive
    }

    // v1_ingress_spec->ingress_class_name
    cJSON *ingress_class_name = cJSON_GetObjectItemCaseSensitive(v1_ingress_specJSON, "ingressClassName");
    if (cJSON_IsNull(ingress_class_name)) {
        ingress_class_name = NULL;
    }
    if (ingress_class_name) { 
    if(!cJSON_IsString(ingress_class_name) && !cJSON_IsNull(ingress_class_name))
    {
    goto end; //String
    }
    }

    // v1_ingress_spec->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(v1_ingress_specJSON, "rules");
    if (cJSON_IsNull(rules)) {
        rules = NULL;
    }
    if (rules) { 
    cJSON *rules_local_nonprimitive = NULL;
    if(!cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_createList();

    cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        v1_ingress_rule_t *rulesItem = v1_ingress_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }

    // v1_ingress_spec->tls
    cJSON *tls = cJSON_GetObjectItemCaseSensitive(v1_ingress_specJSON, "tls");
    if (cJSON_IsNull(tls)) {
        tls = NULL;
    }
    if (tls) { 
    cJSON *tls_local_nonprimitive = NULL;
    if(!cJSON_IsArray(tls)){
        goto end; //nonprimitive container
    }

    tlsList = list_createList();

    cJSON_ArrayForEach(tls_local_nonprimitive,tls )
    {
        if(!cJSON_IsObject(tls_local_nonprimitive)){
            goto end;
        }
        v1_ingress_tls_t *tlsItem = v1_ingress_tls_parseFromJSON(tls_local_nonprimitive);

        list_addElement(tlsList, tlsItem);
    }
    }


    v1_ingress_spec_local_var = v1_ingress_spec_create_internal (
        default_backend ? default_backend_local_nonprim : NULL,
        ingress_class_name && !cJSON_IsNull(ingress_class_name) ? strdup(ingress_class_name->valuestring) : NULL,
        rules ? rulesList : NULL,
        tls ? tlsList : NULL
        );

    return v1_ingress_spec_local_var;
end:
    if (default_backend_local_nonprim) {
        v1_ingress_backend_free(default_backend_local_nonprim);
        default_backend_local_nonprim = NULL;
    }
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            v1_ingress_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    if (tlsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tlsList) {
            v1_ingress_tls_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tlsList);
        tlsList = NULL;
    }
    return NULL;

}
