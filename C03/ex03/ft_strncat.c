/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 17:58:24 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/30 14:43:49 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
/*#include<string.h>*/
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while ((src[j] != '\0') && (j < nb))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int main()
{
	char dest[11] = "Hello";
	char src[6] = "World";
	char dest1[11] = "Hello";
	char src1[6] = "World";

	printf("%s", ft_strncat(dest,src,4));
	printf("\n%s", strncat(dest1,src1,4));
	return(0);
}*/
