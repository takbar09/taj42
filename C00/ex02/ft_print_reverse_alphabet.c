/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_reverse_alphabet.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 15:46:20 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/17 15:51:36 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)

{
	char	c;

	c = 122;
	while (c >= 97)
	{
		write(1, &c, 1);
		c--;
	}
	write(1, "\n", 1);
}

int main(void)
{
	ft_print_reverse_alphabet();
}
