#include "../include/sort.h"
#include "../include/vector.h"

#include <assert.h>

int cmp(void *a, void *b) { return *(int *)a <= *(int *)b ? 1 : 0; }

extern int test_cmp(void *x, void *y);
extern void test_delete(void *key);

void test_vector_bubble_sort() {
  printf("test_vector_bubble_sort\n");
  int args[3] = {1, 0, 4};

  vector_t v;
  vector_init(&v, 0, sizeof(int));

  vector_push_back(&v, (void *)&args[0]);
  vector_push_back(&v, (void *)&args[1]);
  vector_push_back(&v, (void *)&args[2]);

  vector_bubble_sort(&v, cmp);

  int key0 = 0;
  int key1 = 1;
  int key2 = 4;

  assert(vector_find(&v, (void *)&key0, test_cmp) == 2);
  assert(vector_find(&v, (void *)&key1, test_cmp) == 1);
  assert(vector_find(&v, (void *)&key2, test_cmp) == 0);

  vector_free(&v, test_delete);
}
