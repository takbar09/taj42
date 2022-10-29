/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_comb.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 11:19:19 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/22 11:30:29 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print_num(char i, char j, char k)

{
	write (1, &i, 1);
	write (1, &j, 1);
	write (1, &k, 1);
}

void	ft_print_comb(void)

{
	char	i;
	char	j;
	char	k;

	i = 48;
	while (i <= 55)
	{
		j = i + 1;
		while (j <= 56)
		{
			k = j + 1;
			while (k <= 57)
			{
				if (i == 55 && j == 56 && k == 57)
					ft_print_num(i, j, k);
				else
					ft_print_num(i, j, k);
				write (1, ", ", 1);
				k++;
			}
			j++;
		}
		i++;
	}
}

int	main(void)

{
	ft_print_comb();
	return (0);
}
