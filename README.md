# push_swap

`push_swap` is a project from the 42 school focused on sorting algorithms and optimization.

The goal is to sort a stack of integers using a limited set of operations while producing the smallest possible number of moves.

This implementation uses a **Radix Sort** algorithm to efficiently sort large datasets and practice low-level bit manipulation using bit shifting.

---

## Project Overview

The program works with two stacks:

- `stack_a`
- `stack_b`

Using a restricted set of operations, the program must sort `stack_a` in ascending order.

The challenge is not only to sort correctly, but also to minimize the number of operations.

---

## Sorting Strategy

This project uses a **binary Radix Sort** approach:

- values are indexed
- each number is sorted bit by bit
- bit shifting (`>>`) is used to analyze binary digits
- elements are pushed or rotated depending on the current bit value

This method provides excellent performance for large inputs while keeping the implementation simple and efficient.

---

## Allowed Operations

### Swap

- `sa`
- `sb`
- `ss`

### Push

- `pa`
- `pb`

### Rotate

- `ra`
- `rb`
- `rr`

### Reverse Rotate

- `rra`
- `rrb`
- `rrr`

---

## Compilation

```bash
make
```

### Compilation flags

```bash
-Wall -Wextra -Werror
```

---

## Usage

### Basic usage

```bash
./push_swap 2 1 3 6 5 8
```

### With quoted arguments

```bash
./push_swap "2 1 3 6 5 8"
```

---

## Example Output

```bash
pb
ra
pb
sa
pa
pa
```

Each line represents an operation performed to sort the stack.

---

## Project Structure

```text
.
├── Makefile
├── includes
│   └── Push_swap.h
├── libft
├── operations
│   ├── push.c
│   ├── reverse_rotate.c
│   ├── rotate.c
│   └── swap.c
├── sorting
│   ├── find_max_lst.c
│   ├── find_min_lst.c
│   ├── identify_order.c
│   ├── is_sorted.c
│   ├── mini_sort.c
│   └── radix_sort.c
└── src
    ├── create_add_node.c
    ├── errors.c
    ├── find_max_bits.c
    ├── free_stack.c
    ├── ft_free_list.c
    ├── main.c
    ├── split_to_nodes.c
    └── stdin_to_str.c
```

---

## Features

- Parsing and validation of input
- Duplicate detection
- Error handling
- Linked list stack implementation
- Optimized mini-sort for small datasets
- Binary Radix Sort for large datasets
- Memory management and cleanup

---

## Concepts Covered

- Sorting algorithms
- Radix Sort
- Bitwise operations and bit shifting
- Linked lists
- Stack manipulation
- Algorithm optimization
- Memory management
- Parsing and validation

---

## Dependencies

This project uses a custom `libft` library including:

- standard libc reimplementations
- linked list utilities
- a custom `ft_printf`

---

## Author

Project completed as part of the 42 curriculum.
