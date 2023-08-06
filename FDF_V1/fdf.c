/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:12:13 by takbar            #+#    #+#             */
/*   Updated: 2023/08/06 15:30:15 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 
 * -----------------program structure-----------------
 *  1. read file
 *  	- get height ( 
*/
#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft/libft.h"

/*int deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}*/
// initializes map for usage
t_data	*data_init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_printf("Error allocating map in map_init");
	data->height = 0;
	data->width = 0;
	data->z_matrix = NULL;
	data->max = 0;
	data->min = 0;
	return (data);
}
/*int main (int argc, char **argv)
{
	t_data *data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!argv[1])
		return (0);
	read_file(argv[1], data);

	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%d ", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("success");
}*/
int main(int argc, char **argv)
{
	t_data *data;

	data = data_init();
	if (argc != 2)
		ft_printf("Error\n");
	if (!argv[1])
		return (0);
	data = parse_map(data, argv[1]);
	data->mlx_ptr = mlx_init();
	data->win_prt = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	void drawLine(10, 10, 600, 300, data);
	mlx_key_hook(win_ptr, deal_key, NULL);
	mlx_loop(mlx_ptr);
/*	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			ft_printf("%d ", data->z_matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	system("leaks fdf");
	ft_printf("success");*/
}
