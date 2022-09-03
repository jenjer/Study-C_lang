/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:51:34 by youngski          #+#    #+#             */
/*   Updated: 2022/09/01 22:55:05 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);
unsigned int	*start(char *str, unsigned int *flag);

unsigned int	start(char *str, unsigned int *i)
{
	unsigned int flag;
	i = 0;
	flag = 0;
	while (str[i] != ' ')	
		i++;
	while (str[i] != '-' && str[i] != '+')
	{
		if(str[i] == '-')
			flag++;
		i++;
	}	
	return flag;
}

int ft_atoi(char *str)
{
	unsigned int i;
	int index;
	int for_return;
	int count_loop;

	i = 0;
	flag[0] = 0;
	count_loop = 0;
	flag = start(str, flag);
	index = flag[2];
	while (str[index] < '0' || str[index] > '9')
		index++;
	while (str[index] > '0' && str[index] < '9')
	{
		for_return = for_return * 10 + str[index];
		index++;
		count_loop++;
	}
	return (for_return);
}
