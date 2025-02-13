#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_security_context.h"



static v1_security_context_t *v1_security_context_create_internal(
    int allow_privilege_escalation,
    v1_app_armor_profile_t *app_armor_profile,
    v1_capabilities_t *capabilities,
    int privileged,
    char *proc_mount,
    int read_only_root_filesystem,
    long run_as_group,
    int run_as_non_root,
    long run_as_user,
    v1_se_linux_options_t *se_linux_options,
    v1_seccomp_profile_t *seccomp_profile,
    v1_windows_security_context_options_t *windows_options
    ) {
    v1_security_context_t *v1_security_context_local_var = malloc(sizeof(v1_security_context_t));
    if (!v1_security_context_local_var) {
        return NULL;
    }
    v1_security_context_local_var->allow_privilege_escalation = allow_privilege_escalation;
    v1_security_context_local_var->app_armor_profile = app_armor_profile;
    v1_security_context_local_var->capabilities = capabilities;
    v1_security_context_local_var->privileged = privileged;
    v1_security_context_local_var->proc_mount = proc_mount;
    v1_security_context_local_var->read_only_root_filesystem = read_only_root_filesystem;
    v1_security_context_local_var->run_as_group = run_as_group;
    v1_security_context_local_var->run_as_non_root = run_as_non_root;
    v1_security_context_local_var->run_as_user = run_as_user;
    v1_security_context_local_var->se_linux_options = se_linux_options;
    v1_security_context_local_var->seccomp_profile = seccomp_profile;
    v1_security_context_local_var->windows_options = windows_options;

    v1_security_context_local_var->_library_owned = 1;
    return v1_security_context_local_var;
}

__attribute__((deprecated)) v1_security_context_t *v1_security_context_create(
    int allow_privilege_escalation,
    v1_app_armor_profile_t *app_armor_profile,
    v1_capabilities_t *capabilities,
    int privileged,
    char *proc_mount,
    int read_only_root_filesystem,
    long run_as_group,
    int run_as_non_root,
    long run_as_user,
    v1_se_linux_options_t *se_linux_options,
    v1_seccomp_profile_t *seccomp_profile,
    v1_windows_security_context_options_t *windows_options
    ) {
    return v1_security_context_create_internal (
        allow_privilege_escalation,
        app_armor_profile,
        capabilities,
        privileged,
        proc_mount,
        read_only_root_filesystem,
        run_as_group,
        run_as_non_root,
        run_as_user,
        se_linux_options,
        seccomp_profile,
        windows_options
        );
}

void v1_security_context_free(v1_security_context_t *v1_security_context) {
    if(NULL == v1_security_context){
        return ;
    }
    if(v1_security_context->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_security_context_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_security_context->app_armor_profile) {
        v1_app_armor_profile_free(v1_security_context->app_armor_profile);
        v1_security_context->app_armor_profile = NULL;
    }
    if (v1_security_context->capabilities) {
        v1_capabilities_free(v1_security_context->capabilities);
        v1_security_context->capabilities = NULL;
    }
    if (v1_security_context->proc_mount) {
        free(v1_security_context->proc_mount);
        v1_security_context->proc_mount = NULL;
    }
    if (v1_security_context->se_linux_options) {
        v1_se_linux_options_free(v1_security_context->se_linux_options);
        v1_security_context->se_linux_options = NULL;
    }
    if (v1_security_context->seccomp_profile) {
        v1_seccomp_profile_free(v1_security_context->seccomp_profile);
        v1_security_context->seccomp_profile = NULL;
    }
    if (v1_security_context->windows_options) {
        v1_windows_security_context_options_free(v1_security_context->windows_options);
        v1_security_context->windows_options = NULL;
    }
    free(v1_security_context);
}

