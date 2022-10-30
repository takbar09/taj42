/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_int_tab.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 14:39:33 by takbar        #+#    #+#                 */
/*   Updated: 2022/09/01 16:01:00 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/
void	ft_sort_int_tab(int *tab, int size)
{
	int	j;
	int	tmp;

	while (size > 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		size--;
	}
}
/*int main ()
{
	int tab[] = {5, 30, 4, 18, 50, -74, 1685, 4, 19, -5, 8};
	int size;
	int	index;

	size = 11;
	index = 0;
	while (index < size)
	{
		printf("%d, ", tab[index]);
		index++;
	}
	printf("\n");
	ft_sort_int_tab(tab,size);
	index = 0;
	while (index < size)
	{
		printf("%d, ", tab[index]);
		index++;
	}
	//printf("%d,%d,%d,%d,%d",tab[0],tab[1],tab[2],tab[3],tab[4]);
}*/
