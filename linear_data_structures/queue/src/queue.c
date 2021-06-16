#include "../include/queue.h"

void queue_init(queue_t *q, size_t elem_size, size_t max_size) {
  if (q) {
    q->data = malloc(elem_size*max_size);
    q->elem_size = elem_size;
    q->max_size = max_size;
    q->count = 0;
    q->front = 0;
    q->back = 0;
  }
}

static void *get_item(queue_t *q, size_t index);

void queue_free(queue_t *q, void (*deleter)(void *)) {
  if (q) {
    for (size_t i = 0; i < q->count; ++i) {
      deleter(get_item(q, i));
    }
    free(q->data);
  }
}

static void *get_item(queue_t *q, size_t index) {
  return (char *) q->data + index*q->elem_size;
}

unsigned short queue_is_empty(queue_t *q) {
  if (q) {
    return q->count==0 ? 1 : 0;
  }
  return 1;
}

unsigned short queue_is_full(queue_t *q) {
  if (q) {
    return q->count==q->max_size ? 1 : 0;
  }
  return 0;
}

size_t queue_count(queue_t *q) {
  if (q) {
    return q->count;
  }
  return 0;
}

static void set_item(queue_t *q, size_t index, void *item);

void queue_enqueue(queue_t *q, void *item) {
  if (q) {
    set_item(q, q->back, item);
    q->back = (q->back + 1)%q->max_size;
    ++q->count;
  }
}

static void set_item(queue_t *q, size_t index, void *item) {
  memcpy(((char *) q->data) + index*q->elem_size, item, q->elem_size);
}

void *queue_peek(queue_t *q) {
  if (q && !queue_is_empty(q)) {
    return get_item(q, q->front);
  }
  return NULL;
}

//void queue_dequeue(queue_t *q, void *item) {
//  q = NULL;
//  item = NULL;
//}
