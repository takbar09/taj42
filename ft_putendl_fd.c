
#include "libft.h"

/*
** [PROTOTYPE]
** void	ft_putendl_fd(char *s, int fd);
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*
**int	main(void)
**{
**	printf("====ft_putendl_fd====\n");
**	ft_putendl_fd("42Seoul", 1);
**	return (0);
**}
*/