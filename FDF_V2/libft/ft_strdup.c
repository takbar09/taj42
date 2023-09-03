/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 21:11:14 by takbar        #+#    #+#                 */
/*   Updated: 2022/12/09 17:24:38 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1) + 1;
	new = (char *) malloc (sizeof(*new) * len);
	if (!new)
		return (NULL);
	return ((char *)ft_memcpy(new, s1, len));
}
/*int main(void)
{
	printf("%s\n", ft_strdup("42Codam"));
	printf("%s\n", strdup("42Codam"));
}*/
