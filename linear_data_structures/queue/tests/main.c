#include <stdio.h>
#include <assert.h>
#include <stdio.h>
#include "include/queue.h"

static void deleter(void *item) { (*(int *) item) = 0; }

void test_init() {
  printf("test_init()\n");

  queue_t q;
  queue_init(&q, sizeof(int), 10);

  assert(queue_is_empty(&q)==1);
  assert(queue_is_full(&q)==0);
  assert(queue_count(&q)==0);

  queue_free(&q, deleter);
}

void test_enqueue1() {
  printf("test_enqueue1()\n");

  queue_t q;
  queue_init(&q, sizeof(int), 10);

  int item = 10;
  queue_enqueue(&q, &item);

  assert(queue_is_empty(&q)==0);
  assert(queue_is_full(&q)==0);
  assert(queue_count(&q)==1);

  queue_free(&q, deleter);
}

void test_enqueue2() {
  printf("test_enqueue2()\n");

  queue_t q;
  queue_init(&q, sizeof(int), 10);

  int item = 10;
  for (int i = 0; i < 10; ++i) {
    queue_enqueue(&q, &item);
  }

  assert(queue_is_empty(&q)==0);
  assert(queue_is_full(&q)==1);
  assert(queue_count(&q)==10);

  queue_free(&q, deleter);
}

void test_peek1() {
  printf("test_peek1()\n");

  queue_t q;
  queue_init(&q, sizeof(int), 10);

  int item = 10;
  for (int i = 0; i < 10; ++i) {
    queue_enqueue(&q, &item);
    item += 1;
  }

  int result = *(int *) queue_peek(&q);
  assert(result==10);
  assert(queue_is_empty(&q)==0);
  assert(queue_is_full(&q)==1);
  assert(queue_count(&q)==10);

  queue_free(&q, deleter);
}

void test_peek2() {
  printf("test_peek2()\n");

  queue_t q;
  queue_init(&q, sizeof(int), 10);

  int *result = (int *) queue_peek(&q);
  assert(result==NULL);
  assert(queue_is_empty(&q)==1);
  assert(queue_is_full(&q)==0);
  assert(queue_count(&q)==0);

  queue_free(&q, deleter);
}

void test_queue_dequeue1() {
  printf("test_queue_dequeue1()\n");

  queue_t q;
  queue_init(&q, sizeof(int), 10);

  queue_dequeue(&q, NULL);
  assert(queue_is_empty(&q)==1);
  assert(queue_is_full(&q)==0);
  assert(queue_count(&q)==0);

  queue_free(&q, deleter);
}

void test_queue_dequeue2() {
  printf("test_queue_dequeue2()\n");

  queue_t q;
  queue_init(&q, sizeof(int), 10);

  int item = 10;
  for (int i = 0; i < 10; ++i) {
    queue_enqueue(&q, &item);
    item += 1;
  }

  queue_dequeue(&q, NULL);

  assert(queue_is_empty(&q)==0);
  assert(queue_is_full(&q)==0);
  assert(queue_count(&q)==9);

  queue_free(&q, deleter);
}

void test_queue_dequeue3() {
  printf("test_queue_dequeue3()\n");

  queue_t q;
  queue_init(&q, sizeof(int), 10);

  int item = 10;
  queue_enqueue(&q, &item);
  item += 1;

  queue_dequeue(&q, deleter);

  assert(queue_is_empty(&q)==1);
  assert(queue_is_full(&q)==0);
  assert(queue_count(&q)==0);

  queue_free(&q, deleter);
}

int main() {
  printf("Hello, World!\n");

  test_init();
  test_enqueue1();
  test_enqueue2();

  test_peek1();
  test_peek2();

  test_queue_dequeue1();
  test_queue_dequeue2();
  test_queue_dequeue3();
  return 0;
}
