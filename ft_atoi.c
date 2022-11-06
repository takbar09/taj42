/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/06 17:45:42 by takbar        #+#    #+#                 */
/*   Updated: 2022/11/06 19:07:08 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
/*#include <stdlib.h>*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
	i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i - 1] == '-' || str[i - 1] == '+')
			return (0);
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}
/*int main()
{
	char str[] = " +monkeys12";
	printf("%d\n",ft_atoi(str));
	printf("%d",atoi(str));
}*/
