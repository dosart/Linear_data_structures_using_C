[![C CI](https://github.com/dosart/Linear_data_structures_using_C/actions/workflows/main.yml/badge.svg)](https://github.com/dosart/Linear_data_structures_using_C/actions/workflows/main.yml)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/7fedc00712dd4d03b849d30c25736e31)](https://www.codacy.com/gh/dosart/Linear_data_structures_using_C/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=dosart/Linear_data_structures_using_C&amp;utm_campaign=Badge_Grade) ![cppcheck-action](https://github.com/stepin654321/MiniProject_Template/workflows/cppcheck-action/badge.svg) ![Valgrind](https://github.com/stepin654321/MiniProject_Template/workflows/Valgrind/badge.svg)

The project was made as part of the [Coding Interview University](https://github.com/Ilyushin/google-interview-university) course.

# Linear data structures using C
Implementation of classic linear data structures

## Vector (Dynamic array)

- [x] vector_get - returns item at given index, NULL if index out of bounds
- [x] vector_push_back - adds an element to the end
- [x] vector_is_empty 
- [x] vector_capacity - number of items it can hold
- [x] vector_size - number of items
- [x] vector_resize // private function
- [x] vector_delete_by_index - delete item at index, shifting all trailing elements left
- [x] vector_delete_by_value - looks for value and removes index holding it (even if in multiple places)
- [x] vector_insert_by_index - inserts item at index, shifts that index's value and trailing elements to the right
- [x] vector_free - frees memory of vector

### Search functions

- [x] vector_find - implementation linear search
- [x] vector_binary_search - implementation binary search

### Sort functions

- [x] vector_bubble_sort - implementation bubble sort
- [x] vector_insertion_sort -  implementation insertion sort

### Higher-order functions
- [x] vector_foreach - applies a function to each element of the array
- [x] vector_filter - add to a new array elements whose predicate returns true
- [x] vector_fold - converts a vector to a single value
- [x] vector_any -  return true if at least one element of an iterable is true else false


## Stack (using linked list)

- [x] stack_push - inserts a new element at the top of the stack, above its current top element
- [x] stack_pop - removes the element on top of the stack, effectively reducing its size by one
- [x] stack_peek - returns the next character in the input sequence, without extracting it
- [x] stack_size - returns count of elements
- [x] stack_is_emtry = returnы 1 if stack is empty, else returns 0
- [x] stack_free -frees memory of stack

### Higher-order functions (using macros)

- [x] STACK_FOREACH - applies a function to each element of the array

## Queue (using fixed-sized array)

- [x] queue-enqueue(value) - adds item at end of available storage
- [x] queue_dequeue() - removes first element from queue
- [x] queue_count() - returns count of elements of queue
- [x] queue_is_full() - returns true if queue is ful
- [x] queue_free() - frees memory of queue
- [x] queue_peek() - returns value at front of queue, don't remove from queue 
