#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *stack_arr;
    int size;
    int count;
};

int push(struct stack *s, int number);
int pop(struct stack *s, int *number);
int is_stack_sorted(struct stack *s);
int stack_smallest_index(struct stack *s);
int stack_largest_index(struct stack *s);

// to be removed later.
//int print_stacks(struct stack *a, struct stack *b);

#endif