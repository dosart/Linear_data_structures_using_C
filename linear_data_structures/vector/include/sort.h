#ifndef LINEAR_DATA_STRUCTURES_USING_C_SORT_H
#define LINEAR_DATA_STRUCTURES_USING_C_SORT_H

#include "utils.h"
#include "vector.h"

/**
 * @ingroup vector
 *
 * @brief Implementation bubble sort algorithm
 *
 * @warning Doesn't check for NULL equality
 *
 * @param v pointer to vector
 * @param cmp comparison function (returns True if x ≤ y and False otherwise)
 */
void vector_bubble_sort(vector_t *v, int (*cmp)(void *, void *));

/**
 * @ingroup vector
 *
 * @brief Implementation insertion sort algorithm
 *
 * @warning Doesn't check for NULL equality
 *
 * @param v pointer to vector
 * @param cmp comparison function (returns True if x ≤ y and False otherwise)
 */
void vector_insertion_sort(vector_t *v, int (*cmp)(void *, void *));

void vector_quick_sort(vector_t* v, int (*cmp)(void*, void*))

#endif // LINEAR_DATA_STRUCTURES_USING_C_SORT_H
