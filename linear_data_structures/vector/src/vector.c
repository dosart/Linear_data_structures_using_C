#include "../include/vector.h"

vector_t vector_make(size_t capacity) {
  if (capacity == 0)
    capacity = 16;
  vector_t vector;
  vector.data = malloc(sizeof(int) * capacity);
  vector.size = 0;
  vector.capacity = capacity;
  return vector;
}

void vector_free(vector_t *vector) {
  if (vector != NULL) {
    free(vector->data);
    vector->capacity = 0;
    vector->size = 0;
  }
}
