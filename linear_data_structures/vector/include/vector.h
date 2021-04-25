/*!
@file
@brief  Header file for dynamic array (vector)

This file contains the definition of the data structure dynamic array
*/
#ifndef LINEAR_DATA_STRUCTURES_USING_C_VECTOR_H
#define LINEAR_DATA_STRUCTURES_USING_C_VECTOR_H

#include <stdlib.h>

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
  int *data;
  size_t size;
  size_t capacity;
} vector_t;

/**
 * @ingroup vector
 *
 * @brief Construct new vector data structure
 *
 * @param size size of vector
 * if size == 0, set size = 16
 *
 * @return vector data structure
 */
vector_t vector_make(size_t capacity);

/**
 * @ingroup vector
 *
 * @brief Free memory dynamic array
 *
 * @param vector pointer to vector
 */
void vector_free(vector_t *vector);

#endif // LINEAR_DATA_STRUCTURES_USING_C_VECTOR_H
