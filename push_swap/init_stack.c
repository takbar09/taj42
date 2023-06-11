
#include "init_stack.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
	i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i - 1] == '-' || str[i - 1] == '+')
			return (0);
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}

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

    i = 0;
    while (i < (size - 1))
    {
        index = smallest_index(temp, size);
        a->stack_arr[index] = i;
        temp[index] = temp[greatst_index];
        i++;    
    }
    a->count = a->size;
    return (0);
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
        temp[i] = ft_atoi(argv[i+1]);
        i++;
    }
    map_temp_to_stacka(a, temp, a->size);
    free(temp);
    return (0);
}
