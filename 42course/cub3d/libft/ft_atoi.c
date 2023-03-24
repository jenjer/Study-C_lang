/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:51:34 by youngski          #+#    #+#             */
/*   Updated: 2022/12/30 23:58:01 by youngski         ###   ########.fr       */
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

long	ft_atoi(const char *str)
{
	size_t	i;
	long	for_return;
	int		flag;
	int		checker;

	checker = 0;
	for_return = 0;
	i = 0;
	flag = start(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		for_return = for_return * 10 + (str[i] - 48);
		i++;
		checker = 1;
	}
	for_return *= flag;
	if (checker == 0 || str[i] != 0 || for_return > 2147483647)
		return (21474836999);
	if (for_return < -2147483648)
		return (21474836999);
	return (for_return);
}
