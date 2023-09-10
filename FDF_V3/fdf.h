/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:14:51 by takbar            #+#    #+#             */
/*   Updated: 2023/09/10 19:43:46 by takbar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct point 
{
	int	x;
	int	y;
	int	z;
	int	color;
}t_point;

typedef struct data
{
	int			max_x;
	int			max_y;
	int			max;
	int			min;
	t_point		**p_matrix;
	int			scale;
	int			z_scale;
	double		angle;
	int			x_offset;
	int			y_offset;
	t_point		p1;
	t_point		p2;
	uint32_t	color;
	int			window_x;
	int			window_y;
	void		*mlx_ptr;
	void		*win_ptr;
}t_data;

int		get_height(char *filename);

char	**ft_mem_free(char **res);

int		count_words(char *str, char c);

t_point	*parse_line(char *line, t_data *data, int y);

void	parse_map(t_data *data, char *filename);

void	drawLine(int x0, int y0, int x1, int y1, t_data *data);

int		absolute(int x);

int		get_max(int x1, int x2);

void	draw(void *d);

void	scale(t_point *p, t_data *data);

void	projection(t_point *p, double angle);

void	calculate_scale(t_data *data);

int		clear_screen(t_data *data);

void	free_resources(t_data *data);

#endif