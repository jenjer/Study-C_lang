/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:04:38 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/22 17:16:39 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	check_wall(t_press *press, double x, double y)
{
	int	ix;
	int	iy;
	int	tx;
	int	ty;

	ix = floor(x + 0.1);
	iy = floor(y + 0.1);
	tx = floor(x - 0.1);
	ty = floor(y - 0.1);
	if (press->meta->sp_map[(int)floor(y)][(int)floor(x)] == '1' \
			|| press->meta->sp_map[(int)floor(y)][(int)floor(x)] == 'X' ||
				press->meta->sp_map[iy][ix] == '1' || \
					press->meta->sp_map[iy][ix] == 'X' || \
						press->meta->sp_map[ty][tx] == '1' || \
							press->meta->sp_map[ty][tx] == 'X')
		return (1);
	return (0);
}

void	update_player_lr(t_press *press, double *nx, double *ny, double step)
{
	if (press->key2->left == 1)
	{
		*nx = press->player2->x + step \
				* sin(press->player2->rotation_angle);
		*ny = press->player2->y - step \
				* cos(press->player2->rotation_angle);
	}
	else if (press->key2->right == 1)
	{
		*nx = press->player2->x + step \
				* sin(press->player2->rotation_angle);
		*ny = press->player2->y - step \
				* cos(press->player2->rotation_angle);
	}
}

void	update_player_slide(t_press *press, double move_step)
{
	double	slide_step;
	double	slide_x;
	double	slide_y;

	slide_step = move_step;
	if (press->key2->up == 1 || press->key2->down == 1)
	{
		slide_x = press->player2->x + \
						slide_step * cos(press->player2->rotation_angle);
		slide_y = press->player2->y + \
						slide_step * sin(press->player2->rotation_angle);
		if (!check_wall(press, slide_x, press->player2->y))
			press->player2->x = slide_x;
		else if (!check_wall(press, press->player2->x, slide_y))
			press->player2->y = slide_y;
	}
}

void	set_direction(t_press *press)
{
	if (press->key2->up == 1)
		press->player2->walk_direction = -1;
	if (press->key2->down == 1)
		press->player2->walk_direction = 1;
	if (press->key2->turn_left == 1)
		press->player2->turn_direction = -1;
	if (press->key2->turn_right == 1)
		press->player2->turn_direction = 1;
	if (press->key2->left == 1)
		press->player2->walk_direction = -1;
	if (press->key2->right == 1)
		press->player2->walk_direction = 1;
	press->player2->rotation_angle += \
			press->player2->turn_direction * (press->player2->turnspeed);
}

int	update_player2(t_press *press)
{
	double	nx;
	double	ny;
	double	move_step;

	press->player2->turn_direction = 0;
	press->player2->walk_direction = 0;
	set_direction(press);
	move_step = press->player2->walk_direction * (press->player2->walkspeed);
	nx = press->player2->x + move_step * cos(press->player2->rotation_angle);
	ny = press->player2->y + move_step * sin(press->player2->rotation_angle);
	if (press->key2->left == 1 || press->key2->right == 1)
		update_player_lr(press, &nx, &ny, move_step);
	if (!check_wall(press, nx, ny))
	{
		press->player2->x = nx;
		press->player2->y = ny;
	}
	else
		update_player_slide(press, move_step);
	return (0);
}
