/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:53:46 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/04 18:18:04 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */ 

#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "libft/libft.h"

int swap_ab(struct stack *s, char c);
int push_ab(struct stack *a, struct stack *b, char c);
int rotate_ab(struct stack *s, char c);

#endif
