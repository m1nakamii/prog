#include "IntVector.h"
#include <stdio.h>

int main() {
  IntVector *v = int_vector_new(0);
  if (v == NULL) {
    printf("Failed to allocate memory\n");
    return 1;
  }
  int_vector_push_back(v, 1);
  int_vector_push_back(v, 2);
  int_vector_push_back(v, 3);

  printf("Size: %ld, Capacity: %ld\n", int_vector_get_size(v),
         int_vector_get_capacity(v));
  for (size_t i = 0; i < int_vector_get_size(v); i++) {
    printf("%d ", int_vector_get_item(v, i));
  }
  printf("\n");

  int_vector_pop_back(v);
  int_vector_pop_back(v);

  int_vector_set_item(v, 0, 4);

  int_vector_resize(v, 5);
  int_vector_set_item(v, 4, 5);

  printf("Size: %ld, Capacity: %ld\n", int_vector_get_size(v),
         int_vector_get_capacity(v));
  for (size_t i = 0; i < int_vector_get_size(v); i++) {
    printf("%d ", int_vector_get_item(v, i));
  }
  printf("\n");

  int_vector_free(v);

  return 0;
}