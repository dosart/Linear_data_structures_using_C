/*!
@file
@brief  Header file for queue_t
This file contains the definition of the data structure queue_t
*/

#ifndef QUEUE_INCLUDE_QUEUE_H_
#define QUEUE_INCLUDE_QUEUE_H_

#include <stddef.h>
#include "malloc.h"
#include "memory.h"

/**
 * @ingroup queue_t
 *
 * @brief Implementation queue_t using array
 *
 * @authors Dosart
 *
 * @version 0.2.0
 *
 * @date 15 Jun 2021
 *
 * @warning This structure created only for educational goals
 */
typedef struct queue {
  void *data;
  size_t elem_size; ///< size of one element.
  size_t max_size; ///< max_size of elements on the stack.
  size_t count; ///< count if elements in queue_t
  size_t front; ///< index of first element.
  size_t back; ///< index of last element.
} queue_t;

/**
 * @ingroup queue_t
 *
 * @brief Construct new queue_t data structure.
 *
 * @param s Pointer to queue_t data structure.
 * @param elem_size Size of stack item.
 * @param max_size Count of elements for which you need to allocate memory
 */
void queue_init(queue_t *q, size_t elem_size, size_t max_size);

/**
 * @ingroup queue_t
 *
 * @brief Free memory in q.
 *
 * @param s Pointer to queue.
 * @param deleter Deleter function to remove an item.
 */
void queue_free(queue_t *q, void (*deleter)(void *));

/**
 * @ingroup queue_t
 *
 * @brief Returns true if queue is empty.
 *
 * @param s Pointer to queue_t data structure.
 */
unsigned short queue_is_empty(queue_t *q);

/**
 * @ingroup queue_t
 *
 * @brief Returns true if queue is full.
 *
 * @param s Pointer to queue_t data structure.
 */
unsigned short queue_is_full(queue_t *q);

/**
 * @ingroup queue_t
 *
 * @brief Returns count of elements of queue.
 *
 * @param s Pointer to queue_t data structure.
 *
 * @returns count of elements of queue.
 */
size_t queue_count(queue_t *q);

/**
 * @ingroup queue_t
 *
 * @brief Adds item to queue.
 *
 * @param s Pointer to queue_t data structure.
 * @param item Item to add.
 */
void queue_enqueue(queue_t *q, void *item);

/**
 * @ingroup queue_t
 *
 * @brief  Removes first element from queue.
 *
 * @param s Pointer to queue_t data structure.
 * @param deleter Deleter function to remove an item (if NULL don't remove).
 */
void queue_dequeue(queue_t *q, void (*deleter)(void *));

/**
 * @ingroup queue_t
 *
 * @brief Returns value at front of queue, don't remove from queue.
 *
 * @param s Pointer to queue_t data structure.
 *
 * @returns value at front of queue.
 */
void* queue_peek(queue_t *q);

#endif //QUEUE_INCLUDE_QUEUE_H_

