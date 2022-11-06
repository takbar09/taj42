/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 20:31:04 by takbar        #+#    #+#                 */
/*   Updated: 2022/11/05 17:36:09 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include "libft.h"

int main()

{
	printf("%d", ft_isalpha("ab123f"));
	printf("%d", ft_isalpha("abcdef"));
	printf("%d", ft_isalpha(""));

			return (0);
}

