/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 12:36:29 by takbar        #+#    #+#                 */
/*   Updated: 2022/12/09 17:13:03 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
/*int main(void)
{
	char s1[10] = "codam42";
	char s2[10] = "codam42";

	ft_bzero(s1, sizeof(s1) - 1);
	printf("%s\n", s1);
	bzero(s2, sizeof(s2) - 1);
	printf("%s\n", s2);
}*/
