/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_ray_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:20:14 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/22 17:20:52 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	ray_loop(t_press *press, double *ray_x, double *ray_y)
{
	while (1)
	{
		if (!check_wall_light(press, *ray_x, *ray_y))
		{
			press->img2->data[(GAME_WIDTH * \
				(int)((*ray_y) * (press->map2->mts))) + \
				(int)((*ray_x) * (press->map2->mts))] = 0xff0000;
		}
		else
		{
			press->ray2->last_x = *ray_x;
			press->ray2->last_y = *ray_y;
			break ;
		}
		*ray_y += (press->ray2->dy / press->map2->mts) / 160;
		*ray_x += (press->ray2->dx / press->map2->mts) / 160;
	}
}

void	draw_line(t_press *press, double player_x, double player_y)
{
	double	ray_x;
	double	ray_y;

	ray_x = player_x;
	ray_y = player_y;
	press->ray2->dx = (press->ray2->wall_hit_x - player_x);
	press->ray2->dy = (press->ray2->wall_hit_y - player_y);
	press->ray2->max_value = fmax(fabs(press->ray2->dx), fabs(press->ray2->dy));
	press->ray2->dx /= press->ray2->max_value;
	press->ray2->dy /= press->ray2->max_value;
	ray_loop(press, &ray_x, &ray_y);
	press->ray2->distance = \
			distance_between_points(player_x, player_y, ray_x, ray_y);
}

void	cal_ray(t_press *press, t_dp_ray *hv)
{
	double	next_touch_x;
	double	next_touch_y;

	next_touch_x = hv->xintercept;
	next_touch_y = hv->yintercept;
	while (next_touch_x >= 0 && next_touch_x <= GAME_WIDTH && \
				next_touch_y >= 0 && next_touch_y <= GAME_HEIGHT)
	{
		if (check_wall_light(press, next_touch_x, next_touch_y))
		{
			hv->found_wallhit = 1;
			hv->wall_hitx = next_touch_x;
			hv->wall_hity = next_touch_y;
			break ;
		}
		else
		{
		next_touch_x += hv->xstep;
		next_touch_y += hv->ystep;
		}
	}
	cal_distance(press, hv);
}

void	draw_one_ray(t_press *press, double angle, int ray_num)
{
	t_dp_ray	horz;
	t_dp_ray	vert;

	ray_init(press->ray2, angle);
	cal_horz_ray(press, &horz);
	cal_vert_ray(press, &vert);
	if (vert.distance < horz.distance)
	{
		press->ray2->wall_hit_x = vert.wall_hitx;
		press->ray2->wall_hit_y = vert.wall_hity;
		press->ray2->was_hit_vertical = 1;
	}
	else
	{
		press->ray2->wall_hit_x = horz.wall_hitx;
		press->ray2->wall_hit_y = horz.wall_hity;
		press->ray2->was_hit_vertical = 0;
	}
	draw_line(press, press->player2->x, press->player2->y);
	press->ray_arr->distances[ray_num] = press->ray2->distance;
	press->ray_arr->ray_angles[ray_num] = press->ray2->ray_angle;
	press->ray_arr->ray_x[ray_num] = press->ray2->last_x;
	press->ray_arr->ray_y[ray_num] = press->ray2->last_y;
	press->ray_arr->colors[ray_num] = fix_color(press);
	press->ray_arr->colors[0] = press->ray_arr->colors[1];
}

void	draw_ray(t_press *press)
{
	double				angle;
	double				ray_range;
	int					i;
	static t_ray_arr	ray_arr_;

	i = 1;
	ray_range = PI / 3.0;
	angle = press->player2->rotation_angle;
	ft_memset(&ray_arr_, 0, sizeof(t_ray_arr));
	press->ray_arr = &ray_arr_;
	while (i < RAY_COUNT)
	{
		draw_one_ray(press, angle - (ray_range / 2.0), i);
		angle += ray_range / RAY_COUNT;
		i++;
	}
	info3_init(press, 1);
	normalize_color(press);
	pixel_render(press);
	mlx_put_image_to_window(press->param->mlx, \
			press->param->win, press->img2->img, 0, 0);
}
