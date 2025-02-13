#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_definition_version.h"



static v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_create_internal(
    list_t *additional_printer_columns,
    int deprecated,
    char *deprecation_warning,
    char *name,
    v1_custom_resource_validation_t *schema,
    list_t *selectable_fields,
    int served,
    int storage,
    v1_custom_resource_subresources_t *subresources
    ) {
    v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_local_var = malloc(sizeof(v1_custom_resource_definition_version_t));
    if (!v1_custom_resource_definition_version_local_var) {
        return NULL;
    }
    v1_custom_resource_definition_version_local_var->additional_printer_columns = additional_printer_columns;
    v1_custom_resource_definition_version_local_var->deprecated = deprecated;
    v1_custom_resource_definition_version_local_var->deprecation_warning = deprecation_warning;
    v1_custom_resource_definition_version_local_var->name = name;
    v1_custom_resource_definition_version_local_var->schema = schema;
    v1_custom_resource_definition_version_local_var->selectable_fields = selectable_fields;
    v1_custom_resource_definition_version_local_var->served = served;
    v1_custom_resource_definition_version_local_var->storage = storage;
    v1_custom_resource_definition_version_local_var->subresources = subresources;

    v1_custom_resource_definition_version_local_var->_library_owned = 1;
    return v1_custom_resource_definition_version_local_var;
}

__attribute__((deprecated)) v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_create(
    list_t *additional_printer_columns,
    int deprecated,
    char *deprecation_warning,
    char *name,
    v1_custom_resource_validation_t *schema,
    list_t *selectable_fields,
    int served,
    int storage,
    v1_custom_resource_subresources_t *subresources
    ) {
    return v1_custom_resource_definition_version_create_internal (
        additional_printer_columns,
        deprecated,
        deprecation_warning,
        name,
        schema,
        selectable_fields,
        served,
        storage,
        subresources
        );
}

void v1_custom_resource_definition_version_free(v1_custom_resource_definition_version_t *v1_custom_resource_definition_version) {
    if(NULL == v1_custom_resource_definition_version){
        return ;
    }
    if(v1_custom_resource_definition_version->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_custom_resource_definition_version_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_custom_resource_definition_version->additional_printer_columns) {
        list_ForEach(listEntry, v1_custom_resource_definition_version->additional_printer_columns) {
            v1_custom_resource_column_definition_free(listEntry->data);
        }
        list_freeList(v1_custom_resource_definition_version->additional_printer_columns);
        v1_custom_resource_definition_version->additional_printer_columns = NULL;
    }
    if (v1_custom_resource_definition_version->deprecation_warning) {
        free(v1_custom_resource_definition_version->deprecation_warning);
        v1_custom_resource_definition_version->deprecation_warning = NULL;
    }
    if (v1_custom_resource_definition_version->name) {
        free(v1_custom_resource_definition_version->name);
        v1_custom_resource_definition_version->name = NULL;
    }
    if (v1_custom_resource_definition_version->schema) {
        v1_custom_resource_validation_free(v1_custom_resource_definition_version->schema);
        v1_custom_resource_definition_version->schema = NULL;
    }
    if (v1_custom_resource_definition_version->selectable_fields) {
        list_ForEach(listEntry, v1_custom_resource_definition_version->selectable_fields) {
            v1_selectable_field_free(listEntry->data);
        }
        list_freeList(v1_custom_resource_definition_version->selectable_fields);
        v1_custom_resource_definition_version->selectable_fields = NULL;
    }
    if (v1_custom_resource_definition_version->subresources) {
        v1_custom_resource_subresources_free(v1_custom_resource_definition_version->subresources);
        v1_custom_resource_definition_version->subresources = NULL;
    }
    free(v1_custom_resource_definition_version);
}

