/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_y2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:22:14 by youngski          #+#    #+#             */
/*   Updated: 2023/02/20 15:28:27 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	temp_count_plus_word(char **line_temp, int *count)
{
	(*line_temp)++;
	(*count)++;
}

int	count_space(char *line)
{
	int	len;
	int	cnt;
	int	i;

	len = ft_strlen(line);
	i = -1;
	cnt = 0;
	while (++i < len - 1)
	{
		if (line[i] == ' ' || line[i] == '<' || line[i] == '>'
			|| line[i] == '|')
		{
			if (line[i + 1] == '<' || line[i + 1] == '>')
				i++;
			cnt++;
			i++;
		}
		while (line[i] == ' ')
		{
			i++;
			cnt++;
		}
	}
	return (cnt + 2);
}

void	init_pure_word(int *sm_flag, int *du_flag)
{
	*sm_flag = 0;
	*du_flag = 0;
}

void	adding_pure_word(char *ret, char **line_temp, int *count)
{
	ret[*count] = **line_temp;
	(*line_temp)++;
	ret[(*count) + 1] = 0;
	(*count)++;
}

int	make_pure_word(char *line_temp, char *ret)
{
	int	sm_flag;
	int	du_flag;
	int	count;

	count = 0;
	init_pure_word(&sm_flag, &du_flag);
	while (ret && *ret)
		ret++;
	while (line_temp && *line_temp)
	{
		if (*line_temp == '<')
		{
			if (*line_temp == '<')
				adding_pure_word(ret, &line_temp, &count);
			adding_pure_word(ret, &line_temp, &count);
			return (count);
		}
		if (*line_temp && *line_temp != ' ' && *line_temp != '\''
			&& *line_temp != '\"')
			adding_pure_word(ret, &line_temp, &count);
		else
			return (count);
	}
	return (count);
}
