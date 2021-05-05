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

size_t vector_filter(vector_t *v, int (*pred)(void *), void** out) {
  if (v != NULL) {
      *out = malloc(v->size * v->elem_size);
      char* p_v = (char*)v->data;
      char* p_out = (char*)*out;
      size_t v_i, out_i;
      for (v_i = 0, out_i = 0; v_i < v->size; ++v_i) {
          if (pred(get_item(v, v_i))) {
              memcpy(p_out + out_i * v->elem_size, p_v + v_i * v->elem_size, v->elem_size);
              out_i++;
          }
      }
      *out = realloc(*out, out_i * v->elem_size);
      return out_i;
  }
    return 0;
}
