/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:42:38 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/22 17:21:00 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	erase_key(t_press *press)
{
	press->key2->up = 0;
	press->key2->down = 0;
	press->key2->left = 0;
	press->key2->right = 0;
	press->key2->turn_left = 0;
	press->key2->turn_right = 0;
}

void	reset_image(t_press *press)
{
	mlx_destroy_image(press->param->mlx, press->img2->img);
	press->img2->img = mlx_new_image(press->param->mlx, \
				GAME_WIDTH, GAME_HEIGHT);
	press->img2->data = (int *)mlx_get_data_addr(press->img2->img, \
						&(press->img2->bpp), &(press->img2->line_size), \
							&(press->img2->endian));
	mlx_clear_window(press->param->mlx, press->param->win);
}

int	key_press(int keycode, t_press *press)
{
	if (keycode == KEY_LEFT)
		press->key2->turn_left = 1;
	if (keycode == KEY_RIGHT)
		press->key2->turn_right = 1;
	if (keycode == KEY_W)
		press->key2->up = 1;
	if (keycode == KEY_S)
		press->key2->down = 1;
	if (keycode == KEY_A)
		press->key2->left = 1;
	if (keycode == KEY_D)
		press->key2->right = 1;
	if (keycode == KEY_ESC)
		exit(1);
	update_player2(press);
	reset_image(press);
	draw_base(press);
	render_map(press);
	draw_player(press);
	draw_ray(press);
	erase_key(press);
	return (0);
}
