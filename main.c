#include <stdio.h>
#include "../include/linked_list.h"
#include "../include/stack.h"

static void demo_linked_list(void) {
    printf("=== Linked List demo ===\n");

    LinkedList list;
    list_init(&list);

    list_push_back(&list, 10);
    list_push_back(&list, 20);
    list_push_back(&list, 30);
    list_push_front(&list, 5);

    char buf[128];
    list_to_string(&list, buf, sizeof(buf));
    printf("After pushes: %s (size=%d)\n", buf, list.size);

    list_remove(&list, 20);
    list_to_string(&list, buf, sizeof(buf));
    printf("After removing 20: %s (size=%d)\n", buf, list.size);

    printf("Contains 30? %s\n", list_contains(&list, 30) ? "yes" : "no");
    printf("Contains 99? %s\n", list_contains(&list, 99) ? "yes" : "no");

    list_reverse(&list);
    list_to_string(&list, buf, sizeof(buf));
    printf("After reverse: %s\n", buf);

    list_free(&list);
    printf("\n");
}

static void demo_stack(void) {
    printf("=== Stack demo ===\n");

    Stack s;
    stack_init(&s);

    stack_push(&s, 1);
    stack_push(&s, 2);
    stack_push(&s, 3);

    int top;
    stack_peek(&s, &top);
    printf("Top after pushing 1,2,3: %d\n", top);

    int value;
    while (stack_pop(&s, &value)) {
        printf("Popped: %d\n", value);
    }

    printf("Stack empty now? %s\n", stack_is_empty(&s) ? "yes" : "no");
}

int main(void) {
    demo_linked_list();
    demo_stack();
    return 0;
}
