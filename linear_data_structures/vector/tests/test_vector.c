//
// Created by dosart on 25.04.2021.
//
#include "../include/vector.h"
#include <assert.h>
#include <stdio.h>

void test_vector_init_zero_size();
void test_vector_init();

void test_vector_push_back1();
void test_vector_push_back2();

void test_vector_get1();
void test_vector_get2();

void test_vector_set1();
void test_vector_set2();

int main() {
  test_vector_init_zero_size();
  test_vector_init();

  test_vector_push_back1();
  test_vector_push_back2();

  test_vector_get1();
  test_vector_get2();

  test_vector_set1();
  test_vector_set2();
}

void test_vector_init_zero_size() {
  printf("test_vector_init_zero_size\n");

  vector_t v;
  vector_init(&v, 0, 0);

  assert(v.size == 0);
  assert(v.capacity == 0);

  vector_free(&v);
}

void test_vector_init() {
  printf("test_vector_init\n");

  vector_t v;
  vector_init(&v, 16, 0);

  assert(v.size == 0);
  assert(v.capacity == 16);

  vector_free(&v);
}

void test_vector_push_back1() {
  printf("test_vector_push_back1\n");

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  int x = 1;
  vector_push_back(&v, (void *)&x);

  assert(v.size == 1);
  assert(v.capacity == 16);

  vector_free(&v);
}

void test_vector_push_back2() {
  printf("test_vector_push_back2\n");

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  int x = 1;
  vector_push_back(&v, (void *)&x);
  vector_push_back(&v, (void *)&x);

  assert(v.size == 2);
  assert(v.capacity == 16);
  assert(*((int *)((char *)v.data + 0 * sizeof(int))) == 1);
  assert(*((int *)((char *)v.data + 1 * sizeof(int))) == 1);

  vector_free(&v);
}

void test_vector_get1() {
  printf("test_vector_get1\n");

  vector_t v;
  vector_init(&v, 4, sizeof(int));

  *((int *)((char *)v.data + 0 * sizeof(int))) = 1;
  v.size = 1;

  void *item = vector_get(&v, 0);
  int y = *((int *)item);

  assert(y == 1);

  vector_free(&v);
}

void test_vector_get2() {
  printf("test_vector_get2\n");

  vector_t v;
  vector_init(&v, 2, sizeof(int));

  int *item = (int *)vector_get(&v, 0);
  assert(item == NULL);

  vector_free(&v);
}

void test_vector_set1() {
  printf("test_vector_set1\n");

  vector_t v;
  vector_init(&v, 0, sizeof(int));
  int one = 1;
  int two = 2;
  vector_push_back(&v, (void *)&one);
  vector_push_back(&v, (void *)&two);

  one += 1;
  two += 1;
  vector_set(&v, 0, (void *)&(one));
  vector_set(&v, 1, (void *)&(two));

  assert(*(int *)vector_get(&v, 0) == one);
  assert(*(int *)vector_get(&v, 1) == two);

  vector_free(&v);
}

void test_vector_set2() {
  printf("test_vector_set2\n");

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  assert(vector_get(&v, 10) == NULL);

  vector_free(&v);
}
