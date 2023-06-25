/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 19:20:19 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/25 19:20:50 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_STACK_H
# define INIT_STACK_H
# include <stdio.h>
# include <stdlib.h>
# include "stack.h"
# include "libft/libft.h"

int	init_stacks(int arg_count, char **args, struct stack *a, struct stack *b);

#endif
