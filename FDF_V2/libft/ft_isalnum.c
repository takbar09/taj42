/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:00:58 by takbar        #+#    #+#                 */
/*   Updated: 2022/12/09 17:17:11 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)

{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*int main()

{
	printf("%d", ft_isalnum("ab123f"));
	printf("%d", ft_isalnum("abcdef"));
	printf("%d", ft_isalnum(""));

			return (0);
}*/
