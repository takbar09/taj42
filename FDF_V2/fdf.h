/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:14:51 by takbar            #+#    #+#             */
/*   Updated: 2023/09/03 17:15:30 by takbar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

typedef struct data
{
	int width;
	int height;
	int max;
	int min;
	int **z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

//void read_file(char *file_name, t_data *data);

int					get_height(char *filename);

int					count_words(char *str, char c);

int					*parse_line(char *line, t_data *data);

t_data				*parse_map(t_data *data, char *filename);

//void drawLine(int x0, int y0, int x1, int y1, t_data *data);

#endif

