/*
 * v1alpha1_storage_version_migration_list.h
 *
 * StorageVersionMigrationList is a collection of storage version migrations.
 */

#ifndef _v1alpha1_storage_version_migration_list_H_
#define _v1alpha1_storage_version_migration_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_storage_version_migration_list_t v1alpha1_storage_version_migration_list_t;

#include "v1_list_meta.h"
#include "v1alpha1_storage_version_migration.h"



typedef struct v1alpha1_storage_version_migration_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_storage_version_migration_list_t;

__attribute__((deprecated)) v1alpha1_storage_version_migration_list_t *v1alpha1_storage_version_migration_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1alpha1_storage_version_migration_list_free(v1alpha1_storage_version_migration_list_t *v1alpha1_storage_version_migration_list);

v1alpha1_storage_version_migration_list_t *v1alpha1_storage_version_migration_list_parseFromJSON(cJSON *v1alpha1_storage_version_migration_listJSON);

cJSON *v1alpha1_storage_version_migration_list_convertToJSON(v1alpha1_storage_version_migration_list_t *v1alpha1_storage_version_migration_list);

#endif /* _v1alpha1_storage_version_migration_list_H_ */

