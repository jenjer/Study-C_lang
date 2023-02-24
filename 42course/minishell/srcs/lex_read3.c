/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_read3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:31:03 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/20 15:41:37 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	read_word_squote(char **s, t_str *buf)
{
	(*s)++;
	while (!is_line_end(**s) && **s != '\'')
		push_str(buf, *((*s)++));
	if (**s != '\'')
		return (1);
	(*s)++;
	return (0);
}

int	read_word_dquote(char **s, t_str *buf, char **envp)
{
	(*s)++;
	while (!is_line_end(**s) && **s != '\"')
	{
		if (**s == '$')
			read_env(s, buf, envp);
		else
			push_str(buf, *((*s)++));
	}
	if (**s != '\"')
		return (1);
	(*s)++;
	return (0);
}

int	see_next_word(char **s, t_str *env, char *g_str, t_str *buf)
{
	if (see_next_word_null(s, &buf) == 1 \
			|| see_next_word_meta(s, &buf, g_str) == 1)
	{
		free(g_str);
		free_str(env);
		return (1);
	}
	return (0);
}

t_token	*make_nullcur(t_str *buf, t_token *cur, char ***envp)
{
	if (buf->s[0] != '\0')
		cur = push_token(T_WORD, buf, cur);
	else
	{
		buf->null_flag = 1;
		cur = push_token(T_WORD, buf, cur);
	}
	free_spl(*envp);
	return (cur);
}
