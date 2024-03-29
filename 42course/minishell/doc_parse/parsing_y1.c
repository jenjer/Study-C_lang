/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_y1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:15:04 by youngski          #+#    #+#             */
/*   Updated: 2023/02/20 15:28:03 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_inside_char(char my_char, char *t, int *flag, int *i)
{
	if (my_char == '\"')
		*t = '\'';
	else
		*t = '\"';
	*flag = 0;
	(*i)++;
}

void	inside_char_plus(int *i, int *count)
{
	(*i)++;
	(*count)++;
}

void	count_inside_char(int *i, int *count, char *line_temp, char my_char)
{
	int		flag;
	char	t;

	init_inside_char(my_char, &t, &flag, i);
	while (line_temp && line_temp[*i])
	{
		if (line_temp[*i + 1] != ' ' && line_temp[*i] == my_char)
		{
			if (line_temp[*i + 1] == t && flag == 1)
			{
				count_inside_char(i, count, line_temp, t);
				flag = 0;
			}
			else if (flag == 0)
				flag = 1;
			inside_char_plus(i, count);
		}
		if (line_temp[*i] != my_char)
			inside_char_plus(i, count);
		else
		{
			(*i)++;
			return ;
		}
	}
}

int	make_inside_char_double(char *line_temp, char *ret, int *j)
{
	int	count;

	while (ret && *ret)
		ret++;
	count = 1;
	ret[0] = *line_temp;
	ret[1] = 0;
	line_temp++;
	while (*line_temp)
	{
		if (*line_temp == '\"')
		{
			if (count == 0)
				(*j)++;
			ret[count++] = *line_temp;
			ret[count] = 0;
			line_temp++;
			return (count);
		}
		ret[count] = *line_temp;
		ret[count + 1] = 0;
		line_temp++;
		count++;
	}
	return (count);
}

int	make_inside_char_single(char *line_temp, char *ret, int *j)
{
	int	count;

	count = 1;
	while (*ret)
		ret++;
	ret[0] = *line_temp;
	ret[1] = 0;
	line_temp++;
	while (*line_temp)
	{
		if (*line_temp == '\'')
		{
			if (count == 0)
				(*j)++;
			ret[count++] = *line_temp;
			ret[count] = 0;
			line_temp++;
			return (count);
		}
		ret[count] = *line_temp;
		ret[count + 1] = 0;
		line_temp++;
		count++;
	}
	return (count);
}
