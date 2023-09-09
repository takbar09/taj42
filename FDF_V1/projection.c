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

void scale(t_point *p, t_data *data)
{
	p->x = p->x * data->scale;
	p->y = p->y * data->scale;
	p->z = p->z * 7;

}

void projection(t_point *p, double angle)
{
	int prev_x = p->x;
	int prev_y = p->y;

	p->x = (prev_x - prev_y) * cos(angle);
	p->y = (prev_x + prev_y) * sin(0.55) - p->z;
}

