/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:02:01 by youngski          #+#    #+#             */
/*   Updated: 2023/03/25 12:57:07 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	len;
	char	*ret;

	if (!s1 || !set || (!s1 && !set))
		return (0);
	i = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[len - 1] && ft_strchr(set, s1[len - 1]))
	{
		if (len-- -1 < 1)
			break ;
	}
	if (i > len)
		return (ft_strdup(""));
	ret = (char *)malloc(len - i + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1 + i, len - i + 1);
	return (ret);
}
