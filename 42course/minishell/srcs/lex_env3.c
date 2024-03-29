/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_env3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:06:26 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/20 15:36:41 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*make_meta_chr(char *ret, int *size, char meta_chr)
{
	int		i;
	char	*temp_ret;

	i = -1;
	temp_ret = ret;
	ret = (char *)malloc(sizeof(char) * ++(*size));
	ret[(*size) - 1] = '\0';
	while (temp_ret[++i])
		ret[i] = temp_ret[i];
	ret[i] = meta_chr;
	return (ret);
}

void	free_meta_str(char *meta_str, t_str **env, t_str *buf)
{
	int	i;

	i = -1;
	if (meta_str)
		while (meta_str[++i])
			push_str(buf, meta_str[i]);
	if (meta_str)
	{
		free(meta_str);
		meta_str = 0;
	}
	if (env && *env && (*env)->s)
	{
		free_str(*env);
		*env = 0;
	}
}

char	*check_meta_chr(t_str **env, int i, int len, int size)
{
	char	*tmp_str;
	char	*ret;
	char	*str;
	int		idx;

	str = NULL;
	ret = NULL;
	tmp_str = (*env)->s;
	if (is_all_non_meta(tmp_str) == 1)
		return (NULL);
	len = ft_strlen((*env)->s);
	while ((*env)->s[i])
		if (is_meta_chr((*env)->s[i++]) != 1)
			if (is_meta_chr((*env)->s[i]) == 1)
				break ;
	size = len - i;
	str = make_non_meta(env, str, i);
	ret = make_meta(env, ret, size, i);
	clear_str(*env);
	idx = -1;
	while (++idx < i)
		push_str(*env, str[idx]);
	free(str);
	return (ret);
}

int	see_next_word_meta(char **s, t_str **buf, char *g_str)
{
	if (*((*s) + 1) != '\0' && is_meta_chr(*((*s) + 1)) == 1)
	{
		if (*((*s) + 1) == '?')
			return (is_g_exit_code(s, buf, g_str, -1));
		else if (*((*s) + 1) == '\'' || *((*s) + 1) == '\"')
			return (next_word_quote(s, buf));
		else
			push_2str(buf, s);
		if (**s == '\0')
			return (1);
		while (**s)
		{
			if (**s == '\0' || **s == '$' || **s == '\'' || **s == '\"')
				return (1);
			push_str(*buf, (**s));
			(*s)++;
		}
		return (1);
	}
	return (0);
}
