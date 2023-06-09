/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:35:05 by youngski          #+#    #+#             */
/*   Updated: 2023/05/22 16:27:01 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	skip_space(char **str)
{
	int	i;

	i = 0;
	while (*str[0] == ' ')
	{
		i++;
		(*str)++;
	}
	if (i != 1)
		ft_exit("Not following order!\n");
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			;
		else
			return (1);
		i++;
	}
	return (0);
}

int	map_free_all(t_meta_data meta, int i)
{
	if (meta.f_color)
		free(meta.f_color);
	if (meta.c_color)
		free(meta.c_color);
	while (meta.map[i])
		free(meta.map[i++]);
	free(meta.map);
	i = 0;
	while (meta.sp_map[i])
		free(meta.sp_map[i++]);
	free(meta.sp_map);
	i = 0;
	while (i < meta.height + 2)
		free(meta.visited[i++]);
	free(meta.visited);
	i = -1;
	while (++i < 4)
	{
		free(meta.tex[i].tex_path);
		free(meta.tex[i].texture);
	}
	free(meta.tex);
	return (0);
}

int	ft_strrncmp(char *s1, char *s2, int n)
{
	int	i;

	i = ft_strlen(s1) - 1;
	if (i < 4)
		return (1);
	n--;
	while (s1[i] == s2[n])
	{
		if (i == 0 || n == 0)
			break ;
		i--;
		n--;
	}
	if (i && s1[i - 1] == '/')
		return (1);
	if (s1[i] == s2[n])
		return (0);
	else
		return (1);
}
