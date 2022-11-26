#include <stdlib.h>
#include <stdio.h>

int	ft_len(int n)
{
	int len;

	len = 0;

    if (n == 0)
        len++;

	if (n < 0)
	{
		n = -1*n;
		len++;
	}

	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}


char *ft_itoa(int n)
{
	char *str;
	int	len;
    int r;

	len = ft_len(n);
    if (!(str = (char *)malloc(sizeof(char ) * (len + 1))))
	return (NULL);
    str[len] = '\0';
    len--;
    if (n == 0)
        str[0]='0';
	if (n < 0)
	{
		n = -1*n;
		str[0]='-';
	}
	while (n > 0)
	{
        r = n % 10;
		n = n / 10;
        str[len--]='0'+r;
	}
	return (str);
}

int main(void)
{
	printf("%s\n",ft_itoa(0));
	printf("%s\n",ft_itoa(1));
	printf("%s\n",ft_itoa(2));
	printf("%s\n",ft_itoa(123));
	printf("%s\n",ft_itoa(-1));
	printf("%s\n",ft_itoa(-2345));
	printf("%s\n",ft_itoa(11111111));
    return (0);
}
