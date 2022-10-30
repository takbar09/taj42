/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 13:51:34 by takbar        #+#    #+#                 */
/*   Updated: 2022/09/01 16:18:13 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
/*#include<string.h>*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/*int	main()
{
	unsigned int	n;

	n = 3;
	char	s1[] = "abc";
	char	s2[] = "abg";
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
	return (0);
}*/
