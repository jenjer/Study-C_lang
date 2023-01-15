/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:05:20 by youngski          #+#    #+#             */
/*   Updated: 2022/11/12 17:44:18 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*for_ret;

	len = ft_strlen(s1);
	for_ret = (char *)malloc(len + 1);
	if (!for_ret)
		return (0);
	ft_strlcpy(for_ret, s1, len + 1);
	return (for_ret);
}
