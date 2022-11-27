#include "libft.h"

/*
** [PROTOTYPE]
** void ft_putstr_fd(char *s, int fd);
*/

void		ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/*
**int	main(void)
**{
**	printf("====ft_putstr_fd====\n");
**	ft_putstr_fd("42Seoul", 1);
**	printf("\n");
**	ft_putstr_fd("Cadet", -1);
**	return (0);
**}
*/