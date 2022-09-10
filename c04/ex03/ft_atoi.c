/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:51:34 by youngski          #+#    #+#             */
/*   Updated: 2022/09/05 14:43:02 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);
int	start(char *str, int *i);

int	start(char *str, int *i)
{
	int	flag;

	flag = 1;
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v' || \
str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		*i = *i + 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			flag *= -1;
		*i = *i + 1;
	}	
	return (flag);
}

int	ft_atoi(char *str)
{
	int	i;
	int	for_return;
	int	flag;

	for_return = 0;
	i = 0;
	flag = start(str, &i);
	while (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		for_return = for_return * 10 + (str[i] - 48);
		i++;
	}
	return (flag * for_return);
}
