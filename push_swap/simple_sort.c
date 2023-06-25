/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 18:47:27 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/25 19:14:48 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "commands.h"

void	push_min_to_stack_b(struct stack *a, struct stack *b)
{
	int	smallest_index;

	smallest_index = stack_smallest_index(a);
	while (smallest_index != 0)
	{
		if (smallest_index < a->count / 2)
			rotate_ab(a, 'a');
		else
			reverse_rotate_ab(a, 'a');
		smallest_index = stack_smallest_index(a);
	}
	push_ab(a, b, 'b');
}

void	push_max_to_end(struct stack *a)
{
	int	largest_index;

	largest_index = stack_largest_index(a);
	if (largest_index == 0)
		rotate_ab(a, 'a');
	if (largest_index == 1)
		reverse_rotate_ab(a, 'a');
}

void	simple_sort(struct stack *a, struct stack *b)
{
	if (is_stack_sorted(a))
		return ;
	while (a->count > 3)
		push_min_to_stack_b(a, b);
	if (a->count == 3)
		push_max_to_end(a);
	if (a->count == 3 || a->count == 2)
		if (a->stack_arr[0] > a->stack_arr[1])
			swap_ab(a, 'a');
	while (b->count > 0)
		push_ab(a, b, 'a');
}
