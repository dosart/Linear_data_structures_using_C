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
 * @brief Implementation dynamic array (vector).
 *
 * @authors Dosart
 *
 * @version 0.2.0
 *
 * @date 25 april 2021
 *
 * @warning This structure created only for educational goals.
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
 * @brief Construct new vector data structure.
 *
 * @param v Pointer to vector data structure.
 * @param capacity The size of the storage space currently allocated for the
 * vector, expressed in terms of elements. if capacity == 0, set capacity = 16
 * on first addition.
 *
 * @param elem_size Size of vector item.
 */
void vector_init(vector_t *v, size_t capacity, size_t elem_size);

/**
 * @ingroup vector
 *
 * @brief Implementation null object pattern.
 */
void vector_null(vector_t *v);

/**
 * @ingroup vector
 *
 * @brief Free memory dynamic array.
 *
 * @param v Pointer to vector.
 * @param deleter Function to remove an item.
 */
void vector_free(vector_t *v, void (*deleter)(void *));

/**
 * @ingroup vector
 *
 * @brief Adds an item to the end.
 *
 * @param v Pointer to vector data structure.
 * @param elem Element for add.
 */
void vector_push_back(vector_t *v, void *elem);

/**
 * @ingroup vector
 *
 * @brief Adds an item  by index. If index > size then don't add.
 *
 * @param v Pointer to vector data structure.
 * @param index Index for added.
 * @param elem Element for add.
 */
void vector_insert_by_index(vector_t *v, size_t index, void *elem);

/**
 * @ingroup vector
 *
 * @brief Delete item by value, shifting all trailing elements left.
 *
 * @param v Pointer to vector data structure.
 * @param key Value for delete.
 * @param cmp The function that takes two arguments. Returns 1 if the elements are.
 * @param deleter The function to remove an item.
 */
void vector_delete_by_value(vector_t *v, void *key, int (*cmp)(void *, void *),
                            void (*deleter)(void *));

/**
 * @ingroup vector
 *
 * @brief Delete item at index, shifting all trailing elements left.
 *
 * @param v Pointer to vector data structure.
 * @param index Index for delete.
 * @param deleter Function to remove an item.
 */
void vector_delete_by_index(vector_t *v, size_t index, void (*deleter)(void *));

/**
 * @ingroup vector
 *
 * @brief Returns item at given index.
 *
 * @param v Pointer to vector data structure.
 * @param elem Element for add.
 *
 * @return item At given index.
 */
void *vector_get(vector_t *v, size_t index);

/**
 * @ingroup vector
 *
 * @brief Change element by index.
 *
 * @param v Pointer to vector data structure.
 * @param index Index for change element.
 * @param elem Element for change.
 *
 * @return item At given index.
 */
void vector_set(vector_t *v, size_t index, void *elem);

/**
 * @ingroup vector
 *
 * @brief Returns size of vector (expressed in terms of elements).
 *
 * @param v Pointer to vector data structure.
 *
 * @return size Size of vector.
 */
size_t vector_size(vector_t *v);

/**
 * @ingroup vector
 *
 * @brief Returns true if vector is empty (expressed in terms of elements).
 *
 * @param v Pointer to vector data structure.
 *
 * @return size_t  1 if size == 0 else 0.
 */
size_t vector_is_empty(vector_t *v);

/**
 * @ingroup vector
 *
 * @brief Implementation linear search.
 *
 * @param v Pointer to vector data structure.
 * @param key Key for search
 * @param cmp A function that takes two arguments (key and current item of
 * vector). Returns 1 if the elements are equal, otherwise 0.
 *
 * @return index of find element Returns -1 if key is not found.
 */
long long vector_find(vector_t *v, void *key, int (*cmp)(void *, void *));

#define EQUAL 0
#define LESS 1
#define MORE 2

/**
 * @ingroup vector
 *
 * @brief Implementation binary search
 *
 * @param v Pointer to vector data structure
 * @param key Key for search
 * @param cmp A function that takes two arguments (key and current item of
 * vector). Returns EQUAL if the key are equal, returns LESS if key less,
 * returns MORE if key more.
 *
 * @return index of find element Returns -1 if key is not found.
 */
long long vector_binary_search(vector_t *v, void *key,
                               int (*cmp)(void *, void *));

#endif // LINEAR_DATA_STRUCTURES_USING_C_VECTOR_H
