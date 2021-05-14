
#include "../include/vector.h"

#include <assert.h>

 typedef struct search_test_item {
    long long (*search)(vector_t *, void *, int(*cmp)(void*, void*));
    int(*cmp)(void*, void*);
    char* message;
} search_test_item;

int cmp_linear_search(void *x, void *y) {
    int int_x = *(int *)x;
    int int_y = *(int *)y;

    return int_x == int_y;
}

int cmp_binary_search(void *x, void *y) {
    int int_x = *(int *)x;
    int int_y = *(int *)y;

    if (int_x == int_y)
        return EQUAL;
    else if (int_x < int_y)
        return LESS;
    else
        return MORE;
}

void test_delete1(void *key) {
    *(int *)key = 0;
}

void test_vector_search1(search_test_item* item);
void test_vector_search2(search_test_item* item);
void test_vector_search3(search_test_item* item);
void test_vector_search4(search_test_item* item);

void test_search() {

    struct search_test_item binary_search_item =
            {
                .search = vector_binary_search,
                .cmp = cmp_binary_search,
                .message = "Binary_search"
            };

    struct search_test_item linear_search_item =
            {
                    .search = vector_find,
                    .cmp = cmp_linear_search,
                    .message = "Linear_search"
            };

    struct search_test_item search_test_items[] = {binary_search_item, linear_search_item};
    for (unsigned short i = 0; i < 2; ++i) {
        test_vector_search1(&search_test_items[i]);
        test_vector_search2(&search_test_items[i]);
        test_vector_search3(&search_test_items[i]);
        test_vector_search4(&search_test_items[i]);
    }
}

void test_vector_search1(search_test_item* item) {
    printf("test_vector_find1 %s\n", item->message);
    int args[3] = {0, 1, 2};

    vector_t v;
    vector_init(&v, 0, sizeof(int));

    vector_push_back(&v, (void *)&args[0]);
    vector_push_back(&v, (void *)&args[1]);
    vector_push_back(&v, (void *)&args[2]);
    int key = 0;

    assert(item->search(&v, (void *)&key, item->cmp) == 0);

    vector_free(&v, test_delete1);
}
void test_vector_search2(search_test_item* item) {
    printf("test_vector_find2. %s\n", item->message);
    int args[3] = {0, 1, 2};

    vector_t v;
    vector_init(&v, 0, sizeof(int));

    vector_push_back(&v, (void *)&args[0]);
    vector_push_back(&v, (void *)&args[1]);
    vector_push_back(&v, (void *)&args[2]);
    int key = 1;

    assert(item->search(&v, (void *)&key, item->cmp) == 1);

    vector_free(&v, test_delete1);
}

void test_vector_search3(search_test_item* item) {
    printf("test_vector_find3 %s\n", item->message);
    int args[3] = {0, 1, 2};

    vector_t v;
    vector_init(&v, 0, sizeof(int));

    vector_push_back(&v, (void *)&args[0]);
    vector_push_back(&v, (void *)&args[1]);
    vector_push_back(&v, (void *)&args[2]);
    int key = 2;

    assert(item->search(&v, (void *)&key, item->cmp) == 2);

    vector_free(&v, test_delete1);
}

void test_vector_search4(search_test_item* item) {
    printf("test_vector_find4 %s\n", item->message);
    int args[3] = {0, 1, 2};

    vector_t v;
    vector_init(&v, 0, sizeof(int));

    vector_push_back(&v, (void *)&args[0]);
    vector_push_back(&v, (void *)&args[1]);
    vector_push_back(&v, (void *)&args[2]);
    int key = 3;

    assert(item->search(&v, (void *)&key, item->cmp) == -1);

    vector_free(&v, test_delete1);
}