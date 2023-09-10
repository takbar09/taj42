/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:07:14 by takbar            #+#    #+#             */
/*   Updated: 2023/09/10 18:53:40 by takbar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

int	get_max_y(char *filename)
{
	int		y;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
	return (y);
}

// parses line to find value of each point
t_point	*parse_line(char *line, t_data *data, int y)
{
	t_point	*row;
	char	**words;
	char	**comma_sep_words;
	int		i;

	words = ft_split(line, ' ');
	row = malloc(sizeof(t_point) * data->max_x);
	i = -1;
	while (++i < data->max_x)
	{
		row[i].x = i;
		row[i].y = y;
		row[i].color = 0;
		if (count_words(words[i], ',') > 1)
		{
			comma_sep_words = ft_split(words[i], ',');
			row[i].z = atoi(comma_sep_words[0]);
			row[i].color = strtol(comma_sep_words[1], NULL, 16);
			ft_mem_free(comma_sep_words);
		}
		else
			row[i].z = atoi(words[i]);
	}
	ft_mem_free(words);
	return (row);
}

int	get_max_x(char *filename)
{
	char	*line;
	int		fd;
	int		max_x;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Cannot read from file in parse_map");
		return (-1);
	}
	line = get_next_line(fd);
	max_x = count_words(line, ' ');
	close(fd);
	return (max_x);
}

int	read_points(t_data *data, char *filename)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	data->p_matrix = malloc(sizeof(t_point *) * data->max_y);
	if (!data->p_matrix)
		return (-1);
	i = 0;
	while (line != NULL)
	{
		data->p_matrix[i] = parse_line(line, data, i);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

// returns a map struct with array storing X-Y-Z values from file
void	parse_map(t_data *data,	char *filename)
{
	data->max_y = get_max_y(filename);
	data->max_x = get_max_x(filename);
	printf("max_y = %d,  max_x=%d\n", data->max_y, data->max_x);
	read_points(data, filename);
	write (1, "Sucess", 6);
	return ;
}
