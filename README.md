# c-data-structures

![C](https://img.shields.io/badge/C-C11-00599C?logo=c&logoColor=white)
![Tests](https://img.shields.io/badge/tests-passing-brightgreen)

Small, dependency-free implementations of two classic data structures —
a singly linked list and an array-based stack — written from scratch in C,
with a unit test suite for each.

## Why

Practicing manual memory management, pointer manipulation, and API design
in C outside of coursework. Kept intentionally small so every line is easy
to explain.

## What's inside

- **Linked list** (`src/linked_list.c`) — push front/back, remove by value,
  contains, reverse, and a `list_to_string` helper for easy debugging.
- **Stack** (`src/stack.c`) — fixed-capacity array-based stack with push,
  pop, peek, and full/empty checks.
- **Demo** (`src/main.c`) — runs both structures through a scripted set of
  operations and prints the results.
- **Tests** (`tests/`) — `assert`-based unit tests covering normal cases and
  edge cases (empty list, full stack, popping from empty stack, etc).

## Building & running

```bash
make demo && ./demo   # run the walkthrough demo
make test              # build and run all unit tests
make clean              # remove build artifacts
```

### Example output

```
=== Linked List demo ===
After pushes: [5, 10, 20, 30] (size=4)
After removing 20: [5, 10, 30] (size=3)
Contains 30? yes
Contains 99? no
After reverse: [30, 10, 5]

=== Stack demo ===
Top after pushing 1,2,3: 3
Popped: 3
Popped: 2
Popped: 1
Stack empty now? yes
```

## Project structure

```
c-data-structures/
├── include/
│   ├── linked_list.h
│   └── stack.h
├── src/
│   ├── linked_list.c
│   ├── stack.c
│   └── main.c
├── tests/
│   ├── test_linked_list.c
│   └── test_stack.c
└── Makefile
```
