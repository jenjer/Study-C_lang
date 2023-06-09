/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:45:15 by youngski          #+#    #+#             */
/*   Updated: 2023/05/19 16:45:53 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	map_check_func(t_meta_data *meta, int r, int c)
{
	static int	dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	static int	dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int			nr;
	int			nc;
	int			i;

	i = -1;
	while (++i < 8)
	{
		nr = r + dr[i];
		nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= meta->height + 2
			|| nc >= meta->max_width + 2)
			continue ;
		else if (meta->sp_map[nr][nc] != '1' && meta->sp_map[nr][nc] != 'X')
			return (1);
	}
	return (0);
}

int	valid_char_check(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'E' || c == 'S'
		|| c == 'W' || c == 'X');
}

void	do_dfs1(t_meta_data *meta, int r, int c)
{
	const int	dr[4] = {0, 0, -1, 1};
	const int	dc[4] = {-1, 1, 0, 0};
	int			nr;
	int			nc;
	int			i;

	meta->visited[r][c] = 1;
	if (meta->sp_map[r][c] == '1')
		meta->num1--;
	i = -1;
	while (++i < 4)
	{
		nr = r + dr[i];
		nc = c + dc[i];
		if (meta->visited[nr][nc] == 0 && meta->sp_map[nr][nc] == '1')
			do_dfs1(meta, nr, nc);
	}
}
