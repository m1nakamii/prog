#include "IntVector.h"
#include <stddef.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 10

IntVector *int_vector_new(size_t initial_capacity) {
  IntVector *v = (IntVector *)malloc(sizeof(IntVector));
  if (v == NULL) {
    return NULL;
  }

  v->data = (int *)malloc(initial_capacity * sizeof(int));
  if (v->data == NULL) {
    free(v);
    return NULL;
  }

  v->size = 0;
  v->capacity = initial_capacity;
  return v;
}

void int_vector_free(IntVector *v) {
  if (v != NULL) {
    free(v->data);
    free(v);
  }
}

int int_vector_get_item(const IntVector *v, size_t index) {
  return v->data[index];
}

void int_vector_set_item(IntVector *v, size_t index, int value) {
  v->data[index] = value;
}

size_t int_vector_get_size(const IntVector *v) { return v->size; }

size_t int_vector_get_capacity(const IntVector *v) { return v->capacity; }

void int_vector_reserve(IntVector *v, size_t capacity) {
  if (v->capacity < capacity) {
    int *new_data = (int *)realloc(v->data, capacity * sizeof(int));
    if (new_data == NULL) {
      return;
    }
    v->data = new_data;
    v->capacity = capacity;
  }
}

void int_vector_push_back(IntVector *v, int item) {
  if (v->size >= v->capacity) {
    size_t new_capacity = v->capacity == 0 ? INITIAL_CAPACITY : v->capacity * 2;
    int_vector_reserve(v, new_capacity);
  }
  v->data[v->size++] = item;
}

void int_vector_pop_back(IntVector *v) {
  if (v->size > 0) {
    --v->size;
  }
}

void int_vector_resize(IntVector *v, size_t new_size) {
  if (new_size > v->capacity) {
    int_vector_reserve(v, new_size);
  }
  v->size = new_size;
}

void int_vector_clear(IntVector *v) { v->size = 0; }
