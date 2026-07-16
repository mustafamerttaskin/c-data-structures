#ifndef STACK_H
#define STACK_H

#define STACK_CAPACITY 128

typedef struct {
    int data[STACK_CAPACITY];
    int top; /* index of the next free slot; 0 means empty */
} Stack;

void stack_init(Stack *s);
int stack_is_empty(const Stack *s);
int stack_is_full(const Stack *s);

/* Returns 1 on success, 0 if the stack is full. */
int stack_push(Stack *s, int value);

/* Returns 1 on success and writes the popped value into *out.
 * Returns 0 if the stack is empty. */
int stack_pop(Stack *s, int *out);

/* Returns 1 and writes the top value into *out without removing it.
 * Returns 0 if the stack is empty. */
int stack_peek(const Stack *s, int *out);

#endif
