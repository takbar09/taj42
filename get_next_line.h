#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
#include <io.h>

int	    ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
int	    ft_putstr(char *str);
char	*ft_read_line(char *read_file_str);
char	*ft_remove_read_line(char	*read_file_str);
char	*file_read(int fd, char	*read_file_str);

#endif