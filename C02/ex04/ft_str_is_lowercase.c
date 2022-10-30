/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_lowercase.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 20:26:25 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/26 14:04:22 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_lowercase(char *str)

{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a') && (str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
