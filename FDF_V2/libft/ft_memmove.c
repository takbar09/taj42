/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 16:52:29 by takbar        #+#    #+#                 */
/*   Updated: 2022/12/09 17:51:58 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (n > 0)
		{
			((char *)dst)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*int main(void)
{
	char s1[] = "Codam is in amsterdam";
	char s2[] = "Codam is in asmterdam";

	ft_memmove(s1 + 20, s1 + 10, 1);
	printf("%s\n", s1);
}*/
