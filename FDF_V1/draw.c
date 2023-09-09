/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:15:50 by takbar            #+#    #+#             */
/*   Updated: 2023/09/09 17:58:05 by takbar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"
#include <math.h>

void init_point(int x, int y, int z, t_point *p)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

static void	draw_line(t_data *data)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int	error[2];

	delta.x = absolute(data->p2.x - data->p1.x);
	delta.y = absolute(data->p2.y - data->p1.y);
	sign.x = data->p1.x < data->p2.x ? 1 : -1;
	sign.y = data->p1.y < data->p2.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = data->p1;
	while (cur.x != data->p2.x || cur.y != data->p2.y)
	{
		mlx_put_pixel(data->win_ptr, cur.x, cur.y, data->color);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void prepare_draw_point(int x, int y, t_data *data, int inc_x)
{
	init_point(x, y, data->z_matrix[y][x], &data->p1);
	scale(&data->p1, data);
	projection(&data->p1, data->angle);
	data->p1.x += data->x_offset+300;
	data->p1.y += data->y_offset/2;

	if (inc_x == 1)
		x++;
	else
		y++;

	init_point(x, y, data->z_matrix[y][x], &data->p2);
	scale(&data->p2, data);
	projection(&data->p2, data->angle);
	data->p2.x += data->x_offset+300;
	data->p2.y += data->y_offset/2;
	data->color = (data->p1.z || data->p2.z) ? 0xFFFFFFFF : 0xBBFAFFFF;
	data->color = (data->p2.z != data->p1.z) ? 0xFFFFFFFF : data->color;
	// 0xffffff
	// 0x00ffffff
	// bit-wise operations to be used for map colors

	return;
}

void draw(void *d)
{
	t_data *data;
	int		y;
	int		x;

	data = d;
	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{	
			if (y+1 < data->max_y)
			{
				prepare_draw_point(x,y, data, 0);
				draw_line(data);
			}
			if (x+1 < data->max_x)
			{
				prepare_draw_point(x,y, data, 1);
				draw_line(data);
			}
				
			x++;
		}
		y++;
	}
}
/*
int main(int argc, char **argv) {
    //int x0 = 1, y0 = 1; // Starting point
    //int x1 = 8, y1 = 5; // Ending point
    t_data data;
    data.win_ptr = 0;
    data.mlx_ptr = 0;
    mlx_image_t* image;
    
	
	
	mlx_t* mlx;
    void parse_map(t_data *data, char *filename);
    parse_map(&data, argv[1]);
	data.scale = 50;
	data.angle = .5;
	data.x_offset = 200;
	data.y_offset = 200;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(data.max_x*data.scale*1.3 + data.x_offset, data.max_y*data.scale*1.3 + data.y_offset, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(-1);
	}
	if (!(image = mlx_new_image(mlx, data.max_x*data.scale*1.3 + data.x_offset, data.max_y*data.scale*1.3+data.y_offset)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(-1);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(-1);
	}

	data.mlx_ptr = mlx;
	data.win_ptr = image;
	draw(&data);
	//mlx_loop_hook(mlx, draw, &data);
	
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (-1);
}
*/
