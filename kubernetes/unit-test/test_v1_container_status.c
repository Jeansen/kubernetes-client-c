#ifndef v1_container_status_TEST
#define v1_container_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_container_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_container_status.h"
v1_container_status_t* instantiate_v1_container_status(int include_optional);

#include "test_v1_container_state.c"
#include "test_v1_resource_requirements.c"
#include "test_v1_container_state.c"
#include "test_v1_container_user.c"


v1_container_status_t* instantiate_v1_container_status(int include_optional) {
  v1_container_status_t* v1_container_status = NULL;
  if (include_optional) {
    v1_container_status = v1_container_status_create(
      list_createList(),
      list_createList(),
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_container_state(0),
      "0",
      1,
       // false, not to have infinite recursion
      instantiate_v1_resource_requirements(0),
      56,
      1,
       // false, not to have infinite recursion
      instantiate_v1_container_state(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_container_user(0),
      list_createList()
    );
  } else {
    v1_container_status = v1_container_status_create(
      list_createList(),
      list_createList(),
      "0",
      "0",
      "0",
      NULL,
      "0",
      1,
      NULL,
      56,
      1,
      NULL,
      "0",
      NULL,
      list_createList()
    );
  }

  return v1_container_status;
}


#ifdef v1_container_status_MAIN

void test_v1_container_status(int include_optional) {
    v1_container_status_t* v1_container_status_1 = instantiate_v1_container_status(include_optional);

	cJSON* jsonv1_container_status_1 = v1_container_status_convertToJSON(v1_container_status_1);
	printf("v1_container_status :\n%s\n", cJSON_Print(jsonv1_container_status_1));
	v1_container_status_t* v1_container_status_2 = v1_container_status_parseFromJSON(jsonv1_container_status_1);
	cJSON* jsonv1_container_status_2 = v1_container_status_convertToJSON(v1_container_status_2);
	printf("repeating v1_container_status:\n%s\n", cJSON_Print(jsonv1_container_status_2));
}

int main() {
  test_v1_container_status(1);
  test_v1_container_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_container_status_MAIN
#endif // v1_container_status_TEST
