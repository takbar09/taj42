/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex_nbr.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 16:47:30 by takbar        #+#    #+#                 */
/*   Updated: 2023/01/27 17:21:34 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_nbr(unsigned int n, char iscase)
{
	char			*hex_value;
	unsigned int	length;

	length = 0;
	if (iscase == 'x')
	{
		hex_value = "0123456789abcdef";
	}
	if (iscase == 'X')
	{
		hex_value = "0123456789ABCDEF";
	}
	if (n > 15)
	{
		length += ft_print_hex_nbr((n / 16), iscase);
		length += ft_print_hex_nbr((n % 16), iscase);
	}
	else
	{
		length = ft_print_char(hex_value[n % 16]);
	}
	return (length);
}
