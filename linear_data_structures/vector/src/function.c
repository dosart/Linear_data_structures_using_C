//
// Created by dosart on 03.05.2021.
//

#include "../include/function.h"
#include "../include/utils.h"

void vector_foreach(vector_t *v, void (*f)(void *)) {
  if (v != NULL) {
    for (size_t i = 0; i < v->size; ++i) {
      f(get_item(v, i));
    }
  }
}

vector_t vector_filter(vector_t *v, int (*pred)(void *)) {
  vector_t out;
  vector_null(&out);
  if (v != NULL) {
    vector_init(&out, 0, v->elem_size);
    for (size_t i = 0; i < v->size; ++i) {
      if (pred(get_item(v, i))) {
        vector_push_back(&out, get_item(v, i));
      }
    }
    return out;
  }
  return out;
}
