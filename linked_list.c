#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

void list_init(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

void list_push_front(LinkedList *list, int value) {
    Node *node = malloc(sizeof(Node));
    node->data = value;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void list_push_back(LinkedList *list, int value) {
    Node *node = malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        Node *cur = list->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }
    list->size++;
}

int list_remove(LinkedList *list, int value) {
    Node *cur = list->head;
    Node *prev = NULL;

    while (cur != NULL) {
        if (cur->data == value) {
            if (prev == NULL) {
                list->head = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            list->size--;
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

int list_contains(const LinkedList *list, int value) {
    Node *cur = list->head;
    while (cur != NULL) {
        if (cur->data == value) return 1;
        cur = cur->next;
    }
    return 0;
}

void list_reverse(LinkedList *list) {
    Node *prev = NULL;
    Node *cur = list->head;
    while (cur != NULL) {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    list->head = prev;
}

void list_free(LinkedList *list) {
    Node *cur = list->head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = NULL;
    list->size = 0;
}

void list_to_string(const LinkedList *list, char *buf, int size) {
    int offset = 0;
    offset += snprintf(buf + offset, size - offset, "[");
    Node *cur = list->head;
    while (cur != NULL && offset < size) {
        offset += snprintf(buf + offset, size - offset, "%d%s",
                            cur->data, cur->next ? ", " : "");
        cur = cur->next;
    }
    snprintf(buf + offset, size - offset, "]");
}
