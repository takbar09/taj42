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
	if (data->mlx_ptr)
		mlx_close_window(data->mlx_ptr);

	i=0;
	if (data->p_matrix){
		while (i < data->max_y){
			if(data->p_matrix[i])
				free(data->p_matrix[i]);
			i++;
		}
		free(data->p_matrix);
	}
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int n;
	int result;

	i = 0;
	n = 1;
	result = 0;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - 48;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result += str[i] - 55;
		else if (str[i] >= 'a' && str[i] <= 'z')
			result += str[i] - 87;
		i++;
	}
	return (result * n);
}
