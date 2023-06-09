/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:33:23 by youngski          #+#    #+#             */
/*   Updated: 2023/05/22 17:13:26 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "cub2d.h"
# include <float.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define BUTTON_X 17

# define GAME_WIDTH 1600
# define GAME_HEIGHT 900

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	all;
}	t_color;

typedef struct s_texture
{
	char		*tex_path;
	int			*texture;
	double		width;
	double		height;
}	t_texture;

typedef struct s_meta_data
{
	t_color			*f_color;
	t_color			*c_color;
	t_texture		*tex;
	int				fd;
	int				height;
	int				max_width;
	int				add_height;
	int				player_x;
	int				player_y;
	char			**map;
	char			**sp_map;
	int				pos1_r;
	int				pos1_c;
	int				dir;
	int				num1;
	int				**visited;
}	t_meta_data;

typedef struct s_param
{
	void	*mlx;
	void	*win;
}	t_param;

typedef struct s_3d
{
	double	fov_angle;
	double	distance_plane;
	int		wall_top_pixel[RAY_COUNT];
	int		wall_bot_pixel[RAY_COUNT];
	int		dir;
	int		img_wid;
	int		img_hwid;
	int		y;
	int		x;
	int		position_hei;
}	t_3d;

typedef struct s_press
{
	t_3d		*info3;
	t_ray_arr	*ray_arr;
	t_img1		*img1;
	t_param		*param;
	t_meta_data	*meta;
	t_map2		*map2;
	t_img2		*img2;
	t_key		*key2;
	t_player2	*player2;
	t_ray2		*ray2;
}	t_press;

//------------------------ functions ---------------------------// 

// init function
int		map_init(t_meta_data *meta, char **tmp_map, int idx, int s_flag);
int		map_direction_init(t_meta_data *meta, int flag, char *line);

// parsing function
int		add_color(t_meta_data *meta, char *tmp, int flag, int i);
int		map_valid_check(t_meta_data *meta, int r, int flag, int first1);
void	check_dup_path(t_meta_data *meta, char *tmp, int flag);

// freeing function
int		map_free_all(t_meta_data meta, int i);
void	free_spl(char **temp);

// utils
int		ft_isnum(char *str);
void	skip_space(char **str);
int		ft_strrncmp(char *s1, char *s2, int n);
int		ft_exit(const char *str);
int		ft_max(int a, int b);
int		ft_compare(int a, int b);
void	deep_copy_space(char *sp_map, char *map, int width);

// casting && ray
int		map_cast(t_param *param, t_meta_data *meta);
void	map_cast_init(t_press *press);
void	param_init(t_press *press);
void	init_player(t_meta_data *meta, t_player2 **player2);
int		check_wall(t_press *press, double x, double y);
int		check_wall_light(t_press *press, double x, double y);
void	cal_distance(t_press *press, t_dp_ray *hv);
void	load_texture(t_press *press);
void	ray_init(t_ray2 *ray2, double ray_angle);
void	ray_arr_init(t_ray_arr *ray_arr);
void	info3_init(t_press *press, int ray_num);
void	cal_vert_ray(t_press *press, t_dp_ray *vert);
void	cal_horz_ray(t_press *press, t_dp_ray *horz);
void	cal_ray(t_press *press, t_dp_ray *hv);
void	normalize_color(t_press *press);
double	normalize_angle(double angle);
void	draw_ray(t_press *press);
void	draw_one_ray(t_press *press, double angle, int ray_num);

//color
int		make_rgb_bit(t_meta_data *meta);
void	draw_base(t_press *press);

//hooking
int		key_press(int keycode, t_press *press);
int		update_player2(t_press *press);

//rendering
void	render_map(t_press *press);
void	fill_squares(t_press *press, int x, int y, int color);
int		draw_player(t_press *press);
void	setting_map_location(t_press *press, int *x, int *y);
void	pixel_render(t_press *press);
int		fix_color(t_press *press);
double	distance_between_points(double x1, double y1, double x2, double y2);
void	render_pixel_row(t_press *press, int idx, int flag);
int		find_position_hei(t_press *press, int i, int y, int dir);

//valid_check
void	do_dfs1(t_meta_data *meta, int r, int c);
int		valid_char_check(char c);
int		map_check_func(t_meta_data *meta, int r, int c);

//direction
int		freeing_line_and_fin(char *line);

//sp_map
void	fill_sp_map(char *sp_map, int idx);
int		is_one_in(t_meta_data *meta, int r, int c);
int		check_cardinal(char dir);
void	call_dfs(t_meta_data *meta);
int		dfs1_start(t_meta_data *meta);
int		check_four_side(t_meta_data *meta, int r, int c);
void	check_alpha(t_meta_data *meta, int *flag, int r, int c);
void	check_wall_sp_map(t_meta_data *meta, int r, int c, int *first1);
int		map_valid_check(t_meta_data *meta, int r, int flag, int first1);

#endif
