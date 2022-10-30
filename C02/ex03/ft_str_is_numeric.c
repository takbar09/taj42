/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_numeric.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:55:42 by takbar        #+#    #+#                 */
/*   Updated: 2022/10/28 20:19:25 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
int	ft_str_is_numeric(char *str)

{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

/*int main()

{
	printf("%d",ft_str_is_numeric("012345"));
	printf("%d",ft_str_is_numeric(""));
	printf("%d",ft_str_is_numeric("abcdeA&"));
}*/
