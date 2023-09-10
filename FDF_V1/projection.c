/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/06 11:15:50 by takbar        #+#    #+#                 */
/*   Updated: 2023/08/06 18:58:16 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "stdio.h"
#include <math.h>

void calculate_scale(t_data *data){
	int	y;
	int	x;
	int max_z;

	if (data->max_x > data->max_y)
		data->scale = data->window_x/(data->max_x*2);
	else
		data->scale = data->window_y/(data->max_y*2);
	y = 0;
	max_z = 0;
	while (y < data->max_y){
		x = 0;
		while (x < data->max_x){
			if (absolute(data->p_matrix[y][x].z) > max_z)
				max_z =  absolute(data->p_matrix[y][x].z);
			x++;
		}
		y++;
	}
	if (max_z < 50)
		data->z_scale = 50/max_z;
}

void scale(t_point *p, t_data *data){
	p->x = p->x * data->scale;
	p->y = p->y * data->scale;
	p->z = p->z * data->z_scale;

}

void projection(t_point *p, double angle){
	int prev_x = p->x;
	int prev_y = p->y;

	p->x = (prev_x - prev_y) * cos(angle);
	p->y = (prev_x + prev_y) * sin(0.55) - p->z;
}
