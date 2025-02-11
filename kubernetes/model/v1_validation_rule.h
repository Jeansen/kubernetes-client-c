/*
 * v1_validation_rule.h
 *
 * ValidationRule describes a validation rule written in the CEL expression language.
 */

#ifndef _v1_validation_rule_H_
#define _v1_validation_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_validation_rule_t v1_validation_rule_t;




typedef struct v1_validation_rule_t {
    char *field_path; // string
    char *message; // string
    char *message_expression; // string
    int optional_old_self; //boolean
    char *reason; // string
    char *rule; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_validation_rule_t;

__attribute__((deprecated)) v1_validation_rule_t *v1_validation_rule_create(
    char *field_path,
    char *message,
    char *message_expression,
    int optional_old_self,
    char *reason,
    char *rule
);

void v1_validation_rule_free(v1_validation_rule_t *v1_validation_rule);

v1_validation_rule_t *v1_validation_rule_parseFromJSON(cJSON *v1_validation_ruleJSON);

cJSON *v1_validation_rule_convertToJSON(v1_validation_rule_t *v1_validation_rule);

#endif /* _v1_validation_rule_H_ */

