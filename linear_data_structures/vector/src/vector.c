#include "../include/vector.h"

void vector_init(vector_t *v, size_t capacity, size_t elem_size) {
  if (v != NULL) {
    v->data = malloc(sizeof(void *) * v->capacity);
    v->elem_size = elem_size;
    v->capacity = capacity;
    v->size = 0;
  }
}

void vector_free(vector_t *vector) {
  if (vector != NULL) {
    free(vector->data);
    vector->capacity = 0;
    vector->size = 0;
  }
}

static void vector_resize(vector_t *v, size_t capacity) {
  if (capacity == 0)
    capacity = 16;
  v->data = realloc(v->data, sizeof(void *) * capacity);
  v->capacity = capacity;
}

static void set_item(vector_t *v, size_t index, void *item) {
  memcpy(((char *)v->data) + index * v->elem_size, item, v->elem_size);
}

void vector_push_back(vector_t *v, void *elem) {
  if (v != NULL) {
    if (v->size == v->capacity)
      vector_resize(v, v->capacity * 2);
    set_item(v, v->size, elem);
    v->size += 1;
  }
}

void *vector_get(vector_t *v, size_t index) {
  if (v != NULL) {
    if (index < v->size) {
      return (char *)v->data + index * v->elem_size;
    }
  }
  return NULL;
}
