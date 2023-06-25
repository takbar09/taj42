/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 19:18:09 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/25 19:19:39 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H
# include <stdio.h>
# include <stdlib.h>
# include "stack.h"

int		swap_ab(struct stack *s, char c);
int		push_ab(struct stack *a, struct stack *b, char c);
int		rotate_ab(struct stack *s, char c);
int		reverse_rotate_ab(struct stack *s, char c);
void	push_min_to_stack_b(struct stack *a, struct stack *b);
void	push_max_to_end(struct stack *a);
void	simple_sort(struct stack *a, struct stack *b);

#endif
