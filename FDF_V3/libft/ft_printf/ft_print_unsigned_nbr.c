/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_unsigned_nbr.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 13:17:01 by takbar        #+#    #+#                 */
/*   Updated: 2023/01/27 17:22:46 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_nbr(unsigned int n)
{
	unsigned int	length;

	length = 0;
	if (n > 9)
	{
		length += ft_print_unsigned_nbr(n / 10);
		length += ft_print_unsigned_nbr(n % 10);
	}
	else
	{
		length += ft_print_char(n + 48);
	}
	return (length);
}
