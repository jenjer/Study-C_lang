/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:42:00 by youngski          #+#    #+#             */
/*   Updated: 2022/09/11 00:47:01 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int *arr;
	int	i;

	if (min > max)
	{
		*range = NULL;
		return 0;
	}
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == NULL)
		return -1;
	else
	{
		i = 0;
		while (i < max - min)
		{
			arr[i] = min + i;
			i++;
		}
		*range = arr;
	}	
	return (i);
}
