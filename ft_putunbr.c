#include <stdio.h>
#include <io.h>
#include <stdarg.h>
//#include <unistd.h>

int ft_putchar(int c);

int ft_putunbr(unsigned int x)
{
    unsigned int number;
    unsigned int length;

    number = x;
    length = 0;
    if (number > 9)
    {
        length += ft_putunbr(number / 10);
        length += ft_putunbr(number % 10);
    }
    if (number <= 9)
        length += ft_putchar(number + '0');
    return (length);
}