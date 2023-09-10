/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_alphabet.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/12 14:26:34 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/17 18:15:54 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 97;
	while (c <= 122)
	{
		write(1, &c, 1);
		c++;
	}
	write(1, "\n", 1);
}
int main(void)
{
	ft_print_alphabet();
}
