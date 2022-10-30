/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_div_mod.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 12:35:13 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/23 16:49:25 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)

{
	*div = a / b;
	*mod = a % b;
}
/*int main()

{
	int x;
	int y;
	int div;
	int mod;

	x = 17;
	y = 5;

	ft_div_mod(x,y,&div,&mod);
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n",div);
	printf("%d",mod);
	return (0);
}*/
