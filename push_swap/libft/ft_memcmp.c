/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 18:00:39 by takbar        #+#    #+#                 */
/*   Updated: 2022/12/09 17:33:03 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	size_t			i;

	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((s1_c)[i] != (s2_c)[i])
		{
			return ((s1_c)[i] - (s2_c)[i]);
		}
		i++;
	}
	return (0);
}
/*int main(void)
{
	printf("%d\n", ft_memcmp("42", "Codam", 2));
	printf("%d\n", memcmp("42", "Codam", 2));
}*/
