/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:51:28 by youngski          #+#    #+#             */
/*   Updated: 2023/01/26 15:41:09 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	clear_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img.star);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.treasure);
	mlx_destroy_image(game->mlx, game->img.man);
	free(game->str_line);
	exit(0);
}

int	find_p(t_game game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game.str_line))
	{
		if (game.str_line[i] == 'P')
			break ;
	}
	return (i);
}

int	map_dfs(t_game game, char *map, int i)
{
	int	count;

	count = 0;
	if (i >= (int)ft_strlen(game.str_line))
		return (0);
	if (map[i] == '1')
		return (0);
	if (map[i] == 'E')
	{
		map[i] = 'V';
		return (1);
	}
	if (map[i] != 'V')
	{
		if (map[i] == 'C')
			count += 1;
		map[i] = 'V';
		count += map_dfs(game, map, i + 1);
		count += map_dfs(game, map, i - 1);
		count += map_dfs(game, map, i + game.wid);
		count += map_dfs(game, map, i - game.wid);
		return (count);
	}
	return (0);
}

int	check_valid_loop(t_game game)
{
	int		i;
	char	*map;

	i = find_p(game);
	map = (char *)malloc(sizeof(char) * ft_strlen(game.str_line));
	if (!map)
		print_err("map_malloc_error");
	ft_memcpy(map, game.str_line, ft_strlen(game.str_line));
	if (map_dfs(game, map, i) == game.all_col + 1)
	{
		free(map);
		return (1);
	}
	free(map);
	return (0);
}
