#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_queuing_configuration.h"



static v1_queuing_configuration_t *v1_queuing_configuration_create_internal(
    int hand_size,
    int queue_length_limit,
    int queues
    ) {
    v1_queuing_configuration_t *v1_queuing_configuration_local_var = malloc(sizeof(v1_queuing_configuration_t));
    if (!v1_queuing_configuration_local_var) {
        return NULL;
    }
    v1_queuing_configuration_local_var->hand_size = hand_size;
    v1_queuing_configuration_local_var->queue_length_limit = queue_length_limit;
    v1_queuing_configuration_local_var->queues = queues;

    v1_queuing_configuration_local_var->_library_owned = 1;
    return v1_queuing_configuration_local_var;
}

__attribute__((deprecated)) v1_queuing_configuration_t *v1_queuing_configuration_create(
    int hand_size,
    int queue_length_limit,
    int queues
    ) {
    return v1_queuing_configuration_create_internal (
        hand_size,
        queue_length_limit,
        queues
        );
}

void v1_queuing_configuration_free(v1_queuing_configuration_t *v1_queuing_configuration) {
    if(NULL == v1_queuing_configuration){
        return ;
    }
    if(v1_queuing_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_queuing_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    free(v1_queuing_configuration);
}

cJSON *v1_queuing_configuration_convertToJSON(v1_queuing_configuration_t *v1_queuing_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1_queuing_configuration->hand_size
    if(v1_queuing_configuration->hand_size) {
    if(cJSON_AddNumberToObject(item, "handSize", v1_queuing_configuration->hand_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_queuing_configuration->queue_length_limit
    if(v1_queuing_configuration->queue_length_limit) {
    if(cJSON_AddNumberToObject(item, "queueLengthLimit", v1_queuing_configuration->queue_length_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_queuing_configuration->queues
    if(v1_queuing_configuration->queues) {
    if(cJSON_AddNumberToObject(item, "queues", v1_queuing_configuration->queues) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_queuing_configuration_t *v1_queuing_configuration_parseFromJSON(cJSON *v1_queuing_configurationJSON){

    v1_queuing_configuration_t *v1_queuing_configuration_local_var = NULL;

    // v1_queuing_configuration->hand_size
    cJSON *hand_size = cJSON_GetObjectItemCaseSensitive(v1_queuing_configurationJSON, "handSize");
    if (cJSON_IsNull(hand_size)) {
        hand_size = NULL;
    }
    if (hand_size) { 
    if(!cJSON_IsNumber(hand_size))
    {
    goto end; //Numeric
    }
    }

    // v1_queuing_configuration->queue_length_limit
    cJSON *queue_length_limit = cJSON_GetObjectItemCaseSensitive(v1_queuing_configurationJSON, "queueLengthLimit");
    if (cJSON_IsNull(queue_length_limit)) {
        queue_length_limit = NULL;
    }
    if (queue_length_limit) { 
    if(!cJSON_IsNumber(queue_length_limit))
    {
    goto end; //Numeric
    }
    }

    // v1_queuing_configuration->queues
    cJSON *queues = cJSON_GetObjectItemCaseSensitive(v1_queuing_configurationJSON, "queues");
    if (cJSON_IsNull(queues)) {
        queues = NULL;
    }
    if (queues) { 
    if(!cJSON_IsNumber(queues))
    {
    goto end; //Numeric
    }
    }


    v1_queuing_configuration_local_var = v1_queuing_configuration_create_internal (
        hand_size ? hand_size->valuedouble : 0,
        queue_length_limit ? queue_length_limit->valuedouble : 0,
        queues ? queues->valuedouble : 0
        );

    return v1_queuing_configuration_local_var;
end:
    return NULL;

}
