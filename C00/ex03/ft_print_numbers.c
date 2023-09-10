/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_numbers.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 16:08:19 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/17 16:17:07 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print_numbers(void)

{
	int n;
	char c;

	n = 0;
	while (n <= 9)
	{
		c = n + 48;
		write(1, &c, 1);
		n++;
	}
	write(1, "\n", 1);
}
int main(void)
{
	ft_print_numbers();
}
