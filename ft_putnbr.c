#include <stdlib.h>

char *ft_itoa(int n);
int	ft_putstr(char *str);

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}