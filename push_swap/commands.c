
#include "commands.h"
#include "stack.h"

static int command_count = 0;

int swap_ab(struct stack *s, char c)
{
    int number1;
    int number2;

    pop(s, &number1);
    pop(s, &number2);
    push(s, number1);
    push(s, number2);

    if (c == 'a')
        printf("sa\n");
    if (c == 'b')
        printf("sb\n");

    command_count++;
    printf("Comamnd count %d\n", command_count);
    return (0);
}


int push_ab(struct stack *a, struct stack *b, char c)
{
    int number;

    if (c == 'a')
    {
        pop(b, &number);
        push(a, number);
        printf("pa\n");
    }
    if (c == 'b')
    {
        pop(a, &number);
        push(b, number);
        printf("pb\n");
    }
    command_count++;
    printf("Comamnd count %d\n", command_count);
    return(0);    
}

int rotate_ab(struct stack *s, char c)
{
    int number;

    pop(s, &number);
    s->stack_arr[s->count] = number;
    s->count++;    
    if (c == 'a')
        printf("ra\n");
    if (c == 'b')
        printf("rb\n");

    command_count++;
    printf("Comamnd count %d\n", command_count);
    return (0);
}


int reverse_rotate_ab(struct stack *s, char c)
{
    int number;
    
    number = s->stack_arr[s->count-1];
    s->count--;
    push(s, number);    
    if (c == 'a')
        printf("rra\n");
    if (c == 'b')
        printf("rrb\n");
    
    command_count++;
    printf("Comamnd count %d\n", command_count);
    return (0);
}