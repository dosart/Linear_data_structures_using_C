//
// Created by dosart on 25.04.2021.
//
#include "../include/vector.h"
#include <assert.h>

void test_vector_make();

int main()
{
    test_vector_make();
}

void test_vector_make()
{
    vector_t* vector = vector_make(8);
    assert(vector->size == 0)
    assert(vector->capacity == 8)
}

