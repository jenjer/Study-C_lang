/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:35:05 by youngski          #+#    #+#             */
/*   Updated: 2023/05/22 17:03:31 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	make_sp_map(t_meta_data *meta)
{
	int		i;
	int		idx;
	char	**temp_sp_map;

	i = -1;
	temp_sp_map = meta->sp_map;
	meta->sp_map = (char **)malloc(sizeof(char *) * (meta->height + 3));
	meta->sp_map[meta->height + 2] = 0;
	while (++i < meta->height + 2)
	{
		meta->sp_map[i] = (char *)malloc(sizeof(char) * meta->max_width + 3);
		fill_sp_map(meta->sp_map[i], meta->max_width + 3);
	}
	i = 0;
	idx = 0;
	while (++i < meta->height + 1)
		deep_copy_space(meta->sp_map[i], meta->map[idx++], meta->max_width);
	if (temp_sp_map)
		free(temp_sp_map);
}

void	map_init_util(t_meta_data *meta)
{
	char	*line;

	while (1)
	{
		line = get_next_line(meta->fd);
		if (!line)
			break ;
		if (ft_strlen(line) > 1 || line[0] != '\n')
			ft_exit("Word after feed error!\n");
	}
	if (!meta->map)
		ft_exit("No map information!\n");
}

void	height_plus_free(t_meta_data *meta, char *line)
{
	meta->height++;
	free(line);
}

int	map_init_sub(t_meta_data *meta, char *line, int *s_flag)
{
	if (!line)
		return (0);
	if (*s_flag == 0 && line[0] == '\n')
		(*s_flag) = 1;
	if (*s_flag == 1 && line[0] == '\n')
	{
		free(line);
		return (1);
	}
	if (*s_flag == 1 && line[0] != '\n')
		(*s_flag)++;
	if (line[0] == '\n')
	{
		free(line);
		return (0);
	}
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (line[ft_strlen(line) - 1] != '1')
		ft_exit("Not 1 ended error!\n");
	if (meta->max_width < (int) ft_strlen(line))
		meta->max_width = ft_strlen(line);
	return (3);
}

int	map_init(t_meta_data *meta, char **tmp_map, int idx, int s_flag)
{
	char	*line;
	int		temp;

	while (1)
	{
		line = get_next_line(meta->fd);
		temp = map_init_sub(meta, line, &s_flag);
		if (temp == 0)
			break ;
		else if (temp == 1)
			continue ;
		tmp_map = meta->map;
		meta->map = (char **)malloc(sizeof(char *) * (meta->height + 2));
		meta->map[meta->height + 1] = 0;
		idx = -1;
		while (++idx < meta->height)
			meta->map[idx] = tmp_map[idx];
		meta->map[idx] = ft_strdup(line);
		if (tmp_map)
			free(tmp_map);
		height_plus_free(meta, line);
	}
	map_init_util(meta);
	make_sp_map(meta);
	return (0);
}
