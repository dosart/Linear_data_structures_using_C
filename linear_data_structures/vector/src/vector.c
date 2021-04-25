#include "../include/vector.h"

vector_t *vector_make(size_t capacity) {
  vector_t *vector = malloc(sizeof(vector_t));
  if (vector != NULL) {
    if (capacity == 0)
      capacity = 16;
    vector->data = malloc(sizeof(int) * capacity);
    vector->size = 0
    vector->capacity = capacity;
  }
  return vector;
}
