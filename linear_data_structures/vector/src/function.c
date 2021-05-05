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
