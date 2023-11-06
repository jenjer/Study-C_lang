/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:22:39 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/20 21:58:08 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	find_position_hei(t_press *press, int i, int y, int dir)
{
	double	range;
	int		position;
	int		top;
	int		bot;

	top = press->info3->wall_top_pixel[i];
	bot = press->info3->wall_bot_pixel[i];
	if (bot < 0)
		bot = 0;
	if (top > GAME_HEIGHT)
		top = GAME_HEIGHT;
	range = bot - top;
	position = (int)((press->meta->tex[dir].height) * ((y / range)));
	return (position);
}

void	render_pixel_row_flag1(t_press *press, \
			int idx, int y, int position_hei)
{
	if (GAME_WIDTH * y + \
			(press->info3->x + idx * (GAME_WIDTH / RAY_COUNT)) < \
				GAME_WIDTH * GAME_HEIGHT)
	{
		if (press->img2->data[GAME_WIDTH * y + \
				(press->info3->x + idx * (GAME_WIDTH / RAY_COUNT))] \
					== press->meta->c_color->all || \
			press->img2->data[(GAME_WIDTH * y + \
			(press->info3->x + idx * (GAME_WIDTH / RAY_COUNT)))] == \
				press->meta->f_color->all)
		{
			press->img2->data[(GAME_WIDTH * y + \
			(press->info3->x + idx * (GAME_WIDTH / RAY_COUNT)))] = \
				press->meta->tex[press->info3->dir].texture[\
				(((int)press->info3->img_wid + \
				(int)(press->meta->tex[press->info3->dir].width) * \
					position_hei))];
		}
	}
}

void	render_pixel_row_flag0(t_press *press, \
			int idx, int y, int position_hei)
{
	if (GAME_WIDTH * y + \
			(press->info3->x + idx * (GAME_WIDTH / RAY_COUNT)) < \
				GAME_WIDTH * GAME_HEIGHT)
	{
		if (press->img2->data[(GAME_WIDTH * y + \
				(press->info3->x + idx * (GAME_WIDTH / RAY_COUNT)))] == \
					press->meta->c_color->all || \
			press->img2->data[(GAME_WIDTH * y + \
				(press->info3->x + idx * (GAME_WIDTH / RAY_COUNT)))] == \
					press->meta->f_color->all)
		{
			press->img2->data[(GAME_WIDTH * y + \
				(press->info3->x + idx * (GAME_WIDTH / RAY_COUNT)))] = \
				press->meta->tex[press->info3->dir].texture[\
					(((int)press->info3->img_hwid + \
					(int)(press->meta->tex[press->info3->dir].width) * \
						position_hei))];
		}
	}
}

void	render_pixel_row_loop(t_press *press, int idx, int flag)
{
	int	y;
	int	position_hei;

	y = press->info3->y;
	press->info3->x = 0;
	position_hei = press->info3->position_hei;
	while (press->info3->x < (GAME_WIDTH / RAY_COUNT))
	{
		if ((GAME_WIDTH * y + (press->info3->x + idx * \
			(GAME_WIDTH / RAY_COUNT))) < 0 || (GAME_WIDTH * y + \
				(press->info3->x + idx * (GAME_WIDTH / RAY_COUNT))) > \
					GAME_WIDTH * GAME_HEIGHT)
		{
			press->info3->x++;
			continue ;
		}
		if (flag == 1)
			render_pixel_row_flag1(press, idx, y, position_hei);
		else
			render_pixel_row_flag0(press, idx, y, position_hei);
		press->info3->x++;
	}
}

void	render_pixel_row(t_press *press, int idx, int flag)
{
	int	hei_index;

	hei_index = 0;
	press->info3->y = press->info3->wall_top_pixel[idx];
	while (press->info3->y < press->info3->wall_bot_pixel[idx])
	{
		press->info3->position_hei = \
			find_position_hei(press, idx, hei_index, press->info3->dir);
		render_pixel_row_loop(press, idx, flag);
		press->info3->y++;
		hei_index++;
	}
}
