/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:42:20 by youngski          #+#    #+#             */
/*   Updated: 2022/11/12 17:39:38 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (ft_strlen(s) == 0)
	{
		if (s[0] == (char)c)
			return ((char *)s);
		else
			return (0);
	}
	i = ft_strlen(s);
	while (i && s[i] != (char)c)
	{
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
