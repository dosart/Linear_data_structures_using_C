//
// Created by dosart on 25.04.2021.
//

#include "test_vector.h"

void test_delete(void *key) { *(int *)key = 0; }

extern void test_foreach();
extern void test_filter();

int main() {
  test_vector_init_zero_size();
  test_vector_init();

  test_vector_push_back1();
  test_vector_push_back2();

  test_vector_get1();
  test_vector_get2();

  test_vector_set1();
  test_vector_set2();

  test_vector_find1();
  test_vector_find2();
  test_vector_find3();
  test_vector_find4();

  test_vector_delete_by_index1();
  test_vector_delete_by_index2();
  test_vector_delete_by_index3();

  test_vector_delete_by_value1();
  test_vector_delete_by_value2();
  test_vector_delete_by_value3();
  test_vector_delete_by_value4();

  test_vector_insert_by_index1();
  test_vector_insert_by_index2();
  test_vector_insert_by_index3();
  test_vector_insert_by_index4();
  test_vector_insert_by_index5();

  test_foreach();
  test_filter();
}

void test_vector_init_zero_size() {
  printf("test_vector_init_zero_size\n");

  vector_t v;
  vector_init(&v, 0, 0);

  assert(v.size == 0);
  assert(vector_size(&v) == 0);
  assert(vector_is_empty(&v) == 1);
  assert(v.capacity == 0);

  vector_free(&v, test_delete);
}

void test_vector_init() {
  printf("test_vector_init\n");

  vector_t v;
  vector_init(&v, 16, 0);

  assert(v.size == 0);
  assert(vector_size(&v) == 0);
  assert(vector_is_empty(&v) == 1);
  assert(v.capacity == 16);

  vector_free(&v, test_delete);
}

void test_vector_push_back1() {
  printf("test_vector_push_back1\n");

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  int x = 1;
  vector_push_back(&v, (void *)&x);

  assert(v.size == 1);
  assert(vector_is_empty(&v) == 0);
  assert(vector_size(&v) == 1);
  assert(v.capacity == 16);

  vector_free(&v, test_delete);
}

void test_vector_push_back2() {
  printf("test_vector_push_back2\n");

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  int x = 1;
  vector_push_back(&v, (void *)&x);
  vector_push_back(&v, (void *)&x);

  assert(v.size == 2);
  assert(vector_is_empty(&v) == 0);
  assert(vector_size(&v) == 2);
  assert(v.capacity == 16);
  assert(*((int *)((char *)v.data + 0 * sizeof(int))) == 1);
  assert(*((int *)((char *)v.data + 1 * sizeof(int))) == 1);

  vector_free(&v, test_delete);
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

  vector_free(&v, test_delete);
}

void test_vector_get2() {
  printf("test_vector_get2\n");

  vector_t v;
  vector_init(&v, 2, sizeof(int));

  int *item = (int *)vector_get(&v, 0);
  assert(item == NULL);

  vector_free(&v, test_delete);
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

  vector_free(&v, test_delete);
}

void test_vector_set2() {
  printf("test_vector_set2\n");

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  assert(vector_get(&v, 10) == NULL);

  vector_free(&v, test_delete);
}

int test_cmp(void *x, void *y) {
  int ix = *(int *)x;
  int iy = *(int *)y;

  return ix == iy;
}

