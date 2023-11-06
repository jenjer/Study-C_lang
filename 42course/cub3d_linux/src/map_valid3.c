/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:46:20 by youngski          #+#    #+#             */
/*   Updated: 2023/05/19 16:50:42 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	is_one_in(t_meta_data *meta, int r, int c)
{
	while (meta->sp_map[++r])
	{
		c = -1;
		while (meta->sp_map[r][++c])
		{
			if (meta->sp_map[r][c] == '1' && meta->visited[r][c] == 0)
			{
				if (check_four_side(meta, r, c))
					return (1);
			}
		}
	}
	return (0);
}

int	check_cardinal(char dir)
{
	if (dir == 'N')
		return (1);
	else if (dir == 'S')
		return (2);
	else if (dir == 'W')
		return (3);
	else if (dir == 'E')
		return (4);
	else
		return (-1);
}

void	call_dfs(t_meta_data *meta)
{
	dfs1_start(meta);
	if (meta->num1 != 0)
	{
		if (is_one_in(meta, -1, -1))
			ft_exit("dfs error\n");
	}
}
