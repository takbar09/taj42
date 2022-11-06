/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:55:42 by takbar        #+#    #+#                 */
/*   Updated: 2022/11/05 18:19:13 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
int	ft_isdigit(int c)

{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*int main()

{
	printf("%d",ft_isdigit("012345"));
	printf("%d",ft_isdigit(""));
	printf("%d",ft_isdigit("abcdeA&"));
}*/