void test_vector_find1() {
  printf("test_vector_find1\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);
  int key = 0;

  assert(vector_find(&v, (void *)&key, test_cmp) == 0);

  vector_free(&v, test_delete);
}
void test_vector_find2() {
  printf("test_vector_find2\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);
  int key = 1;

  assert(vector_find(&v, (void *)&key, test_cmp) == 1);

  vector_free(&v, test_delete);
}

void test_vector_find3() {
  printf("test_vector_find3\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);
  int key = 2;

  assert(vector_find(&v, (void *)&key, test_cmp) == 2);

  vector_free(&v, test_delete);
}
void test_vector_find4() {
  printf("test_vector_find4\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);
  int key = 3;

  assert(vector_find(&v, (void *)&key, test_cmp) == -1);

  vector_free(&v, test_delete);
}

void test_vector_delete_by_index1() {
  printf("test_vector_delete_by_index1\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  vector_delete_by_index(&v, 0, test_delete);

  assert(v.size == 2);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key0, test_cmp) == -1);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 1);

  vector_free(&v, test_delete);
}
void test_vector_delete_by_index2() {
  printf("test_vector_delete_by_index2\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  vector_delete_by_index(&v, 1, test_delete);

  assert(v.size == 2);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key1, test_cmp) == -1);
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 1);

  vector_free(&v, test_delete);
}
void test_vector_delete_by_index3() {
  printf("test_vector_delete_by_index3\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  vector_delete_by_index(&v, 2, test_delete);

  assert(v.size == 2);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key2, test_cmp) == -1);
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 1);

  vector_free(&v, test_delete);
}
void test_vector_delete_by_index4() {
  printf("test_vector_delete_by_index4\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  vector_delete_by_index(&v, 10, test_delete);

  assert(v.size == 3);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 1);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 2);

  vector_free(&v, test_delete);
}

void test_vector_delete_by_value1() {
  printf("test_vector_delete_by_value1\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  vector_delete_by_value(&v, (void *)&args[0], test_cmp, test_delete);

  assert(v.size == 2);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key0, test_cmp) == -1);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 1);

  vector_free(&v, test_delete);
}
void test_vector_delete_by_value2() {
  printf("test_vector_delete_by_value2\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  vector_delete_by_value(&v, (void *)&args[1], test_cmp, test_delete);

  assert(v.size == 2);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key1, test_cmp) == -1);
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 1);

  vector_free(&v, test_delete);
}
void test_vector_delete_by_value3() {
  printf("test_vector_delete_by_value3\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  vector_delete_by_value(&v, (void *)&args[2], test_cmp, test_delete);

  assert(v.size == 2);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key2, test_cmp) == -1);
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 1);

  vector_free(&v, test_delete);
}
void test_vector_delete_by_value4() {
  printf("test_vector_delete_by_value4\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  int for_delete = 100;
  vector_delete_by_value(&v, (void *)&for_delete, test_cmp, test_delete);

  assert(v.size == 3);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 1);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 2);

  vector_free(&v, test_delete);
}

void test_vector_insert_by_index1() {
  printf("test_vector_insert_by_index1\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  int item = 100;
  vector_insert_by_index(&v, 1, (void *)&item);

  assert(v.size == 4);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 2);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 3);
  assert(vector_find(&v, (void *)&item, test_cmp) == 1);

  vector_free(&v, test_delete);
}
void test_vector_insert_by_index2() {
  printf("test_vector_insert_by_index2\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  int item = 100;
  vector_insert_by_index(&v, 2, (void *)&item);

  assert(v.size == 4);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 1);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 3);
  assert(vector_find(&v, (void *)&item, test_cmp) == 2);

  vector_free(&v, test_delete);
}
void test_vector_insert_by_index3() {
  printf("test_vector_insert_by_index3\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  int item = 100;
  vector_insert_by_index(&v, 3, (void *)&item);

  assert(v.size == 4);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 1);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 2);
  assert(vector_find(&v, (void *)&item, test_cmp) == 3);

  vector_free(&v, test_delete);
}
void test_vector_insert_by_index4() {
  printf("test_vector_insert_by_index4\n");
  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  int item = 100;
  vector_insert_by_index(&v, 100, (void *)&item);

  assert(v.size == 3);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key0, test_cmp) == 0);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 1);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 2);
  assert(vector_find(&v, (void *)&item, test_cmp) == -1);

  vector_free(&v, test_delete);
}
void test_vector_insert_by_index5() {
  printf("test_vector_insert_by_index5\n");

  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  int item = 100;
  vector_insert_by_index(&v, 0, (void *)&item);

  assert(v.size == 4);
  assert(vector_is_empty(&v) == 0);
  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  assert(vector_find(&v, (void *)&key0, test_cmp) == 1);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 2);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 3);
  assert(vector_find(&v, (void *)&item, test_cmp) == 0);

  vector_free(&v, test_delete);
}
