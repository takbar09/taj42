#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "commands.h"
#include "init_stack.h"
#include "check_args.h"

static struct stack a;
static struct stack b;

int radix_sort(void)
{
    int bit;
    int i;

    bit = 0;
    while (bit < sizeof(int))
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
}

int push_swap(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    if (check_args(argc, argv) == -1)
        return (-1);
    if (init_stacks(argc, argv, &a, &b) == -1)
        return (-1);
    print_stacks(&a, &b);
    radix_sort();
    print_stacks(&a, &b);
    free(a.stack_arr);
    free(b.stack_arr);
}

int	main(int argc, char **argv)
{
    int return_value;
    return_value = push_swap(argc, argv);
    if (return_value == -1)
        printf ("Error\n");
    return (return_value);
}
