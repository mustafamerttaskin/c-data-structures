CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

.PHONY: all demo test clean

all: demo

demo: src/main.c src/linked_list.c src/stack.c
	$(CC) $(CFLAGS) -o demo src/main.c src/linked_list.c src/stack.c

test: test_linked_list test_stack
	./test_linked_list
	./test_stack

test_linked_list: tests/test_linked_list.c src/linked_list.c
	$(CC) $(CFLAGS) -o test_linked_list tests/test_linked_list.c src/linked_list.c

test_stack: tests/test_stack.c src/stack.c
	$(CC) $(CFLAGS) -o test_stack tests/test_stack.c src/stack.c

clean:
	rm -f demo test_linked_list test_stack
