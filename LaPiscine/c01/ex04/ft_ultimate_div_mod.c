/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:29:13 by youngski          #+#    #+#             */
/*   Updated: 2022/08/27 00:01:22 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int*b);

void	ft_ultimate_div_mod(int *a, int*b)
{
	int	num;
	int	num1;

	num = *a / *b;
	num1 = *a % *b;
	*a = num;
	*b = num1;
}
