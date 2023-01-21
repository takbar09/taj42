#include <stdio.h>
#include <io.h>
#include <stdarg.h>
//#include <unistd.h>
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int ft_putunbr(unsigned int x);
int ft_putchar(int c);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_hex(unsigned int num, const char format);

int	ft_formats(va_list arg, const char format)
{
	int	final_length;
	final_length = 0;
	if (format == 'c')
		final_length += ft_putchar(va_arg(arg, int));
    if (format == 's')
        final_length += ft_putstr(va_arg(arg, char *));
    if (format == 'd' || format == 'i')
		final_length += ft_putnbr(va_arg(arg, int));
    if (format == 'u')
		final_length += ft_putunbr(va_arg(arg, unsigned int));
    if (format == 'p')
        final_length += ft_print_ptr(va_arg(arg, unsigned int));
    if (format == 'x' || format == 'X')
        final_length += ft_print_hex(va_arg(arg, unsigned int), format);
    if (format == '%')
        final_length = write(1, "%", 1);
	return (final_length);
}
int ft_printf(const char *format, ...)
{
	int i;/*iterator*/
	int final_length;/*final length of the formatted string*/
	va_list arg_ptr;/* points to each unnamed arg in turn */
	i = 0;
	final_length = 0;

    if (format == NULL)
        return -1;
	va_start(arg_ptr, format);/*make arg_ptr point to the 1st unnamed arg */
	while (format[i])
	{
		if (format[i] == '%')
        {
            final_length = final_length + ft_formats(arg_ptr, format[i + 1]);
            i++;       
        }
		else
			final_length = final_length + ft_putchar(format[i]);
		i++;
	}
	va_end(arg_ptr);
	return (final_length);
}

int main()
{
int x;
x = 5;
int *ptr = &x;
ft_printf("Hello World\n");
printf("Hello World\n");
ft_printf("");
printf("");
//ft_printf(0);
//printf(0);
ft_printf("Characters: %c %c tt\n", 'a','b');
printf("Characters: %c %c tt\n", 'a','b');
ft_printf("%%\n");
printf("%%\n");
ft_printf("%s\n", NULL);
printf("%s\n", NULL);
ft_printf("%s\n", "ab");
printf("%s\n", "ab");
ft_printf("%d\n", 12);
printf("%d\n", 12);
ft_printf("%u\n", -12);
printf("%u\n", -12);
printf("%x\n", 12);
ft_printf("The address is %p and the value is %d", x, x);
return 0;
}