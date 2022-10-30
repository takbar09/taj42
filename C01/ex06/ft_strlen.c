/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 15:11:20 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/23 16:34:01 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
int	ft_strlen(char *str);

int	ft_strlen(char *str)

{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}
/*int main()

{
	char *s;
	
	s = "Hello";

	ft_strlen(s);
	return (0);
}*/
