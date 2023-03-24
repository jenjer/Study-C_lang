/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:35:03 by youngski          #+#    #+#             */
/*   Updated: 2023/01/26 14:18:19 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "so_long.h"
#include "fcntl.h"

char	*ft_strdup_without_newline(char *str)
{
	int		len;
	char	*ret;
	int		i;

	i = 0;
	len = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * len - 1);
	ret[len - 1] = 0;
	while (i < len - 1)
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	return (ret);
}

void	gnl_make_map_loop(t_game *game, char *line)
{
	int	size;

	size = (int)ft_strlen(line) - 1;
	while (line)
	{
		game->hei++;
		line = get_next_line(game->fd);
		if (!line)
			return ;
		line = ft_strdup_without_newline(line);
		if (size != (int)ft_strlen(line))
		{
			free(line);
			free(game->str_line);
			exit(print_err("map error\n"));
		}
		game->str_line = ft_strjoin(game->str_line, line);
		if (!(game->str_line))
		{
			free(line);
			exit(1);
		}
		free(line);
	}
}

void	count_c_p_e(t_game *game)
{
	int	i;
	int	c;
	int	p;
	int	e;

	i = -1;
	c = 0;
	p = 0;
	e = 0;
	while (++i < (int)ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'C')
			c++;
		else if (game->str_line[i] == 'P')
			p++;
		else if (game->str_line[i] == 'E')
			e++;
	}
	if (p != 1)
		exit (print_err("P map_error"));
	if (e != 1)
		exit (print_err("E map_error"));
	if (c < 1)
		exit (print_err("C map_error"));
	game->all_col = c;
}

int	map_read(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	if (!line)
		return (0);
	game->hei = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup_without_newline(line);
	if (!(game->str_line) || ft_strlen(game->str_line) < 3)
	{
		free(game->str_line);
		exit(print_err("check_map\n"));
	}
	gnl_make_map_loop(game, line);
	count_c_p_e(game);
	if (map_wall_checking(game))
	{
		print_err("Map_checking\n");
		free(game->str_line);
		exit(1);
	}
	return (1);
}

void	setting_img(t_game *game, int hei, int wid)
{
	while (++hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			if (game->str_line[hei * game->wid + wid] == '1')
				mlx_put_image_to_window
					(game->mlx, game->win, game->img.star, wid * 64, hei * 64);
			else if (game->str_line[hei * game->wid + wid] == 'P')
				mlx_put_image_to_window
					(game->mlx, game->win, game->img.man, wid * 64, hei * 64);
			else if (game->str_line[hei * game->wid + wid] == 'C')
				mlx_put_image_to_window
				(game->mlx, game->win, game->img.treasure, wid * 64, hei * 64);
			else if (game->str_line[hei * game->wid + wid] == 'E')
				mlx_put_image_to_window
				(game->mlx, game->win, game->img.ending, wid * 64, hei * 64);
			else if (game->str_line[hei * game->wid + wid] == '0')
				mlx_put_image_to_window
					(game->mlx, game->win, game->img.wall, wid * 64, hei * 64);
			else
				exit(print_err("map_error check other char\n"));
			wid++;
		}
	}
}
