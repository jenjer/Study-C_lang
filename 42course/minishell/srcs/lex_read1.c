/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_read1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:22:29 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/22 14:26:57 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	read_env(char **s, t_str *buf, char **temp)
{
	t_str	*env;
	char	*g_str;
	char	*meta_str;

	env = make_str();
	g_str = ft_itoa(g_exit_code);
	if (see_next_word(s, env, g_str, buf))
		return (1);
	(*s)++;
	while (**s != '\"' && !is_word_end(**s))
	{
		if (**s == '$')
			break ;
		push_str(env, **s);
		(*s)++;
	}
	meta_str = check_meta_chr(&env, 0, 0, 0);
	if (make_env_buf(&buf, &env, temp, meta_str) == 0)
	{
		free(g_str);
		return (0);
	}
	free_meta_str(meta_str, &env, buf);
	free(g_str);
	return (1);
}

int	read_word_quote(char **s, t_str *buf, char **temp)
{
	int	is_fail;

	is_fail = 0;
	if (**s == '\'')
		is_fail |= read_word_squote(s, buf);
	else if (**s == '\"')
		is_fail |= read_word_dquote(s, buf, temp);
	return (is_fail);
}

t_token	*read_word(char **s, t_token *cur, t_str *buf, char **envp)
{
	int		is_fail;
	int		num;
	char	**temp;

	init_fail_and_num(&is_fail, &num);
	while (!is_word_end(**s))
	{
		temp = envp;
		if (**s == '$')
		{
			if (read_env(s, buf, temp) == 0)
			{
				cur = make_nullcur(buf, cur, &envp);
				return (cur);
			}
		}
		else if (**s == '\'' || **s == '\"')
			is_fail = read_word_quote(s, buf, temp);
		else
			push_str(buf, *((*s)++));
	}
	return (make_retcur(buf, cur, is_fail, &envp));
}

t_token	*read_pipe_redir(char **s, t_token *cur, t_str *buf)
{
	if (buf->len != 0)
		cur = push_token(T_WORD, buf, cur);
	push_str(buf, *((*s)++));
	if ((*(*(s)-1) == '<' || *(*(s)-1) == '>') && *(*(s) - 1) == **s)
	{
		push_str(buf, *((*s)++));
		cur = push_token(T_REDIRECT, buf, cur);
	}
	else
	{
		if (*(*(s) - 1) == '|')
			cur = push_token(T_PIPE, buf, cur);
		else
			cur = push_token(T_REDIRECT, buf, cur);
	}
	return (cur);
}
