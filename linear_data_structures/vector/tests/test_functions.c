//
// Created by dosart on 04.05.2021.
//

#include "../include/functions.h"
#include "../include/vector.h"

#include <assert.h>

extern int comporator_for_linear_search(void *x, void *y);
extern void test_delete(void *key);

void test_foreach_function(void *item) {
  int *p = (int *)item;
  *p = *p * 2;
}

int test_cmp1(void *x, void *y) {
  int int_x = *(int *)x;
  int int_y = *(int *)y;

  return int_x == int_y;
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
  assert(vector_find(&v, (void *)&key0, test_cmp1) == 0);
  assert(vector_find(&v, (void *)&key1, test_cmp1) == 1);
  assert(vector_find(&v, (void *)&key2, test_cmp1) == 2);

  vector_free(&v, test_delete);
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

  int key0 = 0;
  int key1 = 2;
  int key2 = 4;
  assert(vector_find(&out, (void *)&key0, test_cmp1) == 0);
  assert(vector_find(&out, (void *)&key1, test_cmp1) == 1);
  assert(vector_find(&out, (void *)&key2, test_cmp1) == 2);

  vector_free(&v, test_delete);
  vector_free(&out, test_delete);
}

void test_any() {
  printf("test_any\n");
  int args[] = {0, 1, 2, 3, 4, 5};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);
  vector_push_back(&v, (void *)&args[3]);
  vector_push_back(&v, (void *)&args[4]);

  int result = vector_any(&v, test_filter_function);
  assert(result == 1);

  vector_free(&v, test_delete);
}

void test_sum(void *acc, void *arg) {
  int x = *(int *)acc;
  int y = *(int *)arg;

  *(int *)acc = x + y;
}

void test_fold() {
  printf("test_fold\n");
  int args[] = {0, 1, 2, 3, 4, 5};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);
  vector_push_back(&v, (void *)&args[3]);
  vector_push_back(&v, (void *)&args[4]);
  vector_push_back(&v, (void *)&args[5]);
  int result = 0;

  vector_fold(&v, (void *)&result, test_sum);
  assert(result == 15);

  vector_free(&v, test_delete);
}