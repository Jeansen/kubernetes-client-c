#ifndef v1alpha3_allocated_device_status_TEST
#define v1alpha3_allocated_device_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_allocated_device_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_allocated_device_status.h"
v1alpha3_allocated_device_status_t* instantiate_v1alpha3_allocated_device_status(int include_optional);

#include "test_v1alpha3_network_device_data.c"


v1alpha3_allocated_device_status_t* instantiate_v1alpha3_allocated_device_status(int include_optional) {
  v1alpha3_allocated_device_status_t* v1alpha3_allocated_device_status = NULL;
  if (include_optional) {
    v1alpha3_allocated_device_status = v1alpha3_allocated_device_status_create(
      list_createList(),
      0,
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1alpha3_network_device_data(0),
      "0"
    );
  } else {
    v1alpha3_allocated_device_status = v1alpha3_allocated_device_status_create(
      list_createList(),
      0,
      "0",
      "0",
      NULL,
      "0"
    );
  }

  return v1alpha3_allocated_device_status;
}


#ifdef v1alpha3_allocated_device_status_MAIN

void test_v1alpha3_allocated_device_status(int include_optional) {
    v1alpha3_allocated_device_status_t* v1alpha3_allocated_device_status_1 = instantiate_v1alpha3_allocated_device_status(include_optional);

	cJSON* jsonv1alpha3_allocated_device_status_1 = v1alpha3_allocated_device_status_convertToJSON(v1alpha3_allocated_device_status_1);
	printf("v1alpha3_allocated_device_status :\n%s\n", cJSON_Print(jsonv1alpha3_allocated_device_status_1));
	v1alpha3_allocated_device_status_t* v1alpha3_allocated_device_status_2 = v1alpha3_allocated_device_status_parseFromJSON(jsonv1alpha3_allocated_device_status_1);
	cJSON* jsonv1alpha3_allocated_device_status_2 = v1alpha3_allocated_device_status_convertToJSON(v1alpha3_allocated_device_status_2);
	printf("repeating v1alpha3_allocated_device_status:\n%s\n", cJSON_Print(jsonv1alpha3_allocated_device_status_2));
}

int main() {
  test_v1alpha3_allocated_device_status(1);
  test_v1alpha3_allocated_device_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_allocated_device_status_MAIN
#endif // v1alpha3_allocated_device_status_TEST
