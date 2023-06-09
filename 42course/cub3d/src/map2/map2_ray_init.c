/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_ray_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:20:14 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/22 17:19:50 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

double	normalize_angle(double angle)
{
	if (angle >= 0)
		while (angle >= 2 * PI)
			angle -= 2 * PI;
	else
		while (angle <= 0)
			angle += 2 * PI;
	return (angle);
}

void	normalize_color(t_press *press)
{
	int	ray_num;
	int	offset;

	ray_num = 1;
	offset = 1;
	while (offset <= 2)
	{
		while (ray_num < RAY_COUNT - offset)
		{
			if (press->ray_arr->colors[ray_num] != \
				press->ray_arr->colors[ray_num - offset] && \
				press->ray_arr->colors[ray_num] != \
				press->ray_arr->colors[ray_num + offset])
				press->ray_arr->colors[ray_num] = \
					press->ray_arr->colors[ray_num - 1];
			ray_num++;
		}
		offset++;
		ray_num = offset + 1;
	}
}

void	info3_init(t_press *press, int ray_num)
{
	static t_3d	info3;
	double		corr_dis;
	double		wall_height;
	double		cal_height;

	ft_memset(&info3, 0, sizeof(t_3d));
	info3.fov_angle = 60 * (PI / 180.0);
	info3.distance_plane = \
			((GAME_WIDTH / 2) / tan(info3.fov_angle / 2));
	while (ray_num < RAY_COUNT)
	{
		corr_dis = press->ray_arr->distances[ray_num] * \
				cos(press->ray_arr->ray_angles[ray_num] - \
						press->player2->rotation_angle);
		wall_height = ((press->map2->mts / corr_dis) * \
				(info3.distance_plane)) / 14;
		cal_height = wall_height;
		info3.wall_top_pixel[ray_num] = (GAME_HEIGHT / 2) - (cal_height / 2);
		info3.wall_bot_pixel[ray_num] = (GAME_HEIGHT / 2) + (cal_height / 2);
		info3.wall_top_pixel[0] = info3.wall_top_pixel[1];
		info3.wall_bot_pixel[0] = info3.wall_bot_pixel[1];
		ray_num++;
	}
	press->info3 = &info3;
}

void	ray_init(t_ray2 *ray2, double ray_angle)
{
	ray2->ray_angle = normalize_angle(ray_angle);
	ray2->wall_hit_x = 0;
	ray2->wall_hit_y = 0;
	ray2->distance = 0;
	ray2->was_hit_vertical = 0;
	ray2->is_ray_facingup = (ray2->ray_angle > 0 && ray2->ray_angle < PI);
	ray2->is_ray_facingdown = !ray2->is_ray_facingup;
	ray2->is_ray_facingleft = (ray2->ray_angle < 0.5 * PI || \
									ray2->ray_angle > 1.5 * PI);
	ray2->is_ray_facingright = !ray2->is_ray_facingleft;
	ray2->max_value = 0;
	ray2->dx = 0;
	ray2->dy = 0;
}
