
#include "stack.h"

void stack_init(stack_t *s, size_t elem_size) {
  if (s!=NULL) {
    s->elem_size = elem_size;
    s->first = s->last = NULL;
    s->size = 0;
  }
}

size_t stack_is_empty(stack_t *s) {
  if (s!=NULL) {
    return s->size==0 ? 1 : 0;
  }
  return 0;
}

size_t stack_size(stack_t *s) {
  if (s!=NULL) {
    return s->size;
  }
  return 0;
}

void *stack_peek(stack_t *s) {
  if (s!=NULL && s->size > 0) {
    return s->first->data;
  }
  return NULL;
}

void stack_free(stack_t *s, void (*deleter)(void *)) {
  if (s!=NULL) {
    stack_item_t *cur = s->first;
    stack_item_t *tmp = NULL;
    while (cur) {
      deleter(cur->data);
      tmp = cur->next;
      free(cur->data);
      free(cur);
      cur = tmp;
    }
  }
}

void stack_pop(stack_t *s, void (*deleter)(void *)) {
  if (s && deleter) {
    stack_item_t* head = s->first;
    if (head) {
      deleter(head->data);
      free(head->data);
      if (head->next)
        s->first = head->next;
      free(head);
      if (--s->size)
        s->last = NULL;
      else
        s->first = s->last = NULL;
    }
  }
}

static stack_item_t *stack_make_item(void *value, size_t value_size,
                                     stack_item_t *next);

void stack_push(stack_t *s, void *item) {
  if (s!=NULL) {
    s->first = stack_make_item(item, s->elem_size, s->first);
    if (s->last==NULL)
      s->last = s->first;
    s->size++;
  }
}

static void copy(void *destination, void *source, size_t size);

static stack_item_t *stack_make_item(void *value, size_t value_size,
                                     stack_item_t *next) {
  stack_item_t *new_item = malloc(sizeof(stack_item_t));
  new_item->next = next;

  new_item->data = malloc(sizeof(value_size));
  copy(new_item->data, value, value_size);

  return new_item;
}

static void copy(void *destination, void *source, size_t size) {
  memcpy((char *) destination, (char *) source, size);
}


