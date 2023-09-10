/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_nbr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 12:34:42 by takbar        #+#    #+#                 */
/*   Updated: 2023/04/15 14:30:28 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		length += ft_print_char('-') + write(1, "2147483648", 10);
	}
	else if (n < 0)
	{
		n = n * -1;
		length += ft_print_char('-') + ft_print_nbr(n);
	}
	else if (n > 9)
	{
		length += ft_print_nbr(n / 10);
		length += ft_print_nbr(n % 10);
	}
	else
	{
		length += ft_print_char(n + 48);
	}
	return (length);
}
