/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:57:00 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/20 15:34:01 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_rules(int *type_arr, int len)
{
	if (rule_pipe(type_arr, len) == -1
		|| rule_redirection(type_arr, len) == -1
		|| rule_error(type_arr, len) == -1)
		return (-1);
	free(type_arr);
	return (0);
}

int	*make_type_arr(t_token *head, int *token_len)
{
	t_token	*temp;
	int		idx;
	int		*type_arr;

	temp = head->next;
	while (temp)
	{
		(*token_len)++;
		temp = temp->next;
	}
	idx = -1;
	temp = head->next;
	type_arr = (int *) malloc(sizeof(int) * (*token_len));
	while (++idx < *token_len)
	{
		type_arr[idx] = temp->type;
		temp = temp->next;
	}
	return (type_arr);
}

int	check_ambiguous_node(t_token *temp, int *type_arr)
{
	while (temp)
	{
		if (temp->type == T_REDIRECT && (ft_strncmp(temp->str, "<<", 2)))
		{
			if (temp->next->null_flag == 1)
			{
				printf(" : ambiguous redirect\n");
				free(type_arr);
				g_exit_code = 1;
				return (1);
			}
		}
		temp = temp->next;
	}
	return (0);
}

int	check_syntax(t_token *head)
{
	int		token_len;
	int		*type_arr;
	t_token	*temp;

	token_len = 0;
	type_arr = make_type_arr(head, &token_len);
	temp = head;
	while (temp)
	{
		temp->cmds = get_cmds_num(type_arr, token_len);
		temp = temp->next;
	}
	temp = head->next;
	if (temp->cmds == 1)
		if (check_ambiguous_node(temp, type_arr) == 1)
			return (-1);
	if (check_rules(type_arr, token_len) == -1)
	{
		free(type_arr);
		return (syntax_err());
	}
	return (0);
}
