/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:34:28 by youngski          #+#    #+#             */
/*   Updated: 2022/11/12 17:47:38 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*myreturn;

	if (size > 0 && count > SIZE_MAX / size)
		return (0);
	myreturn = malloc(size * count);
	if (!myreturn)
		return (0);
	ft_bzero(myreturn, size * count);
	return ((void *)myreturn);
}
