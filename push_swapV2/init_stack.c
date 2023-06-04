/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:54:56 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/04 18:49:42 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "init_stack.h"
#include <stdlib.h>

int smallest_index(int *temp, int size)
{
    int i;
    int smallest;
    int smallest_index;

    i = 1;
    smallest = temp[0];
    smallest_index = 0; 

    while (i < size)
    {
        if (temp[i] < smallest)
        {
            smallest = temp[i];
            smallest_index = i;
        }   
        i++;
    }
    return smallest_index;
}

int greatest_index(int *temp, int size)
{
    int i;
    int greatest;
    int greatest_index;
    
    i = 1;
    greatest = temp[0];
    greatest_index = 0; 

    while (i < size)
    {
        if (temp[i] > greatest)
        {
            greatest = temp[i];
            greatest_index = i;
        }
        i++;
    }
    return greatest_index;
}

int map_temp_to_stacka(struct stack *a, int *temp, int size)
{
    int index;
    int greatst_index;
    int i;

    greatst_index = greatest_index(temp, size);
    a->stack_arr[greatst_index] = size-1;
    printf("Map %d to  %d\n", temp[greatst_index], size-1);

    i = 0;
    while (i < (size - 1))
    {
        index = smallest_index(temp, size);
        a->stack_arr[index] = i;
        printf("Map %d to  %d\n", temp[index], i);
        temp[index] = temp[greatst_index];
        i++;    
    }
    a->count = a->size;
}

int init_stacks(int argc, char **argv, struct stack *a, struct stack *b)
{
    int i;
    int *temp;
    a->size = argc - 1;
    b->size = argc - 1;
    temp = malloc(a->size * sizeof(int));
    a->stack_arr = malloc(a->size * sizeof(int));
    b->stack_arr = malloc(b->size * sizeof(int));
    if (!temp || !a->stack_arr  || !b->stack_arr)
    {
        free(temp);
        free(a->stack_arr);
        free(b->stack_arr);
        return (-1);
    }
    i = 0;
    while (i < a->size)
    {
        temp[i] = atoi(argv[i+1]);
        i++;
    }
    map_temp_to_stacka(a, temp, a->size);
    free(temp);
}
