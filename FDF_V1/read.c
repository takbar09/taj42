/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:07:14 by takbar            #+#    #+#             */
/*   Updated: 2023/07/30 19:02:19 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fdf.h"
#include "get_next_line.h"

static  char    **ft_mem_free(char **res)
{
    int i;

    i = 0;
    while (res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
    return (NULL);
}

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

static  char    *ft_word_make(char *word, char const *s, int k, int word_len)
{
    int i;

    i = 0;
    while (word_len > 0)
    {
        word[i] = s[k - word_len];
        i++;
        word_len--;
    }
    word [i] = '\0';
    return (word);
}

static  char    **ft_split2(char **res, char const *s, char c, int num_word)
{
    int i;
    int k;
    int word_len;

    i = 0;
    k = 0;
    word_len = 0;
    while (s[k] && i < num_word)
    {
        while (s[k] && s[k] == c)
            k++;
        while (s[k] && s[k] != c)
        {
            k++;
            word_len++;
        }
        res[i] = (char *) malloc(sizeof(char) * (word_len + 1));
        if (!(res[i]))
            return (NULL);
        ft_word_make(res[i], s, k, word_len);
        word_len = 0;
        i++;
    }
    res[i] = 0;
    return (res);
}

char    **ft_split(const char *s, char c)
{
    int     num_word;
    char    **res;

    if (s == 0)
        return (NULL);
    num_word = ft_count_word(s, c);
    res = (char **) malloc(sizeof(char *) * (num_word + 1));
    if (!(res))
        return (NULL);
    if (!ft_split2(res, s, c, num_word))
    {
        ft_mem_free(res);
        return (NULL);
    }
    return (res);
}

int	get_height(char *filename)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}
//counts the number of co-ords in each line
int count_words(char *str, char c)
{
    int i;

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

// parses line to find value of each point
int	*parse_line(char *line, t_data *data)
{
	int		*row;
	char	**words;
	int		i;

	words = ft_split(line, ' ');
	row = malloc(sizeof(int) * data->width);
	//if (!row || !words)
	//{
	//	printf("ft_split or malloc failed in parse_line");
	//}
	i = -1;
	while (++i < data->width)
	{
		row[i] = atoi(words[i]);
		if (row[i] > data->max)
			data->max = row[i];
		if (row[i] < data->min)
			data->min = row[i];
	}
	ft_mem_free(words);
	return (row);
}
// returns a map struct with array storing X-Y-Z values from file
t_data	*parse_map(t_data *data, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data->height = get_height(filename);
    printf("data->height = %d\n", data->height);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		printf("Cannot read from file in parse_map");
	line = get_next_line(fd);
	data->width = count_words(line, ' ');
	printf("data->width = %d\n", data->width);
	data->z_matrix = malloc(sizeof(int *) * data->height);
	if (!data->z_matrix)
		printf("Allocation failed in parse_map");
	while (line != NULL)
	{
		data->z_matrix[i] = parse_line(line, data);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (data);
}
