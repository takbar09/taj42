#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "commands.h"
#include "init_stack.h"
#include "check_args.h"

static struct stack a;
static struct stack b;

void push_min_to_stack_b(void)
{
    int smallest_index;

    smallest_index = stack_smallest_index(&a);
    
    while(smallest_index != 0)
    {       
        if (smallest_index < a.count/2)
            rotate_ab(&a, 'a');
        else
            reverse_rotate_ab(&a, 'a');    
        smallest_index = stack_smallest_index(&a);
    }
    push_ab(&a, &b, 'b');
}

void push_max_to_end(void)
{
    int largest_index;

    largest_index = stack_largest_index(&a);

    if (largest_index == 0)
        rotate_ab(&a, 'a');
    if (largest_index == 1)
        reverse_rotate_ab(&a, 'a');
}

void simple_sort(void)
{
    if (is_stack_sorted(&a))
        return;

    while (a.count > 3)
        push_min_to_stack_b();

    if (a.count == 3)
        push_max_to_end();
        
    if (a.count == 3 || a.count == 2)
        if (a.stack_arr[0] > a.stack_arr[1])
            swap_ab(&a, 'a');

    while (b.count > 0)
        push_ab(&a, &b,'a');
}

int radix_sort(void)
{
    int bit;
    int i;

    bit = 0;
    while (bit < 32)
    {
        i = 0;
        while (i < a.size)
        {
            if (is_stack_sorted(&a))
                break;
            if (a.stack_arr[0] & (1<<bit))
                rotate_ab(&a, 'a');
            else
                push_ab(&a, &b, 'b');
            i++;
        }
        
        while(b.count > 0)
            push_ab(&a, &b, 'a');;
        bit++;
    }
    return (0);
}

int push_swap(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    if (check_args(argc, argv) == -1)
        return (-1);
    if (init_stacks(argc, argv, &a, &b) == -1)
        return (-1);
    //print_stacks(&a, &b);
    if (a.size <= 5)
        simple_sort();
    if (a.size > 5)
        radix_sort();
    //print_stacks(&a, &b);
    free(a.stack_arr);
    free(b.stack_arr);
    return (0);
}

int	main(int argc, char **argv)
{
    int return_value;

    return_value = push_swap(argc, argv);
    if (return_value == -1)
        printf ("Error\n");
    return (return_value);
}
