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
	int color;
}t_point;

typedef struct data
{
	int max_x;
	int max_y;
	int max;
	int min;
	t_point **p_matrix;
	int scale;
	int z_scale;
	double angle;
	int x_offset;
	int y_offset;
	t_point p1;
	t_point p2;
	uint32_t color;
	int window_x;
	int window_y;
	void	*mlx_ptr;
	void	*win_ptr;
}t_data;

int	get_height(char *filename);

int	count_words(char *str, char c);

t_point	*parse_line(char *line, t_data *data, int y);

int parse_map(t_data *data, char *filename);

int absolute(int x);

int get_max(int x1, int x2);

void draw(void *d);

void scale(t_point *p, t_data *data);

void projection(t_point *p, double angle);

void calculate_scale(t_data *data);

int clear_screen(t_data *data);

void free_resources(t_data *data);

int	ft_atoi_base(const char *str, int str_base);

int check_cmd_line_args(int argc, char **argv);

int check_line(char *line, t_data *data);

char    **ft_split(const char *s, char c);
#endif

