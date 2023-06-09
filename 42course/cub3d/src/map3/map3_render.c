/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:22:39 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/22 17:13:35 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	fix_color(t_press *press)
{
	int		color;
	double	x;
	double	y;

	color = 0;
	x = press->ray2->last_x - (int)press->ray2->last_x;
	y = press->ray2->last_y - (int)press->ray2->last_y;
	if (y >= x)
	{	
		if (x + y >= 1)
			color = 0xff00ff;
		else
			color = 0x81F7D8;
	}
	else
	{
		if (x + y >= 1)
			color = 0x00ffff;
		else
			color = 0xA9D0F5;
	}
	return (color);
}

void	find_dir(t_press *press, int i)
{
	int	color;

	color = press->ray_arr->colors[i];
	if (color == 0)
		color = press->ray_arr->colors[i - 1];
	if (color == 0xff00ff)
		press->info3->dir = 0;
	else if (color == 0xA9D0F5)
		press->info3->dir = 1;
	else if (color == 0x81F7D8)
		press->info3->dir = 2;
	else if (color == 0x00ffff)
		press->info3->dir = 3;
}

int	count_wall_func(t_press *press, int temp_x, int temp_y)
{
	double	*x;
	double	*y;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	x = press->ray_arr->ray_x;
	y = press->ray_arr->ray_y;
	while (x[i])
	{
		if (temp_x != (int)x[i] || temp_y != (int)y[i])
			ret++;
		temp_x = (int)x[i];
		temp_y = (int)y[i];
		i++;
	}
	return (ret);
}

void	find_wid(t_press *press, int *flag, int num)
{
	if (press->info3->dir == 0 || press->info3->dir == 1)
	{
		*flag = 1;
		press->info3->img_wid = press->meta->tex[press->info3->dir].width * \
				(press->ray_arr->ray_x[num] - (int)press->ray_arr->ray_x[num]);
	}
	else
	{
		*flag = 0;
		press->info3->img_hwid = press->meta->tex[press->info3->dir].width * \
				(press->ray_arr->ray_y[num] - (int)press->ray_arr->ray_y[num]);
	}
}

void	pixel_render(t_press *press)
{
	int	idx;
	int	flag;

	idx = 0;
	while (idx < RAY_COUNT)
	{
		find_dir(press, idx);
		find_wid(press, &flag, idx);
		if (press->info3->wall_top_pixel[idx] < -9000)
			press->info3->wall_top_pixel[idx] = -9000;
		if (press->info3->wall_bot_pixel[idx] > 9000)
			press->info3->wall_bot_pixel[idx] = 9000;
		render_pixel_row(press, idx, flag);
		idx++;
	}
}
