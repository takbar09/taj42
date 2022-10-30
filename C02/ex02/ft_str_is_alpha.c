/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_alpha.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:00:58 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/29 11:57:42 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
int	ft_str_is_alpha(char *str)

{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
	i++;
	}
	return (1);
}
/*int main()

{
	printf("%d", ft_str_is_alpha("ab123f"));
	printf("%d", ft_str_is_alpha("abcdef"));
	printf("%d", ft_str_is_alpha(""));

			return (0);
}*/
