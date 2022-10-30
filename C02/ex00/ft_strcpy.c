/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 11:08:50 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/26 13:58:41 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
/*#include<string.h>*/
char	*ft_strcpy(char *dest, char *src)

{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int main()

{
	char src[] = "hello";
	char dest[] = "World";
	char src1[] = "hello";
	char dest1[] = "World";

	ft_strcpy(dest,src);
	strcpy(dest1,src1);
	printf("%s\n",dest);
    printf("%s",dest1);
	return (0);
}*/
