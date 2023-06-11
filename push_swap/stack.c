#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int push(struct stack *s, int number)
{
    int i;
 
    if (s->count >= s->size)
        return (-1);
    
    if (s->count == 0)
    {
        s->stack_arr[0] = number;
        s->count++;
        return (0);
    }

    i = s->count;       
    while (i > 0)
    {
        s->stack_arr[i] = s->stack_arr[i-1];
        i--;
    }
    s->stack_arr[0] = number;
    s->count++;
    return 0;
}

int pop(struct stack *s, int *number)
{
    int i;
    int j;

    if (s->count <= 0)
        return -1;

    *number = s->stack_arr[0];

    i = 0; 
    while (i < s->count)
    {
        s->stack_arr[i] = s->stack_arr[i + 1];
        i++;
    }
    s->count--;
    return (0);
}

int is_stack_sorted(struct stack *s)
{
    int i = 1;
    while (i < s->count)
    {
        if (s->stack_arr[i-1] > s->stack_arr[i])
            return (0);
        i++;
    }
    return (1);
}

int stack_smallest_index(struct stack *s)
{
    int i;
    int smallest;
    int smallest_index;

    i = 1;
    smallest = s->stack_arr[0];
    smallest_index = 0;
    while (i < s->count)
    {
        if (s->stack_arr[i] < smallest)
        {
            smallest = s->stack_arr[i];
            smallest_index = i;
        }   
        i++;
    }
    return smallest_index;
}

int stack_largest_index(struct stack *s)
{
    int i;
    int largest;
    int largest_index;

    i = 1;
    largest = s->stack_arr[0];
    largest_index = 0;

    while (i < s->count)
    {
        if (s->stack_arr[i] > largest)
        {
            largest = s->stack_arr[i];
            largest_index = i;
        }   
        i++;
    }
    return largest_index;
}

int print_stacks(struct stack *a, struct stack *b)
{
    int i;

    printf("Stack A\n");
    i=0;
    while(i < a->count)
    {
        printf("0x%x, ", a->stack_arr[i]);
        i++;
    }

    printf("\n");
    printf("Stack B\n");
    i = 0;
    while(i < b->count)
    {
        printf("0x%x, ", b->stack_arr[i]);
        
        i++;
    }
    printf("\n");
}
