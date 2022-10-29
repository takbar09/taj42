/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_comb2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 15:17:41 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/18 17:18:24 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void)
{
	char	i;
	char	j;
	
	j = '0';
	while (j <= '9')
	{
		i = 1;
		while (i <= '9')
		{
			write (1, "0", 1);
			write (1, "0", 1);
			write (1, " ", 1);
			write (1, &j, 1);
			write (1, &i, 1);
			write (1, ", ", 2);
			i++;
		}
		i = '0';
		j++;
	}
}

int	main(void)
{
	ft_print_comb2();
}
