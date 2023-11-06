/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:05:20 by youngski          #+#    #+#             */
/*   Updated: 2023/03/28 22:57:51 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
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
