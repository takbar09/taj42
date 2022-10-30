/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rev_int_tab.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 14:17:28 by takbar        #+#    #+#                 */
/*   Updated: 2022/09/01 16:05:43 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	c;

	i = 0;
	while (i < size / 2)
	{
		c = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = c;
		i++;
	}
}
/*int main()
{
	int tab[] = {1, 2, 3, 4, 604, 392, -3902, 9};
	int size;
	int	index;
	size = 8;
	ft_rev_int_tab(tab,size);
	index = 0;
	while (index < size)
	{
		printf("%d, ", tab[index]);
		index++;
	}
	return (0);
	//printf("%d, %d, %d, %d",tab[0],tab[1],tab[2],tab[3],tab);
}*/
