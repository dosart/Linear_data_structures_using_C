//
// Created by dosart on 03.05.2021.
//

#ifndef LINEAR_DATA_STRUCTURES_USING_C_FOREACH_H
#define LINEAR_DATA_STRUCTURES_USING_C_FOREACH_H

#include "vector.h"

/**
 * @ingroup vector
 *
 * @brief Applies a function to each element of the array
 *
 * @param v pointer to vector
 * @param f function
 */
void vector_foreach(vector_t *v, void (*f)(void *));

/**
 * @ingroup vector
 *
 * @brief Add to a new array elements whose predicate returns true
 * true
 *
 * @param v pointer to vector
 * @param f function predicate. Applies to every item v
 *
 * @returns New vector with filtered values
 */
vector_t vector_filter(vector_t *v, int (*f)(void *));

#endif // LINEAR_DATA_STRUCTURES_USING_C_FOREACH_H
