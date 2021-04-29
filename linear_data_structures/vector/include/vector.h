/*!
@file
@brief  Header file for dynamic array (vector)

This file contains the definition of the data structure dynamic array
*/
#ifndef LINEAR_DATA_STRUCTURES_USING_C_VECTOR_H
#define LINEAR_DATA_STRUCTURES_USING_C_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \defgroup vector Dynamic array
 *
 * @brief Implementation dynamic array (vector)
 *
 * @authors Dosart
 *
 * @version 0.1.0
 *
 * @date 25 april 2021
 *
 * @warning This structure created only for educational goals
 *
 */
typedef struct vector_t {
  void *data;
  size_t size;
  size_t capacity;
  size_t elem_size;
} vector_t;

/**
 * @ingroup vector
 *
 * @brief Construct new vector data structure
 *
 * @param v pointer to vector data structure
 * @param capacity the size of the storage space currently allocated for the vector, expressed in terms of elements.
 * if capacity == 0, set capacity = 16 on first addition
 * @param elem_size Size of vector item
 *
 *
 * @return vector data structure
 */
void vector_init(vector_t *v, size_t capacity, size_t elem_size);

/**
 * @ingroup vector
 *
 * @brief Free memory dynamic array
 *
 * @param v pointer to vector
 */
void vector_free(vector_t *v);

/**
 * @ingroup vector
 *
 * @brief Adds an item to the end
 *
 * @param v pointer to vector data structure
 * @param elem element for add
 */
void vector_push_back(vector_t *v, void *elem);

/**
 * @ingroup vector
 *
 * @brief Returns item at given index
 *
 * @param v pointer to vector data structure
 * @param elem element for add
 *
 * @return item at given index
 */
void *vector_get(vector_t *v, size_t index);

#endif // LINEAR_DATA_STRUCTURES_USING_C_VECTOR_H
