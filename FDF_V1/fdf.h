/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:14:51 by takbar            #+#    #+#             */
/*   Updated: 2023/07/30 17:13:45 by takbar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

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

#endif

