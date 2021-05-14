//
// Created by dosart on 12.05.2021.
//

#include "../include/sort.h"
#include "../include/vector.h"

#include <assert.h>

typedef struct sort_test_item {
  void (*sort)(vector_t *v, int (*cmp)(void *, void *));
  int (*cmp)(void *, void *);
  char *message;
} sort_test_item;

int cmp_sort(void *x, void *y) {
  int int_x = *(int *)x;
  int int_y = *(int *)y;

  if (int_x < int_y)
    return 1;
  else
    return 0;
}

void test_delete2(void *key) { *(int *)key = 0; }

void test_vector_sort0(sort_test_item *item);
void test_vector_sort1(sort_test_item *item);
void test_vector_sort2(sort_test_item *item);
void test_vector_sort3(sort_test_item *item);
void test_vector_sort4(sort_test_item *item);

extern int cmp_linear_search(void *, void *);

void test_sort() {
  struct sort_test_item bubble_sort_item = {
      .sort = vector_bubble_sort, .cmp = cmp_sort, .message = "Bubble sort"};

  struct sort_test_item insertion_sort_item = {.sort = vector_insertion_sort,
                                               .cmp = cmp_sort,
                                               .message = "Insertion sort"};

  struct sort_test_item sort_test_items[] = {bubble_sort_item,
                                             insertion_sort_item};
  for (unsigned short i = 0; i < 2; ++i) {
    test_vector_sort0(&sort_test_items[i]);
    test_vector_sort1(&sort_test_items[i]);
    test_vector_sort2(&sort_test_items[i]);
    test_vector_sort3(&sort_test_items[i]);
    test_vector_sort4(&sort_test_items[i]);
  }
}

void test_vector_sort0(sort_test_item *item) {
  printf("test_vector_sort0 %s\n", item->message);

  int args[] = {1, 0, 4, 3, 0, 2, 10};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);
  vector_push_back(&v, (void *)&args[3]);
  vector_push_back(&v, (void *)&args[4]);
  vector_push_back(&v, (void *)&args[5]);
  vector_push_back(&v, (void *)&args[6]);

  item->sort(&v, item->cmp);

  int key0 = 0;
  int key1 = 1;
  int key2 = 2;
  int key3 = 3;
  int key4 = 4;
  int key5 = 10;

  assert(vector_find(&v, (void *)&key0, cmp_linear_search) == 0);
  assert(vector_find(&v, (void *)&key1, cmp_linear_search) == 2);
  assert(vector_find(&v, (void *)&key2, cmp_linear_search) == 3);
  assert(vector_find(&v, (void *)&key3, cmp_linear_search) == 4);
  assert(vector_find(&v, (void *)&key4, cmp_linear_search) == 5);
  assert(vector_find(&v, (void *)&key5, cmp_linear_search) == 6);

  vector_free(&v, test_delete2);
}

void test_vector_sort1(sort_test_item *item) {
  printf("test_vector_sort1 %s\n", item->message);

  int args[3] = {1, 0, 4};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  item->sort(&v, item->cmp);

  int key0 = 0;
  int key1 = 1;
  int key2 = 4;

  assert(vector_find(&v, (void *)&key0, cmp_linear_search) == 0);
  assert(vector_find(&v, (void *)&key1, cmp_linear_search) == 1);
  assert(vector_find(&v, (void *)&key2, cmp_linear_search) == 2);

  vector_free(&v, test_delete2);
}

void test_vector_sort2(sort_test_item *item) {
  printf("test_vector_sort2 %s\n", item->message);

  int args[3] = {0, 1, 2};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  item->sort(&v, item->cmp);

  int key0 = 0;
  int key1 = 1;
  int key2 = 2;

  assert(vector_find(&v, (void *)&key0, cmp_linear_search) == 0);
  assert(vector_find(&v, (void *)&key1, cmp_linear_search) == 1);
  assert(vector_find(&v, (void *)&key2, cmp_linear_search) == 2);

  vector_free(&v, test_delete2);
}

void test_vector_sort3(sort_test_item *item) {
  printf("test_vector_sort3 %s\n", item->message);

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  item->sort(&v, item->cmp);

  assert(vector_size(&v) == 0);
  assert(vector_is_empty(&v) == 1);

  vector_free(&v, test_delete2);
}

void test_vector_sort4(sort_test_item *item) {
  printf("test_vector_sort4 %s\n", item->message);

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  int key = 0;
  vector_push_back(&v, (void *)&key);

  item->sort(&v, item->cmp);

  assert(vector_find(&v, (void *)&key, cmp_linear_search) == 0);
  assert(vector_size(&v) == 1);
  assert(vector_is_empty(&v) == 0);

  vector_free(&v, test_delete2);
}