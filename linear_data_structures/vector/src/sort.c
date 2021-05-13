#include "../include/sort.h"

void vector_bubble_sort(vector_t *v, int (*cmp)(void *, void *)) {
  unsigned int swapped = 1;
  while (swapped) {
    swapped = 0;
    for (size_t i = 1; i < v->size; ++i) {
      void *x = vector_get(v, i);
      void *y = vector_get(v, i - 1);

      if (cmp(x, y)) {
        vector_swap(v, i, i - 1, v->elem_size);
        swapped = 1;
      }
    }
  }
}

void vector_insertion_sort(vector_t *v, int (*cmp)(void *, void *)) {
  for (size_t i = 1; i < v->size; ++i) {
    size_t j = i;
    // while j > 0 and v->data[j - 1] < v->data[j]
    while (j > 0 && cmp(vector_get(v, i - 1), vector_get(v, i))) {
      vector_swap(v, i - 1, i, v->elem_size);
      j--;
    }
  }
}
