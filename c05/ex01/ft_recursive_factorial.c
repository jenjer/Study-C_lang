/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:55:15 by youngski          #+#    #+#             */
/*   Updated: 2022/09/02 03:43:18 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb);

int ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return 0;
	if(nb - 1 > 0)
	nb *= ft_recursive_factorial(nb - 1);
	return nb;
}
