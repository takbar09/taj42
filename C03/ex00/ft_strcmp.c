/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 13:29:55 by takbar        #+#    #+#                 */
/*   Updated: 2022/09/01 16:15:36 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
int	ft_strcmp(char *s1, char *s2)

{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
	i++;
	}
	return (s1[i] - s2[i]);
}
/*int main()

{
	printf("%d",ft_strcmp("abbd", "abbc"));
	return (0);
}*/
