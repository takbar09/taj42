/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/23 14:18:47 by takbar        #+#    #+#                 */
/*   Updated: 2023/07/23 18:11:43 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fdf.h"
#include "get_next_line.h"


int ft_count_word(char const *s, char c)
{
    int i;
    int cnt;

    i = 0;
    cnt = 0;
    while (s[i])
    {
        if (s[i] == c)
            i++;
        else
        {
            cnt++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (cnt);
}

int get_height(char *file_name)
{
	int height;
	int fd;
	char *line;
	
	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while(get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int get_width(char *file_name)
{
	int width;
	int fd;
	char *line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_count_word(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void fill_matrix(int *z_line, char *line)
{
	char **nums;
	int i;

	nums = split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = atoi(nums[i]);
		free(nums);
		i++;
	}
	free(nums);
}

void read_file(char *file_name, fdf *data)
{
	int fd;
	char *line;
	int i;
	
	data->height = get_height(file_name);
	data->width = get_width(file_name);

	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data-> height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
