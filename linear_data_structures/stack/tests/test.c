//
// Created by dosart on 6/12/21.
//

#include "tests.h"

void tests() {
  test_stack_init();

  test_stack_push1();

  test_stack_peek1();
  test_stack_peek2();
  test_stack_peek3();

  test_stack_pop0();
  test_stack_pop1();
  test_stack_pop2();
  test_stack_pop3();
  test_stack_pop4();
}

static void deleter(void* value)
{
  int* pv = (int*)value;
  *pv = 0;
}

void test_stack_init() {
  printf("test_stack_init()\n");

  stack_t stack;
  stack_init(&stack, sizeof(int));

  assert(stack_is_empty(&stack) == 1);
  assert(stack_size(&stack) == 0);
}

void test_stack_push1() {
  printf("test_stack_push1()\n");

  stack_t stack;
  stack_init(&stack, sizeof(int));

  int one = 1;
  int two = 2;
  stack_push(&stack, &one);
  stack_push(&stack, &two);

  assert(stack_is_empty(&stack) == 0);
  assert(stack_size(&stack) == 2);

  stack_free(&stack, deleter);
}

void test_stack_peek1() {
  printf("test_stack_peek1()\n");

  stack_t stack;
  stack_init(&stack, sizeof(int));

  assert(stack_peek(&stack) == NULL);
}
void test_stack_peek2() {
  printf("test_stack_peek2()\n");

  assert(stack_peek(NULL) == NULL);
}
void test_stack_peek3() {
  printf("test_stack_peek3()\n");

  stack_t stack;
  stack_init(&stack, sizeof(int));

  int one = 1;
  int two = 2;
  stack_push(&stack, &one);
  stack_push(&stack, &two);

  int value = *(int*)stack_peek(&stack);
  assert(value == 2);
  assert(stack_is_empty(&stack) == 0);
  assert(stack_size(&stack) == 2);

  stack_free(&stack, deleter);
}

void test_stack_pop0() {
  printf("test_stack_pop0()\n");

  stack_t stack;
  stack_init(&stack, sizeof(int));

  int one = 1;
  int two = 2;
  stack_push(&stack, &one);
  stack_push(&stack, &two);

  stack_pop(&stack, deleter);
  int pop_one = *(int*)stack_peek(&stack);

  assert(pop_one == 1);
  assert(stack_size(&stack) == 1);
  assert(stack_is_empty(&stack) == 0);

  stack_free(&stack, deleter);
}

void test_stack_pop1() {
  printf("test_stack_pop1()\n");

  stack_t stack;
  stack_init(&stack, sizeof(int));

  stack_pop(&stack, deleter);

  assert(stack_is_empty(&stack) == 1);
  assert(stack_size(&stack) == 0);

  stack_free(&stack, deleter);
}

struct point {int x; int y;};

void deleter_point(void* point)
{
  ((struct point*)point)->x = 0;
  ((struct point*)point)->y = 0;
}

void test_stack_pop2() {
  printf("test_stack_pop2()\n");

  struct point p1 = {.x = 0, .y = 10};
  struct point p2 = {.x = 1, .y = 11};

  stack_t stack;
  stack_init(&stack, sizeof(struct point));
  stack_push(&stack, (void*)&p1);
  stack_push(&stack, (void*)&p2);

  stack_pop(&stack, deleter_point);

  struct point p1_pop = *(struct point*) stack_peek(&stack);
  assert(p1_pop.x == p1.x);
  assert(p1_pop.y == p1.y);
  assert(stack_size(&stack) == 1);

  stack_free(&stack, deleter_point);
}

void test_stack_pop3() {
  printf("test_stack_pop3()\n");

  stack_t stack;
  stack_init(&stack, sizeof(int));

  int one = 1;
  stack_push(&stack, &one);

  stack_pop(&stack, deleter);

  assert(stack_size(&stack) == 0);
  assert(stack_is_empty(&stack) == 1);
  assert(stack_peek(&stack) == NULL);

  stack_free(&stack, deleter);
}

void test_stack_pop4() {
  printf("test_stack_pop4()\n");

  stack_t stack;
  stack_init(&stack, sizeof(int));

  assert(stack_peek(&stack) == NULL);
  stack_pop(&stack, deleter);
}

