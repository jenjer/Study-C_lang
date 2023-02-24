/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tokenize2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:33:41 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/20 15:32:34 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_word_end(char s)
{
	if (s == '|' || s == ' ' || s == '\n' || s == 0)
		return (1);
	return (0);
}

int	is_line_end(char s)
{
	if (s == '\n' || s == '\0')
		return (1);
	return (0);
}

t_token	*copy_token(t_token *cur)
{
	t_token	*temp;

	temp = make_token();
	temp->cmds = cur->cmds;
	temp->null_flag = cur->null_flag;
	temp->next = cur->next;
	temp->prev = cur->prev;
	temp->str = ft_strdup(cur->str);
	temp->type = cur->type;
	return (temp);
}

void	get_rid_null_node(t_token **cur)
{
	t_token	*tmp;
	t_token	*nxt;

	tmp = (*cur);
	nxt = NULL;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->next->null_flag == 1)
			{
				nxt = tmp->next;
				tmp->next = nxt->next;
				tmp = tmp->next;
				free(nxt->str);
				free(nxt);
				nxt = NULL;
			}
			else
				tmp = tmp->next;
		}
		else
			break ;
	}
}
