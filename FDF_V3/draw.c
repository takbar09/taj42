/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:15:50 by takbar            #+#    #+#             */
/*   Updated: 2023/09/10 19:53:19 by takbar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"
#include <math.h>

int	clear_screen(t_data *data)
{
	data->win_ptr = mlx_new_image(data->mlx_ptr, data->window_x, data->window_y);
	mlx_delete_image(data->mlx_ptr, data->win_ptr);
	if (!(data->win_ptr))
	{
		mlx_close_window(data->mlx_ptr);
		return (-1);
	}
	if (mlx_image_to_window(data->mlx_ptr, data->win_ptr, 0, 0) == -1)
	{
		mlx_close_window(data->mlx_ptr);
		return (-1);
	}
	return (0);
}

static void	draw_line(t_data *data)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = absolute(data->p2.x - data->p1.x);
	delta.y = absolute(data->p2.y - data->p1.y);
	sign.x = data->p1.x < data->p2.x ? 1 : -1;
	sign.y = data->p1.y < data->p2.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = data->p1;
	while (cur.x != data->p2.x || cur.y != data->p2.y)
	{
		if (cur.x > 0 && cur.y > 0)
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

void	prepare_draw_point(int x, int y, t_data *data, int inc_x)
{
	data->p1 = data->p_matrix[y][x];
	scale(&data->p1, data);
	projection(&data->p1, data->angle);
	data->p1.x += data->x_offset + 300;
	data->p1.y += data->y_offset / 2;
	if (inc_x == 1)
		x++;
	if (inc_x == 0)
		y++;
	data->p2 = data->p_matrix[y][x];
	scale(&data->p2, data);
	projection(&data->p2, data->angle);
	data->p2.x += data->x_offset + 300;
	data->p2.y += data->y_offset / 2;
	data->color = (data->p1.z || data->p2.z) ? 0xFFFFFF : 0xBBFAFF;
	data->color = (data->p2.z != data->p1.z) ? 0xFFFFFF : data->color;
	if (data->p1.color != 0)
		data->color = data->p1.color << 8 | 0xFF;
	return ;
}

void	draw(void *d)
{
	t_data	*data;
	int		y;
	int		x;

	data = d;
	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			if (y + 1 < data->max_y)
			{
				prepare_draw_point(x, y, data, 0);
				draw_line(data);
			}
			if (x + 1 < data->max_x)
			{
				prepare_draw_point(x, y, data, 1);
				draw_line(data);
			}
			x++;
		}
		y++;
	}
}
