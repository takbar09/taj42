/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 16:05:50 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/25 18:57:17 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "commands.h"
#include "stack.h"
#include "init_stack.h"

static int	command_count = 0;

int	swap_ab(struct stack *s, char c)
{
	int	number1;
	int	number2;

	pop(s, &number1);
	pop(s, &number2);
	push(s, number1);
	push(s, number2);
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
	command_count++;
	ft_printf("Comamnd count %d\n", command_count);
	return (0);
}

int	push_ab(struct stack *a, struct stack *b, char c)
{
	int	number;

	if (c == 'a')
	{
		pop(b, &number);
		push(a, number);
		ft_printf("pa\n");
	}
	if (c == 'b')
	{
		pop(a, &number);
		push(b, number);
		ft_printf("pb\n");
	}
	command_count++;
	ft_printf("Comamnd count %d\n", command_count);
	return (0);
}

int	rotate_ab(struct stack *s, char c)
{
	int	number;

	pop(s, &number);
	s->stack_arr[s->count] = number;
	s->count++;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
	command_count++;
	ft_printf("Comamnd count %d\n", command_count);
	return (0);
}

int	reverse_rotate_ab(struct stack *s, char c)
{
	int	number;

	number = s->stack_arr[s->count - 1];
	s->count--;
	push(s, number);
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
	command_count++;
	ft_printf("Comamnd count %d\n", command_count);
	return (0);
}
