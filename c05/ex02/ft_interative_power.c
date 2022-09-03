/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interative_power.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:58:15 by youngski          #+#    #+#             */
/*   Updated: 2022/09/02 03:49:10 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_interative_power(int nb, int power);

int	ft_interative_power(int nb, int power)
{
	int k;

	k = nb;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= k;	
		power--;
	}
	
	return (nb);
}
