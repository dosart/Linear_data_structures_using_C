/*!
@file
@brief  Header file for implement higher order functions
*/

#ifndef LINEAR_DATA_STRUCTURES_USING_C_FOREACH_H
#define LINEAR_DATA_STRUCTURES_USING_C_FOREACH_H

#include "vector.h"

/**
 * @ingroup vector
 *
 * @brief Applies a function to each element of the array.
 *
 * @param v pointer to vector.
 * @param f function.
 */
void vector_foreach(vector_t *v, void (*f)(void *));

/**
 * @ingroup vector
 *
 * @brief Add to a new array elements whose predicate returns true.
 *
 * @param v pointer to vector.
 * @param f function predicate. Applies to every item v.
 *
 * @returns New vector with filtered values.
 */
vector_t vector_filter(vector_t *v, int (*f)(void *));

/**
 * @ingroup vector
 *
 * @brief Return true if at least one element satisfies the predicate.
 *
 * @param v pointer to vector.
 * @param f function predicate. Applies to every item v.
 *
 * @returns bool.
 */
int vector_any(vector_t *v, int (*f)(void *));

/**
 * @ingroup vector
 *
 * @brief Executes the function once for each array element.
 *
 * @param v pointer to vector.
 * @param f function. Applies to every item v.
 */
void vector_fold(vector_t *v, void *acc, void (*fun)(void *, void *));

#endif // LINEAR_DATA_STRUCTURES_USING_C_FOREACH_H
