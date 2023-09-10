/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:12:13 by takbar            #+#    #+#             */
/*   Updated: 2023/09/10 19:29:13 by takbar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	absolute(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-1 * x);
}

int	get_max(int x1, int x2)
{
	if (x1 >= x2)
		return (x1);
	else
		return (x2);
}

void	free_resources(t_data *data)
{
	int	i;

	mlx_close_window(data->mlx_ptr);
	i = 0;
	if (!data->p_matrix)
	{
		while (i < data->max_y)
		{
			if (!data->p_matrix[i])
				free(data->p_matrix[i]);
		}
	}
	free(data->p_matrix);
}

char	**ft_mem_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

int	count_words(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || *str == '\0')
		return (0);
	while (*str)
	{
		if (*str != c)
		{
			++i;
			while (*str && *str != c)
				++str;
		}
		else
			str++;
	}
	return (i);
}
