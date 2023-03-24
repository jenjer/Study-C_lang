/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_interupt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:20:31 by youngski          #+#    #+#             */
/*   Updated: 2023/01/26 14:13:04 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	move_w(t_game *g)
{
	int	i;

	i = -1;
	while (++i < (int)ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - g->wid] == 'C')
		g->col_cnt++;
	if (g->str_line[i - g->wid] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i - g->wid] != '1' && g->str_line[i - g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->wid] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g, -1, 0);
	}
}

void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - 1] == 'C')
		g->col_cnt++;
	if (g->str_line[i - 1] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - 1] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g, -1, 0);
	}
}

void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + g->wid] == 'C')
		g->col_cnt++;
	if (g->str_line[i + g->wid] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i + g->wid] != '1' && g->str_line[i + g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + g->wid] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g, -1, 0);
	}
}

void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + 1] == 'C')
		g->col_cnt++;
	if (g->str_line[i + 1] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + 1] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g, -1, 0);
	}
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		clear_game(game);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}
