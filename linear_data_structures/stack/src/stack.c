#include "../include/stack.h"

void stack_init(stack_t *s, size_t elem_size) {
    if (s != NULL) {
        s->elem_size = elem_size;
        s->first = s->last = NULL;
        s->size = 0;
    }
}

size_t stack_is_empty(stack_t *s) {
    if (s != NULL) {
        return s->size == 0 ? 1 : 0;
    }
    return 0;
}

size_t stack_size(stack_t *s) {
    if (s != NULL) {
        return s->size;
    }
    return 0;
}

