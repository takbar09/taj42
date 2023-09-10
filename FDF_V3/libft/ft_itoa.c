/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 17:49:03 by takbar        #+#    #+#                 */
/*   Updated: 2023/01/22 12:38:51 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_len(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	long_n;

	long_n = n;
	len = ft_len(long_n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str[len] = '\0';
	len--;
	if (long_n == 0)
		str[0] = '0';
	if (long_n < 0)
	{
		long_n = -1 * long_n;
		str[0] = '-';
	}
	while (long_n > 0)
	{
		str[len--] = '0' + (long_n % 10);
		long_n = long_n / 10;
	}
	return (str);
}
/*int main(void)
{
	long int n = -2147483648;
    int		len = ft_len(n);
    printf("itoa:%s\n", ft_itoa(n));
    printf("len:[%d]\n", len);
	printf("%s\n",ft_itoa(0));
    printf("%s\n",ft_itoa(1));
    printf("%s\n",ft:_itoa(2));
    printf("%s\n",ft_itoa(123));
    printf("%s\n",ft_itoa(-1));
    printf("%s\n",ft_itoa(-2345));
    printf("%s\n",ft_itoa(11111111));  
	return (0);
}*/
