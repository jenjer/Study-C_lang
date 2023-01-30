/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:42:08 by youngski          #+#    #+#             */
/*   Updated: 2022/11/18 17:21:07 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy(unsigned char *udst, unsigned char *usrc, size_t len)
{
	unsigned char	temp;
	size_t			i;

	i = 0;
	if (udst - usrc > 0)
	{
		while (len--)
		{
			temp = usrc[len];
			udst[len] = temp;
		}
	}
	else
	{
		while (i < len)
		{
			temp = usrc[i];
			udst[i] = temp;
			i++;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	cpy(udst, usrc, len);
	return ((void *)udst);
}
