/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 14:25:41 by takbar        #+#    #+#                 */
/*   Updated: 2022/11/06 13:34:05 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
int ft_count_word(char const *s, char c)
{
	int i;
	int cnt;
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
		i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
			i++;
		}
	}
	return (cnt);
}
char *ft_word_make(char *word, char const *s, int k, int word_len)
{
	int i;
	i = 0;
	while (word_len >0)
	word[i++] = s[k - word_len--];
	word [i] = '\0';
	return (word);
}
char **ft_split2(char **res, char const *s, char c, int num_word)
{
	int i;
	int k;
	int word_len;

	i = 0;
	k = 0;
	word_len = 0;
	while (s[k] && i < num_word)
	{
		while (s[k] && s[k] == c)
		k++;
		while (s[k] && s[k] != c)
		{
			k++;
			word_len++;
		}
		if (!(res[i] = (char *)malloc(sizeof(char) * (word_len + 1))))
		return (NULL);
		ft_word_make(res[i], s, k, word_len);
		word_len = 0;
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	int num_word;
	char **res;

	if (s == 0)
	return (NULL);
	num_word = ft_count_word(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (num_word + 1))))
	return (NULL);
	ft_split2(res, s, c, num_word);
	return (res);
}

int main(void)
{
	printf ("===ft_split===\n");
	char **a = ft_split("codam_student_taj",'_');
	for(int i=0; i<3; i++)
	printf("%s\n",a[i]);
	return (0);
}