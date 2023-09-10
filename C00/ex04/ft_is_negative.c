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
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
	write(1, "\n", 1);
}

int main(void)
{
	int n;

	n = 0;
	ft_is_negative(n);
}
