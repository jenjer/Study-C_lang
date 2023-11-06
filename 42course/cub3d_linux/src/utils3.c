/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:28:49 by youngski          #+#    #+#             */
/*   Updated: 2023/05/17 21:50:51 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	ft_exit(const char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
	return (1);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_compare(int a, int b)
{
	if (ft_max(a, b) == a)
		return (1);
	return (0);
}

void	deep_copy_space(char *sp_map, char *map, int width)
{
	int		i;
	int		idx;

	idx = 0;
	i = 0;
	while (++i < width + 1)
	{
		if (map[idx] == '\n' || map[idx] == '\0')
			break ;
		if (map[idx] != ' ')
			sp_map[i] = map[idx];
		idx++;
	}
}
