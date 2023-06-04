/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:58:02 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/04 18:31:37 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

struct stack
{
    int *stack_arr;
    int size;
    int count;
};

int push(struct stack *s, int number);
int pop(struct stack *s, int *number);
int is_stack_sorted(struct stack *s);

// to be removed later.
int print_stacks(struct stack *a, struct stack *b);

#endif
