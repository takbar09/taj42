/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 14:30:04 by takbar        #+#    #+#                 */
/*   Updated: 2022/12/04 20:03:47 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*
**int	main(void)
**{
**	ft_putchar_fd('A', 1);
**	printf("\n");
**	ft_putchar_fd('a', -1);
**	return (0);
**}
*/
