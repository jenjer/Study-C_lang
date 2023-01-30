/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:19:37 by youngski          #+#    #+#             */
/*   Updated: 2022/11/18 17:10:17 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		num_len;
	int		temp;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	temp = n;
	if (temp < 0)
		temp *= -1;
	num_len = count_num_len(n);
	ret = (char *)malloc(count_num_len(n) + 1);
	if (!ret)
		return (0);
	while (num_len)
	{
		ret[num_len - 1] = temp % 10 + '0';
		temp /= 10;
		num_len--;
	}
	if (n < 0)
		ret[0] = '-';
	ret[count_num_len(n)] = 0;
	return (ret);
}
