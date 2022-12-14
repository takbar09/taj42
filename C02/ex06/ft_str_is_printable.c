/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_printable.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 14:13:15 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/28 17:56:11 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)

{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32) && (str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}
