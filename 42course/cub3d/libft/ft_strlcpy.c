/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:13:20 by youngski          #+#    #+#             */
/*   Updated: 2023/03/25 12:53:57 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_max(const char *arr)
{
	int	i;

	i = 0;
	while (*(arr + i))
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	if (dstsize < 1)
		return (count_max(src));
	while (i < dstsize -1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count_max(src));
}
