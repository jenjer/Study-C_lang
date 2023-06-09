/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:35:05 by youngski          #+#    #+#             */
/*   Updated: 2023/05/22 17:06:44 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	init_meta_data(char *name, t_meta_data *meta)
{
	int		i;

	i = 0;
	meta->fd = open(name, O_RDONLY);
	if (meta->fd <= 0)
		ft_exit("File open error!\n");
	meta->player_x = -1;
	meta->player_y = -1;
	meta->tex = (t_texture *)malloc(sizeof(t_texture) * 4);
	if (!meta->tex)
		ft_exit("Texture allocation failed!\n");
	while (i < 4)
	{
		meta->tex[i].tex_path = NULL;
		meta->tex[i].texture = NULL;
		meta->tex->width = 0.0;
		meta->tex->height = 0.0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_meta_data	meta;
	t_param		param;

	if (argc != 2 || ft_strrncmp(argv[1], ".cub", 4))
		return (ft_exit("Invalid Argument\n"));
	ft_memset(&meta, 0, sizeof(t_meta_data));
	ft_memset(&param, 0, sizeof(t_param));
	init_meta_data(argv[1], &meta);
	map_direction_init(&meta, 0, NULL);
	map_init(&meta, NULL, 0, 0);
	map_valid_check(&meta, -1, 0, 0);
	make_rgb_bit(&meta);
	map_cast(&param, &meta);
	return (map_free_all(meta, 0));
}
