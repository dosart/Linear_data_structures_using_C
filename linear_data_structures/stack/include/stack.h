//
// Created by dosart on 6/12/21.
//

#ifndef UNTITLED1__STACK_H_
#define UNTITLED1__STACK_H_

/*!
@file
@brief  Header file for stack

This file contains the definition of the data structure stack
*/
#ifndef LINEAR_DATA_STRUCTURES_USING_C_STACK_H
#define LINEAR_DATA_STRUCTURES_USING_C_STACK_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"

/**
 * \defgroup stack
 *
 * @brief Item of stack
 *
 * @authors Dosart
 *
 * @version 0.2.0
 *
 * @date 07 May 2021
 *
 * @warning This structure created only for educational goals
 */
typedef struct stack_item_t {
  void *data;
  struct stack_item_t *next;
} stack_item_t;

/**
 * @ingroup stack
 *
 * @brief Implementation stack using linked list
 *
 * @authors Dosart
 *
 * @version 0.2.0
 *
 * @date 07 May 2021
 *
 * @warning This structure created only for educational goals
 */
typedef struct stack_t {
  stack_item_t *first, *last;
  size_t elem_size; ///< size of one element
  size_t size; ///< count of elements on the stack
} stack_t;

/**
 * @ingroup stack
 *
 * @brief Construct new stack data structure.
 *
 * @param s Pointer to stack data structure.
 * @param elem_size Size of stack item.
 */
void stack_init(stack_t *v, size_t elem_size);

/**
 * @ingroup stack
 *
 * @brief Returns true if stack is empty (expressed in terms of elements).
 *
 * @param s Pointer to stack data structure.
 *
 * @return 1 if size == 0 else 0.
 */
size_t stack_is_empty(stack_t *s);

/**
 * @ingroup stack
 *
 * @brief Returns size of stack (expressed in terms of elements).
 *
 * @param s Pointer to stack data structure.
 *
 * @return Size of stack.
 */
size_t stack_size(stack_t *s);

/**
 * @ingroup stack
 *
 * @brief Free memory in stack_item_t.
 *
 * @param s Pointer to stack.
 * @param deleter Deleter function to remove an item.
 */
void stack_free(stack_t *s, void (*deleter)(void *));

/**
 * @ingroup stack
 *
 * @brief Add item to stack.
 *
 * @param s pointer to stack.
 * @param item element for add.
 */
void stack_push(stack_t *s, void *item);

/**
 * @ingroup stack
 *
 * @brief Looks at the object at the top of this s without removing it from the s.
 *
 * @param s Pointer to s.
 *
 * @return Top of this s.
 */
void* stack_peek(stack_t *s);

/**
 * @ingroup stack
 *
 * @brief Removes the object at the top of this stack and returns that object as the value of this function.
 *
 * @param s Pointer to s.
 *
 * @return Top of this s.
 * @param deleter Deleter function to remove an item.
 */
void stack_pop(stack_t *s, void (*deleter)(void *));

#endif // LINEAR_DATA_STRUCTURES_USING_C_STACK_H

#endif //UNTITLED1__STACK_H_

