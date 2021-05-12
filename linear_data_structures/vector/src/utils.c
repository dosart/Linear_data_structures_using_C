//
// Created by dosart on 03.05.2021.
//

#include "../include/utils.h"

void *get_item(vector_t *v, size_t index) {
  return (char *)v->data + index * v->elem_size;
}

void vector_swap(vector_t *v, size_t index1, size_t index2, size_t elem_size) {
  char tmp;
  for (size_t i = 0; i < elem_size; ++i) {
    tmp = *(char *)((char *)v->data + index1 + i);
    *(char *)((char *)v->data + index1 + i) =
        *(char *)((char *)v->data + index2 + i);
    *(char *)((char *)v->data + index1 + i) = tmp;
  }
}