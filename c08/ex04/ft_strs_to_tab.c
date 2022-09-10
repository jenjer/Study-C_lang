/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:20:13 by youngski          #+#    #+#             */
/*   Updated: 2022/09/10 18:44:39 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
char				*ft_strdup(char *src);
int					len_arr(char *src);

char	*ft_strdup(char *src)
{
	char	*arr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	arr = malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (0);
	i = 0;
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int	len_arr(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*for_return;

	i = 0;
	for_return = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!for_return)
		return (NULL);
	while (i < ac)
	{
		for_return[i].str = av[i];
		for_return[i].size = len_arr(av[i]);
		for_return[i].copy = ft_strdup(av[i]);
		i++;
	}
	for_return[i].str = 0;
	return (for_return);
}
