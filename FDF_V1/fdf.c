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

void init_data (t_data *data, char *filename)
{
	data->win_ptr = 0;
    data->mlx_ptr = 0;
    data->scale = 50;
	data->angle = 0.523599;
	data->x_offset = 200;
	data->y_offset = 200;
    parse_map(data, filename);
}

int init_window(t_data *data)
{
	mlx_t* mlx;
    mlx_image_t* image;
	if (!(mlx = mlx_init(data->max_x*data->scale*1.3 + data->x_offset, data->max_y*data->scale*1.3 + data->y_offset, "MLX42", true)))
		return(-1);

	if (!(image = mlx_new_image(mlx, data->max_x*data->scale*1.3 + data->x_offset, data->max_y*data->scale*1.3+data->y_offset)))
	{
		mlx_close_window(mlx);
		return(-1);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		return(-1);
	}
	data->mlx_ptr = mlx;
	data->win_ptr = image;
	return (0);
}

int main(int argc, char **argv) {
    t_data data;

	if (argc != 2)
		printf("Error\n");
	if (!argv[1])
		return (0);

	init_data(&data, argv[1]);
	if (init_window(&data) < 0)
		return(-1);

	draw(&data);
	//mlx_loop_hook(mlx, draw, &data);
	mlx_loop(data.mlx_ptr);
	mlx_terminate(data.mlx_ptr);
	return (-1);
}
