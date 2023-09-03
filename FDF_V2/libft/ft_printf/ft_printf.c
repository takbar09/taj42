/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 13:27:32 by takbar        #+#    #+#                 */
/*   Updated: 2023/08/05 16:59:10 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list arg, const char format)
{
	int	final_length;

	final_length = 0;
	if (format == 'c')
		final_length += ft_print_char(va_arg(arg, int));
	if (format == 's')
		final_length += ft_print_str(va_arg(arg, char *));
	if (format == 'd' || format == 'i')
		final_length += ft_print_nbr(va_arg(arg, int));
	if (format == 'u')
		final_length += ft_print_unsigned_nbr(va_arg(arg, unsigned int));
	if (format == 'x' || format == 'X')
		final_length += ft_print_hex_nbr(va_arg(arg, unsigned int), format);
	if (format == 'p')
		final_length += ft_print_voidptr_hex(va_arg(arg, unsigned long long));
	if (format == '%')
		final_length = ft_print_char('%');
	return (final_length);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		final_length;
	va_list	arg_ptr;

	i = 0;
	final_length = 0;
	va_start(arg_ptr, format);
	while (format[i])
	{
		if (format[i] == '\0')
			return (0);
		if (format[i] == '%' && format[i + 1])
		{
			final_length += ft_formats(arg_ptr, format[i + 1]);
			i++;
		}
		else
			final_length += ft_print_char(format[i]);
		i++;
	}
	va_end(arg_ptr);
	return (final_length);
}
/*int main()
{
int x;
x = 5;
int *ptr = &x;
ft_printf("Hello World\n");
printf("Hello World\n");
ft_printf("");
printf("");
//ft_printf(0);
//printf(0);;
ft_printf("NULL\n");
printf("NULL\n");
ft_printf("Characters: %c %c tt\n", 'a', 'b');
printf("Characters: %c %c tt\n", 'a', 'b');
ft_printf("%s\n", "Hello, World");
printf("%s\n", "hello, World");
ft_printf("%i\n", 12);
printf("%i\n", 12);
ft_printf("%i\n", -2147483648);
printf("%i\n", -2147483648);
ft_printf("%d\n", -11);
ft_printf("%d\n", -1);
ft_printf("%x\n%X\n", 10, 10);
ft_printf("%%\n");
ft_printf("The address is %p and the alue is %d", x, x);
ft_printf("my ft_printf:  %%%\0ddjjddjj\n");
printf("\nreal printf: %%%\0ddjjddjj\n");
return 0;
}*/
