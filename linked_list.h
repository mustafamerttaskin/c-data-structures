#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

/* Initializes an empty list. */
void list_init(LinkedList *list);

/* Inserts a value at the front of the list. O(1). */
void list_push_front(LinkedList *list, int value);

/* Inserts a value at the back of the list. O(n). */
void list_push_back(LinkedList *list, int value);

/* Removes the first node matching value.
 * Returns 1 if a node was removed, 0 if the value was not found. */
int list_remove(LinkedList *list, int value);

/* Returns 1 if value is present in the list, 0 otherwise. */
int list_contains(const LinkedList *list, int value);

/* Reverses the list in place. */
void list_reverse(LinkedList *list);

/* Frees every node in the list and resets it to empty. */
void list_free(LinkedList *list);

/* Writes the list contents as "[a, b, c]" into buf (size bytes). */
void list_to_string(const LinkedList *list, char *buf, int size);

#endif
