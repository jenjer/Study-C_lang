/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_direction2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:34:13 by youngski          #+#    #+#             */
/*   Updated: 2023/05/19 16:18:35 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	check_dup_path(t_meta_data *meta, char *tmp, int flag)
{
	if (flag == 1)
	{
		if ((meta->tex[0].tex_path))
			ft_exit("Duplicated information!\n");
		meta->tex[0].tex_path = ft_strdup(tmp);
	}
	else if (flag == 2)
	{
		if ((meta->tex[1].tex_path))
			ft_exit("Duplicated information!\n");
		meta->tex[1].tex_path = ft_strdup(tmp);
	}	
	else if (flag == 3)
	{
		if ((meta->tex[2].tex_path))
			ft_exit("Duplicated information!\n");
		meta->tex[2].tex_path = ft_strdup(tmp);
	}	
	else if (flag == 4)
	{
		if ((meta->tex[3].tex_path))
			ft_exit("Duplicated information!\n");
		meta->tex[3].tex_path = ft_strdup(tmp);
	}		
}

int	freeing_line_and_fin(char *line)
{
	free(line);
	return (ft_exit("file open error\n"));
}
