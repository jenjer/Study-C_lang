/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:39:57 by youngski          #+#    #+#             */
/*   Updated: 2022/09/10 17:35:34 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	int		i;
	char	*node;

	i = 0;
	while (src[i])
		i++;
	node = malloc(sizeof(char) * (i + 1));
	if (!node)
		return NULL;
	i = 0;
	while (src[i])
	{
		node[i] = src[i];
		i++;
	}
	node[i] = '\0';
	return (node);
}
