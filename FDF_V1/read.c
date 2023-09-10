/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takbar <takbar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:07:14 by takbar            #+#    #+#             */
/*   Updated: 2023/09/09 17:38:35 by takbar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include "get_next_line.h"
//#include "libft/libft.h"

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

char    **ft_split(const char *s, char c){
    int     num_word;
    char    **res;

    if (s == 0)
        return (NULL);
    num_word = ft_count_word(s, c);
    res = (char **) malloc(sizeof(char *) * (num_word + 1));
    if (!(res))
        return (NULL);
    if (!ft_split2(res, s, c, num_word)){
        ft_mem_free(res);
        return (NULL);
    }
    return (res);
}

int	get_max_y(char *filename){
	int		y;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL){
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
	return (y);
}
//counts the number of co-ords in each line
int count_words(char *str, char c){
    int i;

    i = 0;
    if (!str || *str == '\0')
        return (0);
    while (*str){
        if (*str != c){
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
t_point	*parse_line(char *line, t_data *data, int y){
	t_point		*row;
	char	**words;
    char	**comma_sep_words;
	int		i;
    
	words = ft_split(line, ' ');
	row = malloc(sizeof(t_point) * data->max_x);
	i = -1;
	while (++i < data->max_x){
        row[i].x = i;
        row[i].y = y;
        row[i].color = 0;
        //printf("Words  %s  count words=%d\n", words[i], count_words(words[i], ','));
        if (count_words(words[i], ',') > 1){
            comma_sep_words = ft_split(words[i], ',');
            row[i].z = atoi(comma_sep_words[0]);
            row[i].color = strtol(comma_sep_words[1], NULL, 16);
            ft_mem_free(comma_sep_words);
        }
        else
            row[i].z = atoi(words[i]);
        //printf("Read point x=%d, y=%d, z=%d, color=0x%x\n", row[i].x, row[i].y, row[i].z, row[i].color);
	}
	ft_mem_free(words);
	return (row);
}

int get_max_x(char *filename){
    char	*line;
	int		fd;
    int max_x;
	
    fd = open(filename, O_RDONLY);
	if (fd < 0){
        printf("Cannot read from file in parse_map");
        return (-1);
    }
	line = get_next_line(fd);
	max_x = count_words(line, ' ');
    close(fd);
    return (max_x);
}

int read_points(t_data *data, char *filename){
    char	*line;
	int		fd;
	int i;

    fd = open(filename, O_RDONLY);
	if (fd < 0)
        return (-1);

	line = get_next_line(fd);
    data->p_matrix = malloc(sizeof(t_point *) * data->max_y);
	if (!data->p_matrix)
		return (-1);
    i = 0;
	while (line != NULL){
		data->p_matrix[i] = parse_line(line, data, i);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
    return (0);
}

// returns a map struct with array storing X-Y-Z values from file
void parse_map(t_data *data, char *filename){
	data->max_y = get_max_y(filename);
    data->max_x = get_max_x(filename);

    printf("max_y = %d,  max_x=%d\n", data->max_y, data->max_x);
    read_points(data, filename);
    write(1, "Sucess", 6);
	return;
}
