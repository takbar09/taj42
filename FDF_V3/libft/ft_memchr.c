/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 12:27:34 by takbar        #+#    #+#                 */
/*   Updated: 2022/12/09 17:28:16 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if ((*ptr) == (unsigned char) c)
			return ((unsigned char *)ptr);
		i++;
		ptr++;
	}
	return (NULL);
}

/*int main()
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%p\n", ft_memchr(tab, -1, 7));
	printf("%p\n", memchr(tab, -1, 7));
}*/
