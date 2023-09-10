/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:12:13 by takbar            #+#    #+#             */
/*   Updated: 2023/08/06 15:30:15 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "fdf.h"

int absolute(int x){
	if (x >= 0)
		return (x);
	else
		return (-1*x);
}

int get_max(int x1, int x2){
	if (x1 >= x2)
		return x1;
	else
		return x2;
}

void free_resources(t_data *data){
	int i;
	mlx_close_window(data->mlx_ptr);

	i=0;
	if (!data->p_matrix){
		while (i < data->max_y){
			if(!data->p_matrix[i])
				free(data->p_matrix[i]);
		}
	}
	free(data->p_matrix);
}
