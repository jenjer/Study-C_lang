/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:06:29 by youngski          #+#    #+#             */
/*   Updated: 2023/01/28 17:26:54 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "fcntl.h"

void	set_img_path(t_game *game)
{
	int		img_width;
	int		img_height;
	t_img	*i;

	img_width = 64;
	img_height = 64;
	working_mlx(game);
	i = &(game->img);
	i->wall = mlx_xpm_file_to_image
		(game->mlx, "./images/wall.xpm", &img_width, &img_height);
	i->star = mlx_xpm_file_to_image
		(game->mlx, "./images/star.xpm", &img_width, &img_height);
	i->man = mlx_xpm_file_to_image
		(game->mlx, "./images/man.xpm", &img_width, &img_height);
	i->treasure = mlx_xpm_file_to_image
		(game->mlx, "./images/treasure.xpm", &img_width, &img_height);
	i->ending = mlx_xpm_file_to_image
		(game->mlx, "./images/ending.xpm", &img_width, &img_height);
}

void	working_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, \
			game->wid * 64, game->hei * 64, "so_long");
}

void	init_game_struct(t_game *game)
{
	game->hei = 0;
	game->wid = 0;
	game->col_cnt = 0;
	game->all_col = 0;
	game->walk_cnt = 0;
}

int	click_x_button(t_game *game)
{
	clear_game(game);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	init_game_struct(&game);
	if ((error_check(argc, argv, &game)))
		return (1);
	set_img_path(&game);
	setting_img(&game, -1, 0);
	mlx_key_hook(game.win, &press_key, &game);
	mlx_hook(game.win, 17, 0, &click_x_button, &game);
	mlx_loop(game.mlx);
	free(game.str_line);
}
