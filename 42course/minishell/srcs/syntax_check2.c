/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:48:45 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/22 14:28:55 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	syntax_err(void)
{
	ft_putendl_fd("syntax error", 2);
	g_exit_code = 258;
	return (-1);
}

int	rule_redirection(int *type_arr, int len)
{
	int		i;

	if ((len == 1 && type_arr[0] == T_REDIRECT)
		|| type_arr[len - 1] == T_REDIRECT)
		return (-1);
	i = -1;
	if (len > 1)
		while (++i < len - 1)
			if (type_arr[i] == T_REDIRECT && type_arr[i + 1] != T_WORD)
				return (-1);
	return (0);
}

int	rule_pipe(int *type_arr, int len)
{
	int		i;

	if (type_arr[0] == T_PIPE || type_arr[len - 1] == T_PIPE)
		return (-1);
	i = 0;
	if (len > 2)
		while (++i < len - 1)
			if ((type_arr[i] == T_PIPE)
				&& (type_arr[i - 1] != T_WORD || type_arr[i + 1] == T_PIPE))
				return (-1);
	return (0);
}

int	rule_error(int *type_arr, int len)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		if (type_arr[i] == T_ERROR)
			return (-1);
	}
	return (0);
}

int	get_cmds_num(int *type_arr, int token_len)
{
	int		i;
	int		cmds_num;

	i = -1;
	cmds_num = 1;
	while (++i < token_len)
		if (type_arr[i] == T_PIPE)
			cmds_num++;
	return (cmds_num);
}
