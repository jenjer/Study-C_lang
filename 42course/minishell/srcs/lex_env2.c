/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:17:30 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/20 15:30:38 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_meta_chr(char c)
{
	if (c == '!' || c == '#' || c == '%' || c == '&' || c == '*' || c == '+' \
			|| c == ',' || c == '-' || c == '.' || c == ':' || c == '$' \
				|| c == '=' || c == '?' || c == '@' || c == '[' || c == ']' \
					|| c == '^' || c == '{' || c == '}' || c == '~' \
						|| c == '<' || c == '>' || c == '|' || c == ';' \
							|| c == '\"' || c == '\'')
		return (1);
	return (0);
}

char	*flip_meta_chr(char *ret)
{
	int		len;
	int		r_len;
	int		i;
	char	*temp;

	i = -1;
	len = ft_strlen(ret);
	r_len = len;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	temp[len] = '\0';
	while (++i < len)
	{
		temp[i] = ret[--r_len];
	}
	free(ret);
	return (temp);
}

int	is_all_non_meta(char *tmp_str)
{
	while (*tmp_str)
	{
		if (is_meta_chr(*tmp_str) == 1)
			break ;
		tmp_str++;
		if (*tmp_str == '\0')
			return (1);
	}
	return (0);
}

char	*make_non_meta(t_str **env, char *str, int i)
{
	int	idx;

	idx = -1;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	idx = -1;
	while (++idx < i)
		str[idx] = (*env)->s[idx];
	return (str);
}

char	*make_meta(t_str **env, char *ret, int size, int i)
{
	int	idx;

	idx = -1;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	while (++idx < size)
		ret[idx] = (*env)->s[i++];
	return (ret);
}
