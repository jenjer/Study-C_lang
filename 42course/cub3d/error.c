/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:33:16 by youngski          #+#    #+#             */
/*   Updated: 2023/01/28 17:51:39 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "fcntl.h"

int	print_err(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

int	print_err_free(char *err, t_game *game)
{
	free(game->str_line);
	write(2, err, ft_strlen(err));
	return (1);
}

int	map_type_err(char *argv[])
{
	int	size;

	size = ft_strlen(argv[1]);
	if (!ft_strcmp(&argv[1][size - 4], ".ber") || size < 8)
		return (0);
	return (1);
}

int	error_check(int argc, char *argv[], t_game *game)
{
	if (argc != 2)
		return (print_err("Map is missing.\n"));
	if (!map_type_err(argv))
		return (print_err("Map type is err\n"));
	game->fd = open (argv[1], O_RDONLY);
	if (game->fd <= 0)
		return (print_err("Open_error.\n"));
	if (!map_read(game))
		return (print_err("Map must be rectangular.\n"));
	if (!check_valid_loop(*game))
	{
		free(game->str_line);
		return (print_err("map must be valied\n"));
	}
	return (0);
}

int	map_wall_checking(t_game *game)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(game->str_line))
	{
		if (i < game->wid)
		{
			if (game->str_line[i] != '1')
				return (print_err("Map must be closed/surrounded by walls"));
		}
		else if (i % game->wid == 0 || i % game->wid == game->wid -1)
		{
			if (game->str_line[i] != '1')
				return (print_err("Map must be closed/surrounded by walls"));
		}
		else if (i > (int)ft_strlen(game->str_line) - game->wid)
		{
			if (game->str_line[i] != '1')
				return (print_err("Map must be closed/surrounded by walls"));
		}
		i++;
	}
	return (0);
}
