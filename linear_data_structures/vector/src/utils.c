//
// Created by dosart on 03.05.2021.
//

#include "../include/utils.h"

void *get_item(vector_t *v, size_t index) {
  return (char *)v->data + index * v->elem_size;
}