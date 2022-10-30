/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultimate_div_mod.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 14:02:06 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/23 16:45:57 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)

{
	int	div;
	int	mod;

	div = (*a) / (*b);
	mod = (*a) % (*b);
	*a = div;
	*b = mod;
}
/*int	main()

{
	int x;
	int y;
	int u;
	int v;

	x = 17;
	y = 5;
	u = x;
	v = y;

	ft_ultimate_div_mod(&x,&y);
	printf("%d\n", u);
	printf("%d\n", v);
	printf("%d\n", x);
	printf("%d\n", y);
}*/
