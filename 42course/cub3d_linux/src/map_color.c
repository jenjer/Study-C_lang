/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:06:26 by gyopark           #+#    #+#             */
/*   Updated: 2023/05/22 17:03:22 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	match_color(t_color *color, char **rgb)
{
	color->red = ft_atoi(rgb[0]);
	color->green = ft_atoi(rgb[1]);
	color->blue = ft_atoi(rgb[2]);
	if (color->red < 0 || color->red > 255)
		return (1);
	else if (color->green < 0 || color->green > 255)
		return (1);
	else if (color->blue < 0 || color->blue > 255)
		return (1);
	return (0);
}

void	init_color(t_color *color)
{
	color->red = -1;
	color->green = -1;
	color->blue = -1;
}

int	add_color(t_meta_data *meta, char *tmp, int flag, int i)
{
	t_color	*color;
	char	**rgb;

	color = (t_color *)malloc(sizeof(t_color));
	init_color(color);
	if (flag == 5)
		meta->f_color = color;
	else
		meta->c_color = color;
	rgb = ft_split(tmp, ',');
	while (rgb[++i])
	{
		if (ft_isnum(rgb[i]))
			return (1);
	}
	if (i != 3 || match_color(color, rgb))
	{
		free_spl(rgb);
		rgb = NULL;
		return (1);
	}
	free_spl(rgb);
	rgb = NULL;
	return (0);
}
