/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:42:35 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/22 17:20:57 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	fill_squares(t_press *press, int x, int y, int color)
{
	int	i;
	int	j;
	int	mts;

	mts = press->map2->mts;
	j = 0;
	while (j < mts)
	{
		i = 0;
		while (i < mts)
		{
			press->img2->data[(int)(GAME_WIDTH * (y + j)) + (x + i)] = color;
			i++;
		}
		j++;
	}
}

void	fill_map(t_press *press, int row, int col)
{
	int	mts;

	mts = press->map2->mts;
	if (press->meta->sp_map[row][col] == '1')
		fill_squares(press, (int)(mts * col), \
						(int)(mts * row), 0x848484);
	else if (press->meta->sp_map[row][col] == 'X')
		fill_squares(press, (int)(mts * col), \
						(int)(mts * row), press->meta->c_color->all);
	else if (press->meta->sp_map[row][col] == '0')
		fill_squares(press, (int)(mts * col), \
						(int)(mts * row), 0xffffff);
}

void	render_map(t_press *press)
{
	int	col;
	int	row;

	if (ft_compare(press->map2->map_rows, press->map2->map_cols))
		press->map2->mts = 400 / press->map2->map_rows;
	else
		press->map2->mts = 600 / press->map2->map_cols;
	row = 0;
	while (row < press->map2->map_rows)
	{
		col = 0;
		while (col < press->map2->map_cols)
		{
			fill_map(press, row, col);
			col++;
		}
		row++;
	}
}

int	draw_player(t_press *press)
{
	int	row;
	int	col;
	int	mts;

	mts = press->map2->mts;
	row = 0;
	while (row <= (press->player2->thickness) / 2)
	{
		col = 0;
		while (col <= (press->player2->thickness) / 2)
		{
			press->img2->data[(int)(GAME_WIDTH * \
				((int)((press->player2->y) * mts + row))) \
					+ ((int)((press->player2->x) * mts + col))] = 0x0000FF;
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(press->param->mlx, \
				press->param->win, press->img2->img, 0, 0);
	return (0);
}

int	map_cast(t_param *param_, t_meta_data *meta_)
{	
	t_press		*press;

	press = (t_press *)malloc(sizeof(t_press));
	ft_memset(press, 0, sizeof(t_press));
	press->param = param_;
	press->meta = meta_;
	map_cast_init(press);
	param_init(press);
	press->img2->data = (int *)mlx_get_data_addr(press->img2->img, \
		&(press->img2->bpp), &(press->img2->line_size), \
			&((press->img2->endian)));
	draw_base(press);
	load_texture(press);
	render_map(press);
	draw_player(press);
	draw_ray(press);
	mlx_hook(press->param->win, X_EVENT_KEY_PRESS, 1L << 0, key_press, press);
	mlx_loop(press->param->mlx);
	return (0);
}
