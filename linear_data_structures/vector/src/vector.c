#include "../include/vector.h"
#include "../include/utils.h"

void vector_init(vector_t *v, size_t capacity, size_t elem_size) {
  if (v != NULL) {
    v->data = malloc(elem_size * v->capacity);
    v->elem_size = elem_size;
    v->capacity = capacity;
    v->size = 0;
  }
}

void vector_null(vector_t *v) {
  v->size = v->capacity = v->elem_size = 0;
  v->data = NULL;
}

void vector_free(vector_t *vector, void (*deleter)(void *)) {
  if (vector != NULL) {
    for (size_t i = 0; i < vector->size; ++i) {
      deleter(get_item(vector, i));
    }
    free(vector->data);
    vector->capacity = 0;
    vector->size = 0;
  }
}

static void vector_resize(vector_t *v, size_t capacity) {
  if (capacity == 0)
    capacity = 16;
  v->data = realloc(v->data, v->elem_size * capacity);
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
    v->size++;
  }
}

static void copy(vector_t *v, size_t destination_index, size_t source_index) {
  memcpy((char *)v->data + destination_index * v->elem_size,
         (char *)v->data + source_index * v->elem_size, v->elem_size);
}

void vector_insert_by_index(vector_t *v, size_t index, void *elem) {
  if (v != NULL) {
    if (index > v->size)
      return;
    if (v->size == v->capacity)
      vector_resize(v, v->capacity * 2);
    long long size = v->size;
    long long _index = index;
    for (long long i = size - 1; i >= _index; --i)
      // v->data[i + 1] = v->data[i]
      copy(v, i + 1, i);
    set_item(v, index, elem);
    v->size++;
  }
}

static void shift_left(vector_t *v, size_t index_start) {
  for (size_t i = index_start; i < v->size; ++i) {
    copy(v, i, i + 1);
  }
}

static void maybe_reduce_capacity(vector_t *v) {
  if (v->size > 0 && v->size == v->capacity / 4)
    vector_resize(v, v->capacity / 2);
}

void vector_delete_by_value(vector_t *v, void *key, int (*cmp)(void *, void *),
                            void (*delete)(void *)) {
  if (v != NULL) {
    long long start_index_for_delete = vector_find(v, key, cmp);
    if (start_index_for_delete == -1)
      return;
    size_t i = start_index_for_delete;
    while (i < v->size) {
      if (cmp(key, get_item(v, i)))
        delete (get_item(v, i));
      i++;
    }
    v->size--;
    shift_left(v, start_index_for_delete);
    maybe_reduce_capacity(v);
  }
}

void vector_delete_by_index(vector_t *v, size_t index, void (*delete)(void *)) {
  if (v != NULL) {
    if (index < v->size) {
      delete (get_item(v, index));
      v->size--;
      shift_left(v, index);
      maybe_reduce_capacity(v);
    }
  }
}

void *vector_get(vector_t *v, size_t index) {
  if (v != NULL) {
    if (index < v->size) {
      return get_item(v, index);
    }
  }
  return NULL;
}

void vector_set(vector_t *v, size_t index, void *elem) {
  if (v != NULL) {
    if (index < v->size) {
      set_item(v, index, elem);
    }
  }
}

size_t vector_size(vector_t *v) {
  if (v != NULL) {
    return v->size;
  }
  return 0;
}

size_t vector_is_empty(vector_t *v) {
  if (v != NULL) {
    return v->size == 0 ? 1 : 0;
  }
  return 0;
}

long long vector_find(vector_t *v, void *key, int (*cmp)(void *, void *)) {
  if (v != NULL) {
    for (size_t i = 0; i < v->size; i++) {
      void *current = (char *)v->data + i * v->elem_size;
      if (cmp(current, key))
        return i;
    }
    return -1;
  }
  return -1;
}
