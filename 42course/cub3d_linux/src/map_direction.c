/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:42:38 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/22 16:21:33 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	check_direction(t_meta_data *meta)
{
	if (!meta->tex[0].tex_path || !meta->tex[1].tex_path \
			|| !meta->tex[2].tex_path || !meta->tex[3].tex_path)
		return (1);
	if (!meta->f_color || !meta->c_color)
		return (1);
	if (meta->f_color->red == -1 || meta->f_color->green == -1
		|| meta->f_color->blue == -1)
		return (1);
	if (meta->c_color->red == -1 || meta->c_color->green == -1
		|| meta->c_color->blue == -1)
		return (1);
	return (0);
}

int	see_flag(t_meta_data *meta, char *tmp, int flag)
{
	int	fd;

	if (flag == 5 || flag == 6)
	{
		if (add_color(meta, tmp, flag, -1))
			return (1);
		return (0);
	}
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
		ft_exit("Texture file open error!\n");
	if (flag == 1 || flag == 2 || flag == 3 || flag == 4)
		check_dup_path(meta, tmp, flag);
	return (0);
}

void	make_flag(char *line, int *flag, char **tmp)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		*flag = 1;
	else if (ft_strncmp(line, "SO", 2) == 0)
		*flag = 2;
	else if (ft_strncmp(line, "WE", 2) == 0)
		*flag = 3;
	else if (ft_strncmp(line, "EA", 2) == 0)
		*flag = 4;
	else if (ft_strncmp(line, "F", 1) == 0)
		*flag = 5;
	else if (ft_strncmp(line, "C", 1) == 0)
		*flag = 6;
	if (*flag < 5)
		*tmp += 2;
	else
		(*tmp)++;
}

int	add_direction(t_meta_data *meta, char *line, int *check)
{
	int		flag;
	char	*tmp;
	char	*for_free;

	flag = 0;
	tmp = ft_strdup(line);
	for_free = tmp;
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		make_flag(line, &flag, &tmp);
		skip_space(&tmp);
	}
	else
		ft_exit("Incorrect Prefix!\n");
	if (see_flag(meta, tmp, flag))
		ft_exit("Incorrect information!\n");
	free(for_free);
	for_free = NULL;
	(*check)++;
	return (0);
}

int	map_direction_init(t_meta_data *meta, int check, char *line)
{
	while (1)
	{
		line = get_next_line(meta->fd);
		if (!line)
			ft_exit("Getting line error!");
		if (ft_strlen(line) == 1 && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		add_direction(meta, line, &check);
		free(line);
		if (check == 6)
			break ;
	}
	if (check_direction(meta))
		ft_exit("Incorrect informations!\n");
	return (0);
}