cJSON *v1_custom_resource_definition_version_convertToJSON(v1_custom_resource_definition_version_t *v1_custom_resource_definition_version) {
    cJSON *item = cJSON_CreateObject();

    // v1_custom_resource_definition_version->additional_printer_columns
    if(v1_custom_resource_definition_version->additional_printer_columns) {
    cJSON *additional_printer_columns = cJSON_AddArrayToObject(item, "additionalPrinterColumns");
    if(additional_printer_columns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *additional_printer_columnsListEntry;
    if (v1_custom_resource_definition_version->additional_printer_columns) {
    list_ForEach(additional_printer_columnsListEntry, v1_custom_resource_definition_version->additional_printer_columns) {
    cJSON *itemLocal = v1_custom_resource_column_definition_convertToJSON(additional_printer_columnsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(additional_printer_columns, itemLocal);
    }
    }
    }


    // v1_custom_resource_definition_version->deprecated
    if(v1_custom_resource_definition_version->deprecated) {
    if(cJSON_AddBoolToObject(item, "deprecated", v1_custom_resource_definition_version->deprecated) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_custom_resource_definition_version->deprecation_warning
    if(v1_custom_resource_definition_version->deprecation_warning) {
    if(cJSON_AddStringToObject(item, "deprecationWarning", v1_custom_resource_definition_version->deprecation_warning) == NULL) {
    goto fail; //String
    }
    }


    // v1_custom_resource_definition_version->name
    if (!v1_custom_resource_definition_version->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_custom_resource_definition_version->name) == NULL) {
    goto fail; //String
    }


    // v1_custom_resource_definition_version->schema
    if(v1_custom_resource_definition_version->schema) {
    cJSON *schema_local_JSON = v1_custom_resource_validation_convertToJSON(v1_custom_resource_definition_version->schema);
    if(schema_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schema", schema_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_custom_resource_definition_version->selectable_fields
    if(v1_custom_resource_definition_version->selectable_fields) {
    cJSON *selectable_fields = cJSON_AddArrayToObject(item, "selectableFields");
    if(selectable_fields == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *selectable_fieldsListEntry;
    if (v1_custom_resource_definition_version->selectable_fields) {
    list_ForEach(selectable_fieldsListEntry, v1_custom_resource_definition_version->selectable_fields) {
    cJSON *itemLocal = v1_selectable_field_convertToJSON(selectable_fieldsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(selectable_fields, itemLocal);
    }
    }
    }


    // v1_custom_resource_definition_version->served
    if (!v1_custom_resource_definition_version->served) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "served", v1_custom_resource_definition_version->served) == NULL) {
    goto fail; //Bool
    }


    // v1_custom_resource_definition_version->storage
    if (!v1_custom_resource_definition_version->storage) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "storage", v1_custom_resource_definition_version->storage) == NULL) {
    goto fail; //Bool
    }


    // v1_custom_resource_definition_version->subresources
    if(v1_custom_resource_definition_version->subresources) {
    cJSON *subresources_local_JSON = v1_custom_resource_subresources_convertToJSON(v1_custom_resource_definition_version->subresources);
    if(subresources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "subresources", subresources_local_JSON);
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

v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_parseFromJSON(cJSON *v1_custom_resource_definition_versionJSON){

    v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_local_var = NULL;

    // define the local list for v1_custom_resource_definition_version->additional_printer_columns
    list_t *additional_printer_columnsList = NULL;

    // define the local variable for v1_custom_resource_definition_version->schema
    v1_custom_resource_validation_t *schema_local_nonprim = NULL;

    // define the local list for v1_custom_resource_definition_version->selectable_fields
    list_t *selectable_fieldsList = NULL;

    // define the local variable for v1_custom_resource_definition_version->subresources
    v1_custom_resource_subresources_t *subresources_local_nonprim = NULL;

    // v1_custom_resource_definition_version->additional_printer_columns
    cJSON *additional_printer_columns = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "additionalPrinterColumns");
    if (cJSON_IsNull(additional_printer_columns)) {
        additional_printer_columns = NULL;
    }
    if (additional_printer_columns) { 
    cJSON *additional_printer_columns_local_nonprimitive = NULL;
    if(!cJSON_IsArray(additional_printer_columns)){
        goto end; //nonprimitive container
    }

    additional_printer_columnsList = list_createList();

    cJSON_ArrayForEach(additional_printer_columns_local_nonprimitive,additional_printer_columns )
    {
        if(!cJSON_IsObject(additional_printer_columns_local_nonprimitive)){
            goto end;
        }
        v1_custom_resource_column_definition_t *additional_printer_columnsItem = v1_custom_resource_column_definition_parseFromJSON(additional_printer_columns_local_nonprimitive);

        list_addElement(additional_printer_columnsList, additional_printer_columnsItem);
    }
    }

    // v1_custom_resource_definition_version->deprecated
    cJSON *deprecated = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "deprecated");
    if (cJSON_IsNull(deprecated)) {
        deprecated = NULL;
    }
    if (deprecated) { 
    if(!cJSON_IsBool(deprecated))
    {
    goto end; //Bool
    }
    }

    // v1_custom_resource_definition_version->deprecation_warning
    cJSON *deprecation_warning = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "deprecationWarning");
    if (cJSON_IsNull(deprecation_warning)) {
        deprecation_warning = NULL;
    }
    if (deprecation_warning) { 
    if(!cJSON_IsString(deprecation_warning) && !cJSON_IsNull(deprecation_warning))
    {
    goto end; //String
    }
    }

    // v1_custom_resource_definition_version->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_custom_resource_definition_version->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "schema");
    if (cJSON_IsNull(schema)) {
        schema = NULL;
    }
    if (schema) { 
    schema_local_nonprim = v1_custom_resource_validation_parseFromJSON(schema); //nonprimitive
    }

    // v1_custom_resource_definition_version->selectable_fields
    cJSON *selectable_fields = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "selectableFields");
    if (cJSON_IsNull(selectable_fields)) {
        selectable_fields = NULL;
    }
    if (selectable_fields) { 
    cJSON *selectable_fields_local_nonprimitive = NULL;
    if(!cJSON_IsArray(selectable_fields)){
        goto end; //nonprimitive container
    }

    selectable_fieldsList = list_createList();

    cJSON_ArrayForEach(selectable_fields_local_nonprimitive,selectable_fields )
    {
        if(!cJSON_IsObject(selectable_fields_local_nonprimitive)){
            goto end;
        }
        v1_selectable_field_t *selectable_fieldsItem = v1_selectable_field_parseFromJSON(selectable_fields_local_nonprimitive);

        list_addElement(selectable_fieldsList, selectable_fieldsItem);
    }
    }

    // v1_custom_resource_definition_version->served
    cJSON *served = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "served");
    if (cJSON_IsNull(served)) {
        served = NULL;
    }
    if (!served) {
        goto end;
    }

    
    if(!cJSON_IsBool(served))
    {
    goto end; //Bool
    }

    // v1_custom_resource_definition_version->storage
    cJSON *storage = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "storage");
    if (cJSON_IsNull(storage)) {
        storage = NULL;
    }
    if (!storage) {
        goto end;
    }

    
    if(!cJSON_IsBool(storage))
    {
    goto end; //Bool
    }

    // v1_custom_resource_definition_version->subresources
    cJSON *subresources = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "subresources");
    if (cJSON_IsNull(subresources)) {
        subresources = NULL;
    }
    if (subresources) { 
    subresources_local_nonprim = v1_custom_resource_subresources_parseFromJSON(subresources); //nonprimitive
    }


    v1_custom_resource_definition_version_local_var = v1_custom_resource_definition_version_create_internal (
        additional_printer_columns ? additional_printer_columnsList : NULL,
        deprecated ? deprecated->valueint : 0,
        deprecation_warning && !cJSON_IsNull(deprecation_warning) ? strdup(deprecation_warning->valuestring) : NULL,
        strdup(name->valuestring),
        schema ? schema_local_nonprim : NULL,
        selectable_fields ? selectable_fieldsList : NULL,
        served->valueint,
        storage->valueint,
        subresources ? subresources_local_nonprim : NULL
        );

    return v1_custom_resource_definition_version_local_var;
end:
    if (additional_printer_columnsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, additional_printer_columnsList) {
            v1_custom_resource_column_definition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(additional_printer_columnsList);
        additional_printer_columnsList = NULL;
    }
    if (schema_local_nonprim) {
        v1_custom_resource_validation_free(schema_local_nonprim);
        schema_local_nonprim = NULL;
    }
    if (selectable_fieldsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, selectable_fieldsList) {
            v1_selectable_field_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(selectable_fieldsList);
        selectable_fieldsList = NULL;
    }
    if (subresources_local_nonprim) {
        v1_custom_resource_subresources_free(subresources_local_nonprim);
        subresources_local_nonprim = NULL;
    }
    return NULL;

}
