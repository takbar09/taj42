/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_voidptr_hex.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 17:53:57 by takbar        #+#    #+#                 */
/*   Updated: 2023/01/27 17:22:59 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_to_hex(unsigned long long n)
{
	char			*hex_value;
	unsigned int	length;

	length = 0;
	hex_value = "0123456789abcdef";
	if (n > 15)
	{
		length += ft_ptr_to_hex((n / 16));
		length += ft_ptr_to_hex((n % 16));
	}
	else
	{
		length += ft_print_char(hex_value[n % 16]);
	}
	return (length);
}

int	ft_print_voidptr_hex(unsigned long long n)
{
	unsigned int	length;

	length = 0;
	length += write(1, "0x", 2);
	length += ft_ptr_to_hex(n);
	return (length);
}
