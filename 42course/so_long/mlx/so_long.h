/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:08:07 by youngski          #+#    #+#             */
/*   Updated: 2023/01/26 12:55:01 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC	53
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2

# include "mlx.h"
# include <stdlib.h>

typedef struct s_param{
	int		x;
	int		y;
}				t_param;


typedef struct s_img{
	void	*star;
	void	*wall;
	void	*treasure;
	void	*man;
	void	*ending;
}			t_img;



typedef struct s_game{
	int		fd;
	void	*win;
	void	*mlx;
	int		hei;
	int		wid;
	char	*str_line;
	int		col_cnt;
	int		all_col;
	int		walk_cnt;
	t_img	img;
}				t_game;

void	param_init(t_param *param);
int		key_press(int keycode, t_param *param);
int		error_check(int argc, char *argv[], t_game *game);
int		map_read(t_game *game);
void	setting_img(t_game *game, int hei, int wid);
void	set_img_path(t_game *game);
int		print_err(char *err);
void	clear_game(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);
void	working_mlx(t_game *game);
int		press_key(int key_code, t_game *game);
int		map_wall_checking(t_game *game);
int		map_dfs(t_game game, char *map, int i);
char	**make_visited(t_game game, char **visitied);
int		check_valid_loop(t_game game);


#endif
