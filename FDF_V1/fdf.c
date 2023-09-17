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

void init_data (t_data *data, char *filename){
	data->win_ptr = 0;
    data->mlx_ptr = 0;
	data->angle = 0.523599;
	data->window_x = 1800;
	data->window_y = 1200;
	data->x_offset = 450;
	data->y_offset = 100;
	data->p_matrix = 0;
    parse_map(data, filename);
	calculate_scale(data);
}

int init_window(t_data *data){
	mlx_t* mlx;
    mlx_image_t* image;
	if (!(mlx = mlx_init(data->window_x, data->window_y, "FDF", true)))
		return(-1);

	if (!(image = mlx_new_image(mlx, data->window_x, data->window_y))){
		mlx_close_window(mlx);
		return(-1);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1){
		mlx_close_window(mlx);
		return(-1);
	}
	data->mlx_ptr = mlx;
	data->win_ptr = image;
	return (0);
}

void close_handler(void* param){
	t_data *data;
	
	data = param;
	free_resources(data);
}

void key_handler(void* param){
	t_data *data = param;

	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE)){
		free_resources(data);
	}
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_UP)){
		data->y_offset -= 20;
		clear_screen(data);
	}
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_DOWN)){
		data->y_offset += 20;
		clear_screen(data);
	}
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_LEFT)){
		data->x_offset -= 20;
		clear_screen(data);
	}
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT)){
		data->x_offset += 20;
		clear_screen(data);
	}
}

int main(int argc, char **argv)
{
    t_data data;

	if (argc != 2)
		printf("Error\n");
	if (!argv[1])
		return (0);

	data.p_matrix = 0;
	init_data(&data, argv[1]);
	if (init_window(&data) < 0){
		free_resources(&data);
		return(-1);
	}
	mlx_loop_hook(data.mlx_ptr, draw, &data);
	mlx_loop_hook(data.mlx_ptr, key_handler, &data);
	mlx_close_hook(data.mlx_ptr, close_handler, &data);
	mlx_loop(data.mlx_ptr);
	mlx_terminate(data.mlx_ptr);
	system("leaks a.out");
	return (0);
}
