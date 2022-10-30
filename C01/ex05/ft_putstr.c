/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 14:56:18 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/30 16:39:35 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putstr(char *str)

{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}
/*int main()

{
	char	*s;

	s = "Hello\nWorld";

	ft_putstr(s);
	return(0);
}*/
