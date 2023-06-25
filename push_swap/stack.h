/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 19:21:39 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/25 19:24:29 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdio.h>
# include <stdlib.h>

struct stack
{
    int *stack_arr;
    int size;
    int count;
};

int	push(struct stack *s, int number);
int	pop(struct stack *s, int *number);
int	is_stack_sorted(struct stack *s);
int	stack_smallest_index(struct stack *s);
int	stack_largest_index(struct stack *s);
// to be removed later.
void print_stacks(struct stack *a, struct stack *b);

#endif
