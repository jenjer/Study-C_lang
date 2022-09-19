/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:40:40 by youngski          #+#    #+#             */
/*   Updated: 2022/09/11 22:19:41 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	long long	size;
	long long	k;
	long long	my_min;
	long long	my_max;
	int			*ret;

	my_min = min;
	my_max = max;
	if (min >= max)
		return (NULL);
	size = my_max - my_min;
	k = 0;
	ret = malloc(sizeof(int) * size);
	if (ret == NULL)
		return (NULL);
	while (size > 0)
	{
		ret[k] = min + k;
		k++;
		size--;
	}
	return (ret);
}
