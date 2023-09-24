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

int check_line(char *line, t_data *data)
{
	int i;
    char	**words;
    char	**comma_sep_words;
    int z;

    if (count_words(line, ' ') != data->max_x)
        return (-1);
    words = ft_split(line, ' ');
	i = -1;
	while (++i < data->max_x){
        if (count_words(words[i], ',') > 1){
            comma_sep_words = ft_split(words[i], ',');
            z = atoi(comma_sep_words[0]);
	        ft_mem_free(comma_sep_words);
        }
        else
            z = atoi(words[i]);
        if (z < -100){
	        ft_mem_free(words);
            return(-1);
        }
	}
	ft_mem_free(words);
	return (0);    
}

int check_cmd_line_args(int argc, char **argv)
{
	int len;

	len = 0;
	if (argc != 2)
		return (-1);
	#include <string.h>
	len = strlen(argv[1]);
	if (len<4)
		return (-1);
	if(argv[1][len-1] != 'f')
		return (-1);
	if(argv[1][len-2] != 'd')
		return (-1);
	if(argv[1][len-3] != 'f')
		return (-1);
	if(argv[1][len-4] != '.')
		return (-1);
	return(0);
}
