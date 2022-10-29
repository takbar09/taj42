/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_negative.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 16:19:56 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/17 16:39:52 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)

{
	char	x;
	char	y;

	x = 'N';
	y = 'P';
	if (n < 0)
		write (1, &x, 1);
	else
		write (1, &y, 1);
}
