/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 14:53:19 by takbar        #+#    #+#                 */
/*   Updated: 2022/11/27 19:22:18 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putnbr_fd(-2, fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
/*
int	main(void)
{
	printf("====ft_putnbr_fd====\n");
	printf("====-2147483648====\n");
	ft_putnbr_fd(INT_MIN_STR, 1);
	printf("\n====MAX_OF_INT====\n");
	ft_putnbr_fd(2147483647, 1);
	printf("\n");
	return (0);
}
*/
