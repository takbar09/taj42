/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 21:01:52 by takbar        #+#    #+#                 */
/*   Updated: 2022/12/09 17:14:37 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(count * size);
	if (mem == NULL)
		return (0);
	while (i < (count * size))
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
/*int main(void)
{
	printf("%p\n", ft_calloc(5,1));
	printf("%lu\n", sizeof(ft_calloc(5,1)));
	printf("%p\n", calloc(5,1));
	printf("%lu\n", sizeof(calloc(5,1)));
}*/
