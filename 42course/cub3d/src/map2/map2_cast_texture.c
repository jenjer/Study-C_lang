/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_cast_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:42:35 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/19 16:59:27 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	draw_base(t_press *press)
{
	int	y;
	int	x;

	y = 0;
	while (y < GAME_HEIGHT / 2)
	{
		x = 0;
		while (x < GAME_WIDTH)
		{
			press->img2->data[GAME_WIDTH * y + x] = press->meta->c_color->all;
			x++;
		}
		y++;
	}
	while (y < GAME_HEIGHT)
	{
		x = 0;
		while (x < GAME_WIDTH)
		{
			press->img2->data[GAME_WIDTH * y + x] = press->meta->f_color->all;
			x++;
		}
		y++;
	}
}

static int	*load_image_malloc(t_press *press, char *path, t_img1 *img1, int i)
{
	int		col;
	int		row;
	int		*result;

	img1->ptr = mlx_xpm_file_to_image(press->param->mlx, path, \
						&(img1->img_width), &(img1->img_height));
	if (!(img1->ptr))
		ft_exit("wrong texture\n");
	press->meta->tex[i].width = img1->img_width;
	press->meta->tex[i].height = img1->img_height;
	img1->data = (int *)mlx_get_data_addr(img1->ptr, \
			&img1->bpp, &img1->line_size, &img1->endian);
	result = (int *)malloc(sizeof(int) * (img1->img_width * img1->img_height));
	row = -1;
	while (++row < img1->img_height)
	{
		col = -1;
		while (++col < img1->img_width)
		{
			result[img1->img_width * row + col] = \
					img1->data[img1->img_width * row + col];
		}
	}
	mlx_destroy_image(press->param->mlx, img1->ptr);
	return (result);
}

void	load_texture(t_press *press)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		press->meta->tex[i].texture = load_image_malloc(press, \
			press->meta->tex[i].tex_path, press->img1, i);
	}
}