cJSON *v1_security_context_convertToJSON(v1_security_context_t *v1_security_context) {
    cJSON *item = cJSON_CreateObject();

    // v1_security_context->allow_privilege_escalation
    if(v1_security_context->allow_privilege_escalation) {
    if(cJSON_AddBoolToObject(item, "allowPrivilegeEscalation", v1_security_context->allow_privilege_escalation) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_security_context->app_armor_profile
    if(v1_security_context->app_armor_profile) {
    cJSON *app_armor_profile_local_JSON = v1_app_armor_profile_convertToJSON(v1_security_context->app_armor_profile);
    if(app_armor_profile_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "appArmorProfile", app_armor_profile_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_security_context->capabilities
    if(v1_security_context->capabilities) {
    cJSON *capabilities_local_JSON = v1_capabilities_convertToJSON(v1_security_context->capabilities);
    if(capabilities_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "capabilities", capabilities_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_security_context->privileged
    if(v1_security_context->privileged) {
    if(cJSON_AddBoolToObject(item, "privileged", v1_security_context->privileged) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_security_context->proc_mount
    if(v1_security_context->proc_mount) {
    if(cJSON_AddStringToObject(item, "procMount", v1_security_context->proc_mount) == NULL) {
    goto fail; //String
    }
    }


    // v1_security_context->read_only_root_filesystem
    if(v1_security_context->read_only_root_filesystem) {
    if(cJSON_AddBoolToObject(item, "readOnlyRootFilesystem", v1_security_context->read_only_root_filesystem) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_security_context->run_as_group
    if(v1_security_context->run_as_group) {
    if(cJSON_AddNumberToObject(item, "runAsGroup", v1_security_context->run_as_group) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_security_context->run_as_non_root
    if(v1_security_context->run_as_non_root) {
    if(cJSON_AddBoolToObject(item, "runAsNonRoot", v1_security_context->run_as_non_root) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_security_context->run_as_user
    if(v1_security_context->run_as_user) {
    if(cJSON_AddNumberToObject(item, "runAsUser", v1_security_context->run_as_user) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_security_context->se_linux_options
    if(v1_security_context->se_linux_options) {
    cJSON *se_linux_options_local_JSON = v1_se_linux_options_convertToJSON(v1_security_context->se_linux_options);
    if(se_linux_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "seLinuxOptions", se_linux_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_security_context->seccomp_profile
    if(v1_security_context->seccomp_profile) {
    cJSON *seccomp_profile_local_JSON = v1_seccomp_profile_convertToJSON(v1_security_context->seccomp_profile);
    if(seccomp_profile_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "seccompProfile", seccomp_profile_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_security_context->windows_options
    if(v1_security_context->windows_options) {
    cJSON *windows_options_local_JSON = v1_windows_security_context_options_convertToJSON(v1_security_context->windows_options);
    if(windows_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "windowsOptions", windows_options_local_JSON);
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

v1_security_context_t *v1_security_context_parseFromJSON(cJSON *v1_security_contextJSON){

    v1_security_context_t *v1_security_context_local_var = NULL;

    // define the local variable for v1_security_context->app_armor_profile
    v1_app_armor_profile_t *app_armor_profile_local_nonprim = NULL;

    // define the local variable for v1_security_context->capabilities
    v1_capabilities_t *capabilities_local_nonprim = NULL;

    // define the local variable for v1_security_context->se_linux_options
    v1_se_linux_options_t *se_linux_options_local_nonprim = NULL;

    // define the local variable for v1_security_context->seccomp_profile
    v1_seccomp_profile_t *seccomp_profile_local_nonprim = NULL;

    // define the local variable for v1_security_context->windows_options
    v1_windows_security_context_options_t *windows_options_local_nonprim = NULL;

    // v1_security_context->allow_privilege_escalation
    cJSON *allow_privilege_escalation = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "allowPrivilegeEscalation");
    if (cJSON_IsNull(allow_privilege_escalation)) {
        allow_privilege_escalation = NULL;
    }
    if (allow_privilege_escalation) { 
    if(!cJSON_IsBool(allow_privilege_escalation))
    {
    goto end; //Bool
    }
    }

    // v1_security_context->app_armor_profile
    cJSON *app_armor_profile = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "appArmorProfile");
    if (cJSON_IsNull(app_armor_profile)) {
        app_armor_profile = NULL;
    }
    if (app_armor_profile) { 
    app_armor_profile_local_nonprim = v1_app_armor_profile_parseFromJSON(app_armor_profile); //nonprimitive
    }

    // v1_security_context->capabilities
    cJSON *capabilities = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "capabilities");
    if (cJSON_IsNull(capabilities)) {
        capabilities = NULL;
    }
    if (capabilities) { 
    capabilities_local_nonprim = v1_capabilities_parseFromJSON(capabilities); //nonprimitive
    }

    // v1_security_context->privileged
    cJSON *privileged = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "privileged");
    if (cJSON_IsNull(privileged)) {
        privileged = NULL;
    }
    if (privileged) { 
    if(!cJSON_IsBool(privileged))
    {
    goto end; //Bool
    }
    }

    // v1_security_context->proc_mount
    cJSON *proc_mount = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "procMount");
    if (cJSON_IsNull(proc_mount)) {
        proc_mount = NULL;
    }
    if (proc_mount) { 
    if(!cJSON_IsString(proc_mount) && !cJSON_IsNull(proc_mount))
    {
    goto end; //String
    }
    }

    // v1_security_context->read_only_root_filesystem
    cJSON *read_only_root_filesystem = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "readOnlyRootFilesystem");
    if (cJSON_IsNull(read_only_root_filesystem)) {
        read_only_root_filesystem = NULL;
    }
    if (read_only_root_filesystem) { 
    if(!cJSON_IsBool(read_only_root_filesystem))
    {
    goto end; //Bool
    }
    }

    // v1_security_context->run_as_group
    cJSON *run_as_group = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "runAsGroup");
    if (cJSON_IsNull(run_as_group)) {
        run_as_group = NULL;
    }
    if (run_as_group) { 
    if(!cJSON_IsNumber(run_as_group))
    {
    goto end; //Numeric
    }
    }

    // v1_security_context->run_as_non_root
    cJSON *run_as_non_root = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "runAsNonRoot");
    if (cJSON_IsNull(run_as_non_root)) {
        run_as_non_root = NULL;
    }
    if (run_as_non_root) { 
    if(!cJSON_IsBool(run_as_non_root))
    {
    goto end; //Bool
    }
    }

    // v1_security_context->run_as_user
    cJSON *run_as_user = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "runAsUser");
    if (cJSON_IsNull(run_as_user)) {
        run_as_user = NULL;
    }
    if (run_as_user) { 
    if(!cJSON_IsNumber(run_as_user))
    {
    goto end; //Numeric
    }
    }

    // v1_security_context->se_linux_options
    cJSON *se_linux_options = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "seLinuxOptions");
    if (cJSON_IsNull(se_linux_options)) {
        se_linux_options = NULL;
    }
    if (se_linux_options) { 
    se_linux_options_local_nonprim = v1_se_linux_options_parseFromJSON(se_linux_options); //nonprimitive
    }

    // v1_security_context->seccomp_profile
    cJSON *seccomp_profile = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "seccompProfile");
    if (cJSON_IsNull(seccomp_profile)) {
        seccomp_profile = NULL;
    }
    if (seccomp_profile) { 
    seccomp_profile_local_nonprim = v1_seccomp_profile_parseFromJSON(seccomp_profile); //nonprimitive
    }

    // v1_security_context->windows_options
    cJSON *windows_options = cJSON_GetObjectItemCaseSensitive(v1_security_contextJSON, "windowsOptions");
    if (cJSON_IsNull(windows_options)) {
        windows_options = NULL;
    }
    if (windows_options) { 
    windows_options_local_nonprim = v1_windows_security_context_options_parseFromJSON(windows_options); //nonprimitive
    }


    v1_security_context_local_var = v1_security_context_create_internal (
        allow_privilege_escalation ? allow_privilege_escalation->valueint : 0,
        app_armor_profile ? app_armor_profile_local_nonprim : NULL,
        capabilities ? capabilities_local_nonprim : NULL,
        privileged ? privileged->valueint : 0,
        proc_mount && !cJSON_IsNull(proc_mount) ? strdup(proc_mount->valuestring) : NULL,
        read_only_root_filesystem ? read_only_root_filesystem->valueint : 0,
        run_as_group ? run_as_group->valuedouble : 0,
        run_as_non_root ? run_as_non_root->valueint : 0,
        run_as_user ? run_as_user->valuedouble : 0,
        se_linux_options ? se_linux_options_local_nonprim : NULL,
        seccomp_profile ? seccomp_profile_local_nonprim : NULL,
        windows_options ? windows_options_local_nonprim : NULL
        );

    return v1_security_context_local_var;
end:
    if (app_armor_profile_local_nonprim) {
        v1_app_armor_profile_free(app_armor_profile_local_nonprim);
        app_armor_profile_local_nonprim = NULL;
    }
    if (capabilities_local_nonprim) {
        v1_capabilities_free(capabilities_local_nonprim);
        capabilities_local_nonprim = NULL;
    }
    if (se_linux_options_local_nonprim) {
        v1_se_linux_options_free(se_linux_options_local_nonprim);
        se_linux_options_local_nonprim = NULL;
    }
    if (seccomp_profile_local_nonprim) {
        v1_seccomp_profile_free(seccomp_profile_local_nonprim);
        seccomp_profile_local_nonprim = NULL;
    }
    if (windows_options_local_nonprim) {
        v1_windows_security_context_options_free(windows_options_local_nonprim);
        windows_options_local_nonprim = NULL;
    }
    return NULL;

}
