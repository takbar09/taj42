/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 16:49:00 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/31 11:58:59 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
/*#include<string.h>*/
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
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
	char dest[11] = "hello";
	char src[6] = "World";
	char dest1[11] = "hello";
	char src1[6] = "World";
	printf("%s", ft_strcat(dest, src));
	printf("\n%s", strcat(dest1, src1));
	return (0);
}*/
