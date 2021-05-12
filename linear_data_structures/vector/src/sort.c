#include "../include/sort.h"

void vector_bubble_sort(vector_t *v, int (*cmp)(void *, void *)) {
  unsigned int swapped = 1;
  while (swapped) {
    swapped = 0;
    for (size_t i = 1; i < v->size; ++i) {
      void *x = vector_get(v, i);
      void *y = vector_get(v, i - 1);

      if (cmp(y, x)) {
        vector_swap(v, i, i - 1, v->elem_size);
        swapped = 1;
      }
    }
  }
}
