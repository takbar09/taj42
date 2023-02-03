#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_remove_read_line(char	*read_file_str)
{
	char	*str;
	char 	*start;
	
	start = ft_strchr(read_file_str, '\n');
	if (!start)
		return (NULL);

	start++;
	str = (char *)malloc(sizeof(char)* (ft_strlen(start)+1));
	if (!str)
		return (NULL);
	
 	ft_strcpy(str, start);
	return (str);
}

char	*ft_read_line(char *read_file_str)
{
	size_t		i;
	char	*line;
	if (!read_file_str || !read_file_str[0])
		return (NULL);
 
	// length till '\n'
	i = 0;
	while (read_file_str[i])
	{
		if (read_file_str[i] == '\n')
		{
			i++;
			break;
		}	
		i++;
	}

	// sub str till '\n'
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
		return (NULL);
	while (!ft_strchr(read_file_str, '\n'))
	{
		byte_count = read(fd, buffer, BUFFER_SIZE);
		if (byte_count == -1 || byte_count == 0)
			break; 
		buffer[byte_count] = '\0';
		temp = read_file_str;
		read_file_str = ft_strjoin(read_file_str, buffer);
		free(temp);
	}
	free(buffer);
	if (byte_count == -1)
		return (NULL);
	return (read_file_str);
}

char	*get_next_line(int fd)
{
	static char	*read_file_str;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);        

	if (!read_file_str)
	{
		read_file_str = (char *)malloc(sizeof(char)*1);
		if (!read_file_str)
			return (NULL);	
		read_file_str[0] = '\0';
	}
	read_file_str = file_read(fd, read_file_str);
	line = ft_read_line(read_file_str);
	temp = read_file_str;
	read_file_str = ft_remove_read_line(read_file_str);
	free(temp);
	return (line);
}

int main(void)
{
	#include <fcntl.h>
    int fp;
    char * line = NULL;
    fp = open("test.txt", O_RDONLY);
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
		{
			return (0);
		}
		free(line); 
	}

    close(fp);
	return(0);
}