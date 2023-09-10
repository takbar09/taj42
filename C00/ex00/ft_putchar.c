/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 15:00:32 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/17 13:08:54 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main (void)
{
	char c;

	c = 'a';
	ft_putchar(c);
	write(1, "\n", 1);
}
