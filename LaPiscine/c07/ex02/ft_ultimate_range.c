/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:42:00 by youngski          #+#    #+#             */
/*   Updated: 2022/09/12 06:35:07 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	long long	mx;
	long long	mn;

	mx = (long long)max;
	mn = (long long)min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (mx - mn));
	if (range == NULL)
		return (-1);
	else
	{
		i = 0;
		while (i < mx - mn)
		{
			(*range)[i] = min + i;
			i++;
		}
	}	
	return (i);
}
