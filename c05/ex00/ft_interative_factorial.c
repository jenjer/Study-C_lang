/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interative_factorial.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:49:44 by youngski          #+#    #+#             */
/*   Updated: 2022/09/02 03:41:22 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int ft_interative_factorial(int nb);

int	ft_interative_factorial(int nb)
{
	long long int i;

	i = nb;
	while (i -1 > 0)
	{
		nb *= i -1;
		i--;
	}
	return nb;
}
