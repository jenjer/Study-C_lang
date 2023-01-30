/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:51:34 by youngski          #+#    #+#             */
/*   Updated: 2022/11/18 17:08:15 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(const char *str, size_t *i)
{
	int	flag;

	flag = 1;
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v' || \
str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		*i = *i + 1;
	if (str[*i] == '-')
	{
		flag *= -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
		*i = *i + 1;
	return (flag);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		for_return;
	int		flag;

	for_return = 0;
	i = 0;
	flag = start(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		for_return = for_return * 10 + (str[i] - 48);
		i++;
	}
	for_return *= flag;
	return (for_return);
}
