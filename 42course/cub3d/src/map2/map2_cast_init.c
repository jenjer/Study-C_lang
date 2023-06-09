/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_cast_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:51:09 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/20 22:05:44 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	param_init(t_press *press)
{
	press->param->mlx = mlx_init();
	press->param->win = mlx_new_window(press->param->mlx, \
			GAME_WIDTH, GAME_HEIGHT, "mini");
	press->img2->img = mlx_new_image(press->param->mlx, \
			GAME_WIDTH, GAME_HEIGHT);
}

double	draw_cardinal(int dir)
{
	if (dir == 1)
		return (PI / 2);
	else if (dir == 2)
		return (PI * (1.5));
	else if (dir == 3)
		return (0);
	else if (dir == 4)
		return (PI);
	else
		return (-1);
}

void	init_player(t_meta_data *meta, t_player2 **player2)
{
	(*player2)->x = (meta->player_x + 0.5);
	(*player2)->y = (meta->player_y + 0.5);
	(*player2)->thickness = 2;
	(*player2)->rotation_angle = draw_cardinal(meta->dir);
	(*player2)->walkspeed = 0.2;
	(*player2)->turnspeed = 4 * (PI / 180);
	(*player2)->turn_direction = 0;
	(*player2)->walk_direction = 0;
}

void	init_map2(t_map2 *map2, t_meta_data *meta)
{
	map2->mts = 0;
	map2->map_rows = meta->height + 2;
	map2->map_cols = meta->max_width + 2;
	map2->m_dir = LU;
	map2->scale = 0.5;
}

void	map_cast_init(t_press *press)
{
	press->img1 = (t_img1 *)malloc(sizeof(t_img1));
	ft_memset(press->img1, 0, sizeof(t_img1));
	press->img2 = (t_img2 *)malloc(sizeof(t_img2));
	ft_memset(press->img2, 0, sizeof(t_img2));
	press->map2 = (t_map2 *)malloc(sizeof(t_map2));
	init_map2(press->map2, press->meta);
	press->key2 = (t_key *)malloc(sizeof(t_key));
	ft_memset(press->key2, 0, sizeof(t_key));
	press->player2 = (t_player2 *)malloc(sizeof(t_player2));
	init_player(press->meta, &(press->player2));
	press->ray2 = (t_ray2 *)malloc(sizeof(t_ray2));
}
