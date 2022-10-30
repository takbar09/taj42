/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:25:46 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/31 22:30:26 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		putchar('-');
		putchar('2');
		write (1, "147483648", 9);
	}
	else if (nb < 0)
	{
		putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		putchar(nb + 48);
	}
}

/*int	main()
{
	int nb;

	nb = -10;
	ft_putnbr(nb);
	return (0);
}*/
