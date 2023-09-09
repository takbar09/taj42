/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:14:51 by takbar            #+#    #+#             */
/*   Updated: 2023/08/06 18:55:03 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

//#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

typedef struct point 
{
	int x;
	int y;
	int z;
}t_point;

typedef struct data
{
	int max_x;
	int max_y;
	int max;
	int min;
	int **z_matrix;
	int scale;
	double angle;
	int x_offset;
	int y_offset;
	t_point p1;
	t_point p2;
	int color;
	void	*mlx_ptr;
	void	*win_ptr;
}t_data;

//void read_file(char *file_name, t_data *data);

int	get_height(char *filename);

int	count_words(char *str, char c);

int	*parse_line(char *line, t_data *data);

void parse_map(t_data *data, char *filename);

void drawLine(int x0, int y0, int x1, int y1, t_data *data);

int absolute(int x);

int get_max(int x1, int x2);

void draw(void *d);

void scale(t_point *p, t_data *data);

void projection(t_point *p, double angle);


#endif

