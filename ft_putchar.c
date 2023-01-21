#include <stdio.h>
#include <io.h>
#include <stdarg.h>
//#include <unistd.h>

int ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}