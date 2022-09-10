/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:58:15 by youngski          #+#    #+#             */
/*   Updated: 2022/09/09 23:39:18 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int	k;

	k = nb;
	if (power == 0)
		return (1);
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		nb *= k;
		power--;
	}
	return (nb);
}
