/*!
@file
@brief  Header file for utils functions
*/

#ifndef LINEAR_DATA_STRUCTURES_USING_C_UTILS_H
#define LINEAR_DATA_STRUCTURES_USING_C_UTILS_H

#include "vector.h"
#include <memory.h>

void *get_item(vector_t *v, size_t index);

void vector_swap(vector_t *v, size_t index1, size_t index2, size_t elem_size);

#endif // LINEAR_DATA_STRUCTURES_USING_C_UTILS_H
