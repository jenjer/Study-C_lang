/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:55:34 by youngski          #+#    #+#             */
/*   Updated: 2022/09/12 03:55:42 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, char *charset);
int		count(char *str, char *charset);
int		check(char *str, char c);
char	*pick_word(char *str, char *charset, int *i);

char	*pick_word(char *str, char *charset, int *i)
{
	char	*ret;
	int		k;
	int		u;

	k = *i;
	u = 0;
	while (str[k] && !check(charset, str[k]))
	{
		k++;
	}
	ret = (char *)malloc(sizeof(char) * (k - *i) + 1);
	while (str[*i] && !check(charset, str[*i]))
	{
		ret[u] = str[*i];
		*i = *i + 1;
		u++;
	}
	ret[u] = '\0';
	return (ret);
}

int	check(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != '\0' && check(charset, str[i]))
			i++;
		if (!check(charset, str[i]))
			count++;
		while (str[i] != '\0' && !check(charset, str[i]))
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;
	int		k;

	i = 0;
	k = 0;
	ret = (char **)malloc(sizeof(char *) * count(str, charset) + 1);
	while (str[i])
	{
		while (str[i] != '\0' && check(charset, str[i]))
			i++;
		if (str[i] != '\0' && !check(charset, str[i]))
		{
			ret[k] = pick_word(str, charset, &i);
			k++;
		}
	}
	ret[k] = (NULL);
	return (ret);
}
