#include "IntVector.h"
#include <stdio.h>

int main() {
  IntVector *v = int_vector_new(1);

  int_vector_push_back(v, 1);
  int_vector_push_back(v, 2);
  int_vector_push_back(v, 3);
  int_vector_push_back(v, 4);
  int_vector_push_back(v, 5);
  int_vector_push_back(v, 6);
  int_vector_push_back(v, 7);
  int_vector_push_back(v, 8);
  return 0;
}