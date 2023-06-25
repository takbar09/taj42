/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 15:50:45 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/25 19:31:53 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "commands.h"
#include "init_stack.h"
#include "check_args.h"

int	ft_count_word(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

int	radix_sort(struct stack *a, struct stack *b)
{
	int	bit;
	int	i;

	bit = 0;
	while (bit < 32)
	{
		i = 0;
		while (i < a->size)
		{
			if (is_stack_sorted(a))
				break ;
			if (a->stack_arr[0] & (1 << bit))
				rotate_ab(a, 'a');
			else
				push_ab(a, b, 'b');
			i++;
		}
		while (b->count > 0)
			push_ab(a, b, 'a');
		bit++;
	}
	return (0);
}

int	push_swap(int arg_count, char **args)
{
	struct stack	a;
	struct stack	b;

	if (!args)
		return (-1);
	if (check_args(arg_count, args) == -1)
		return (-1);
	if (init_stacks(arg_count, args, &a, &b) == -1)
		return (-1);
	print_stacks(&a, &b);
	if (a.size <= 5)
		simple_sort(&a, &b);
	if (a.size > 5)
		radix_sort(&a, &b);
	free(a.stack_arr);
	free(b.stack_arr);
	return (0);
}

int	main(int argc, char **argv)
{
	int		return_value;
	char	**args;
	int		arg_count;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		arg_count = ft_count_word(argv[1], ' ');
		args = ft_split(argv[1], ' ');
	}
	if (argc > 2)
	{
		arg_count = argc - 1;
		args = argv + 1;
	}
	return_value = push_swap(arg_count, args);
	if (return_value == -1)
		printf ("Error\n");
	return (return_value);
}
