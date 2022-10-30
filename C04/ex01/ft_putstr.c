/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 15:12:21 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/30 16:20:14 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		str++;
	}
}
/*int main()
{
	char str[] = "Hello";

	ft_putstr(str);
}*/
