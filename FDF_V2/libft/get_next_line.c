/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 16:15:47 by takbar        #+#    #+#                 */
/*   Updated: 2023/08/05 19:10:46 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

char	*ft_remove_read_line(char	*read_file_str)
{
	char	*str;
	char	*start;

	start = ft_strchr_gnl(read_file_str, '\n');
	if (!start)
		return (NULL);
	start++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(start) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, start);
	return (str);
}

char	*ft_read_line(char *read_file_str)
{
	size_t	i;
	char	*line;

	if (!read_file_str || !read_file_str[0])
		return (NULL);
	i = 0;
	while (read_file_str[i])
	{
		if (read_file_str[i] == '\n')
		{
			i++;
			break ;
		}	
		i++;
	}
	line = ft_substr(read_file_str, 0, (i));
	return (line);
}

char	*file_read(int fd, char	*read_file_str)
{
	char		*buffer;
	char		*temp;
	int			byte_count;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(read_file_str), NULL);
	while (!ft_strchr_gnl(read_file_str, '\n'))
	{
		byte_count = read(fd, buffer, BUFFER_SIZE);
		if (byte_count == 0)
			break ;
		if (byte_count == -1)
		{
			free(buffer);
			free(read_file_str);
			return (NULL);
		}
		buffer[byte_count] = '\0';
		temp = read_file_str;
		read_file_str = ft_strjoin(read_file_str, buffer);
		free(temp);
	}
	return (free(buffer), read_file_str);
}

char	*get_next_line(int fd)
{
	static char	*read_file_str;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(read_file_str), NULL);
	if (!read_file_str)
	{
		read_file_str = (char *)malloc(sizeof(char) * 1);
		if (!read_file_str)
			return (free(read_file_str), NULL);
		read_file_str[0] = '\0';
	}
	read_file_str = file_read(fd, read_file_str);
	line = ft_read_line(read_file_str);
	if (!line)
	{
		free(read_file_str);
		read_file_str = NULL;
	}
	temp = read_file_str;
	read_file_str = ft_remove_read_line(read_file_str);
	return (free(temp), line);
}
/*
 * void drawLine(int x, int y) {
    int i, j;

    for (i = 0; i < y; i++) {
        for (j = 0; j < x; j++) {
            printf("*");
        }
        printf("\n");
    }
}
int	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	#include <fcntl.h>
    int fp;
    char * line = NULL;
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    fp = open(argv[1], O_RDONLY);
    if (!fp)
        return(-1);
	while (1)
	{
		line = get_next_line(fp);
		if (line)
		{
			ft_putstr(line);
		}
		else
			return (0);
		free(line); 
	}
    close(fp);
	return(0);
}*/
