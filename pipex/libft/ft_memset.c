/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:09:39 by youngski          #+#    #+#             */
/*   Updated: 2022/11/10 21:33:26 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bb;
	size_t			i;

	i = 0;
	c = (unsigned char)c;
	bb = (unsigned char *)b;
	while (i < len)
	{
		bb[i] = c;
		i++;
	}
	return ((void *)bb);
}
