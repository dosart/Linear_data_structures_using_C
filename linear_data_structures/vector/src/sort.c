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
  size_t j = 0;
  for (size_t i = 1; i < v->size; ++i) {
    j = i;
    while (j > 0 && cmp(vector_get(v, j), vector_get(v, j - 1))) {
      vector_swap(v, j - 1, j, v->elem_size);
      j--;
    }
  }
}

size_t vector_partition(vector_t* v, size_t start, size_t end, int (*cmp)(void*, void*)) {
    void* pivot = vector_get(v, end);
    size_t pivot_idx = start;

    for (size_t i = start; i < end; ++i) {
        void* current = vector_get(v, i);
        if (cmp(current, pivot)) {
            vector_swap(v, i, pivot_idx, v->elem_size);
            pivot_idx++;
        }
    }
    vector_swap(v, end, pivot_idx, v->elem_size);
    return pivot_idx;
}

static  void quick_sort(vector_t* v, size_t start, size_t end,  int (*cmp)(void*, void*)) {
     if (start < end) {
         size_t pivot_idx = vector_partition(v, start, end, cmp);
         quick_sort(v, start, pivot_idx - 1, cmp);
         quick_sort(v, pivot_idx + 1, end, cmp);
     }
 }

void vector_quick_sort(vector_t* v, int (*cmp)(void*, void*)) {
    quick_sort(v, 0, v->size - 1, cmp);
}
