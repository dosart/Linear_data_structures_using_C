//
// Created by dosart on 04.05.2021.
//

#include "../include/function.h"
#include "../include/vector.h"

#include <assert.h>

extern int test_cmp(void *x, void *y);

void test_foreach_function(void *item) {
  int *p = (int *)item;
  *p = *p * 2;
}

void test_foreach() {
  printf("test_foreach\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  vector_foreach(&v, test_foreach_function);

  int key0 = 0;
  int key1 = 2;
  int key2 = 4;
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 1);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 2);
}

int test_filter_function(void *item) {
  int value = *(int *)item;
  return value % 2 == 0 ? 1 : 0;
}

void test_filter() {
  printf("test_filter\n");
  int args[] = {0, 1, 2, 3, 4, 5};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);
  vector_push_back(&v, (void *)&args[3]);
  vector_push_back(&v, (void *)&args[4]);

  vector_t out = vector_filter(&v, test_filter_function);
  assert(out.size == 3);
}