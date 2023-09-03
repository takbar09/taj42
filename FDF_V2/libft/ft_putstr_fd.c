/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 14:38:53 by takbar        #+#    #+#                 */
/*   Updated: 2022/12/04 20:03:31 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/*
**int	main(void)
**{
**	printf("====ft_putstr_fd====\n");
**	ft_putstr_fd("Amsterdam", 1);
**	printf("\n");
**	ft_putstr_fd("Codam", -1);
**	return (0);
**}
*/
