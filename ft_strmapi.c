#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if ((str == NULL) || (f == NULL))
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
**static char	ft_odd_index_upper(unsigned int n, char c)
**{
**	if (n % 2 != 0)
**		if (c >= 'a' && c <= 'z')
**			return (c - 32);
**		else
**			return (c);
**	else
**		return (c);
**}
**
**int	main(void)
**{
**	printf("====ft_strmapi====\n");
**	printf("====cAdEt42SeOuL====\n");
**	printf("%s\n", ft_strmapi("cadet42seoul", ft_odd_index_upper));
**	return (0);
**}
*/