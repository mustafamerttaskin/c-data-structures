#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../include/linked_list.h"

static void test_push_and_size(void) {
    LinkedList list;
    list_init(&list);

    list_push_back(&list, 1);
    list_push_back(&list, 2);
    list_push_front(&list, 0);

    assert(list.size == 3);

    char buf[64];
    list_to_string(&list, buf, sizeof(buf));
    assert(strcmp(buf, "[0, 1, 2]") == 0);

    list_free(&list);
}

static void test_remove(void) {
    LinkedList list;
    list_init(&list);
    list_push_back(&list, 1);
    list_push_back(&list, 2);
    list_push_back(&list, 3);

    assert(list_remove(&list, 2) == 1);
    assert(list.size == 2);
    assert(list_remove(&list, 99) == 0);

    char buf[64];
    list_to_string(&list, buf, sizeof(buf));
    assert(strcmp(buf, "[1, 3]") == 0);

    list_free(&list);
}

static void test_contains(void) {
    LinkedList list;
    list_init(&list);
    list_push_back(&list, 42);

    assert(list_contains(&list, 42) == 1);
    assert(list_contains(&list, 7) == 0);

    list_free(&list);
}

static void test_reverse(void) {
    LinkedList list;
    list_init(&list);
    list_push_back(&list, 1);
    list_push_back(&list, 2);
    list_push_back(&list, 3);

    list_reverse(&list);

    char buf[64];
    list_to_string(&list, buf, sizeof(buf));
    assert(strcmp(buf, "[3, 2, 1]") == 0);

    list_free(&list);
}

static void test_empty_list(void) {
    LinkedList list;
    list_init(&list);

    char buf[64];
    list_to_string(&list, buf, sizeof(buf));
    assert(strcmp(buf, "[]") == 0);
    assert(list.size == 0);

    list_free(&list);
}

int main(void) {
    test_push_and_size();
    test_remove();
    test_contains();
    test_reverse();
    test_empty_list();
    printf("test_linked_list: all tests passed\n");
    return 0;
}
