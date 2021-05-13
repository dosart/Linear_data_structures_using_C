//
// Created by dosart on 03.05.2021.
//

#include "../include/utils.h"

void *get_item(vector_t *v, size_t index) {
  return (char *)v->data + index * v->elem_size;
}

void swap(void *a, void *b, size_t size) {
  char tmp;
  size_t i;
  for (i = 0; i < size; i++) {
    tmp = *((char *)b + i);
    *((char *)b + i) = *((char *)a + i);
    *((char *)a + i) = tmp;
  }
}

void vector_swap(vector_t *v, size_t index1, size_t index2, size_t elem_size) {
  swap(vector_get(v, index1), vector_get(v, index2), elem_size);
}
