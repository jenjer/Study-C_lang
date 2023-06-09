/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_ray_cal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:20:14 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/22 17:19:54 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	check_wall_light(t_press *press, double x, double y)
{
	int	ix;
	int	iy;

	if (x < 0 || x > press->meta->max_width || y < 0 || y > press->meta->height)
		return (1);
	ix = floor(x);
	iy = floor(y);
	return (press->meta->sp_map[iy][ix] != '0');
}

void	cal_distance(t_press *press, t_dp_ray *hv)
{
	if (hv->found_wallhit == 1)
	{
		hv->distance = distance_between_points(press->player2->x, \
		press->player2->y, hv->wall_hitx, hv->wall_hity);
	}
	else
		hv->distance = DBL_MAX;
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	cal_vert_ray(t_press *press, t_dp_ray *vert)
{
	vert->found_wallhit = 0;
	vert->wall_hitx = 0;
	vert->wall_hity = 0;
	vert->xintercept = \
		floor(press->player2->x / press->map2->mts) * (press->map2->mts);
	if (press->ray2->is_ray_facingright)
		vert->xintercept += press->map2->mts;
	vert->yintercept = press->player2->y + \
		(vert->xintercept - press->player2->x) * tan(press->ray2->ray_angle);
	vert->xstep = press->map2->mts;
	if (press->ray2->is_ray_facingleft)
		vert->xstep *= -1;
	vert->ystep = press->map2->mts * tan(press->ray2->ray_angle);
	if (press->ray2->is_ray_facingup && vert->ystep > 0)
		vert->ystep *= -1;
	if (press->ray2->is_ray_facingdown && vert->ystep < 0)
		vert->ystep *= -1;
	cal_ray(press, vert);
}

void	cal_horz_ray(t_press *press, t_dp_ray *horz)
{
	horz->found_wallhit = 0;
	horz->wall_hitx = 0;
	horz->wall_hity = 0;
	horz->yintercept = \
		floor(press->player2->y / press->map2->mts) * (press->map2->mts);
	if (press->ray2->is_ray_facingdown)
		horz->yintercept += press->map2->mts;
	horz->xintercept = press->player2->x + \
		(horz->yintercept - press->player2->y) / tan(press->ray2->ray_angle);
	horz->ystep = press->map2->mts;
	if (press->ray2->is_ray_facingup)
		horz->ystep *= -1;
	horz->xstep = press->map2->mts / tan(press->ray2->ray_angle);
	if (press->ray2->is_ray_facingleft && horz->xstep > 0)
		horz->xstep *= -1;
	if (press->ray2->is_ray_facingright && horz->xstep < 0)
		horz->xstep *= -1;
	cal_ray(press, horz);
}
