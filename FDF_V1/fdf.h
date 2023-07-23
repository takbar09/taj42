/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/23 14:14:51 by takbar        #+#    #+#                 */
/*   Updated: 2023/07/23 17:38:59 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

typedef struct
{
	int width;
	int height;
	int **z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

void read_file(char *file_name, fdf *data);

#endif

