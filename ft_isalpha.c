/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:00:58 by takbar        #+#    #+#                 */
/*   Updated: 2022/11/06 13:25:20 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*#include<stdio.h>*/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*int main()

{
	printf("%d", ft_isalpha("ab123f"));
	printf("%d", ft_isalpha("abcdef"));
	printf("%d", ft_isalpha(""));

			return (0);
}*/
