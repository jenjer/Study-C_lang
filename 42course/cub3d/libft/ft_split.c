/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:59:49 by youngski          #+#    #+#             */
/*   Updated: 2023/03/25 12:55:50 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counting_word(char const *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			ret++;
		while (*s && *s != c)
			s++;
	}
	return (ret);
}

static char	*cpy_string(char *s, char c)
{
	char	*ret;
	size_t	len;

	len = 0;
	ret = 0;
	while (s[len] && s[len] != c)
		len++;
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}

static char	**inserting(char **ret, size_t count_word, char *s, char c)
{
	size_t	i;

	i = 0;
	while (i < count_word)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			ret[i] = cpy_string(s, c);
			if (!ret[i])
			{
				while (i > 0)
					free(ret[--i]);
				free(ret);
				return (NULL);
			}
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_split(char *s, char c)
{
	char	**ret;
	size_t	count_word;

	count_word = counting_word(s, c);
	ret = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (!ret)
		return (0);
	return (inserting(ret, count_word, s, c));
}
