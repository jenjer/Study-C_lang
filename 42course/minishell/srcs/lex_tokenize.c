/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tokenize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:14:14 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/20 15:32:35 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**deep_copy_env(char **envp)
{
	int		i;
	int		j;
	char	**cp_envp;

	i = -1;
	j = 0;
	while (envp[++i])
		;
	cp_envp = (char **)malloc(sizeof(char *) * (i + 1));
	while (j < i)
	{
		cp_envp[j] = ft_strdup(envp[j]);
		j++;
	}
	cp_envp[j] = NULL;
	return (cp_envp);
}

void	free_spl(char **temp)
{
	int	i;

	i = 0;
	while (temp && temp[i])
	{
		free(temp[i]);
		temp[i] = NULL;
		if (temp[i + 1] == NULL)
			break ;
		i++;
	}
	free(temp);
	temp = NULL;
}

t_token	*tokenize(char *s, char **envp)
{
	t_token	*cur;
	t_str	*buf;
	char	**temp;

	cur = make_token();
	buf = make_str();
	while (*s != '\n' && *s)
	{
		if (*s == '<' || *s == '>' || *s == '|')
			cur = read_pipe_redir(&s, cur, buf);
		else if (is_char_space(*s))
			s++;
		else
		{
			temp = deep_copy_env(envp);
			cur = read_word(&s, cur, buf, temp);
		}
	}
	free_str(buf);
	while (cur->prev)
		cur = cur->prev;
	return (cur);
}

t_token	*go_tokenize(char *cmd, char **envp, t_token **t)
{
	if (*t)
		free_token(*t);
	*t = NULL;
	*t = tokenize(cmd, envp);
	return (*t);
}
