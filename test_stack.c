#include <assert.h>
#include <stdio.h>
#include "../include/stack.h"

static void test_push_pop_order(void) {
    Stack s;
    stack_init(&s);

    assert(stack_is_empty(&s) == 1);

    stack_push(&s, 1);
    stack_push(&s, 2);
    stack_push(&s, 3);

    int value;
    stack_pop(&s, &value);
    assert(value == 3);
    stack_pop(&s, &value);
    assert(value == 2);
    stack_pop(&s, &value);
    assert(value == 1);

    assert(stack_is_empty(&s) == 1);
}

static void test_pop_empty_fails(void) {
    Stack s;
    stack_init(&s);

    int value;
    assert(stack_pop(&s, &value) == 0);
}

static void test_peek_does_not_remove(void) {
    Stack s;
    stack_init(&s);
    stack_push(&s, 10);

    int value;
    assert(stack_peek(&s, &value) == 1);
    assert(value == 10);
    assert(stack_is_empty(&s) == 0);
}

static void test_full_stack(void) {
    Stack s;
    stack_init(&s);

    for (int i = 0; i < STACK_CAPACITY; i++) {
        assert(stack_push(&s, i) == 1);
    }
    assert(stack_is_full(&s) == 1);
    assert(stack_push(&s, 999) == 0);
}

int main(void) {
    test_push_pop_order();
    test_pop_empty_fails();
    test_peek_does_not_remove();
    test_full_stack();
    printf("test_stack: all tests passed\n");
    return 0;
}
