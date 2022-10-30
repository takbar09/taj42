/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 12:22:17 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/23 18:20:37 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)

{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
}
/*int	main()

{
	int x;
	int y;

	x = 17;
	y = 5;

	ft_swap(&x, &y);
	printf("%i\n", x);
	printf("%i", y);
	return(0);
}*/
