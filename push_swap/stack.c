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

// to be removed later
int print_stacks(struct stack *a, struct stack *b)
{
    int i;

    printf("Stack a \t  Stack B\n");
    i=0;
    while(i < a->count)
    {
        printf("%d\t", a->stack_arr[i]);
        if (i < b->count)
            printf("%d", b->stack_arr[i]);

        printf("\n");
        i++;
    }

    while(i < b->count)
    {
        printf("\t %d", b->stack_arr[i]);
        printf("\n");
        i++;
    }
}