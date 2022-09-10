/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:11:02 by youngski          #+#    #+#             */
/*   Updated: 2022/09/07 00:52:08 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
void	print_things(long long nbr, char *base);
int		double_check(char *base);
int		ft_strlen_(char *str);

int	ft_strlen_(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	double_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i + 1] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0' && base[j] != base[i])
		{
			j++;
		}
		if (base[i] == base[j])
			return (0);
		i++;
	}
	return (1);
}

void	print_things(long long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr < 0)
		print_things(-nbr, base);
	while (base[i] != '\0')
		i++;
	if (nbr >= i)
	{
		print_things(nbr / i, base);
		print_things(nbr % i, base);
	}
	else if (nbr > -1)
	{
		write (1, &base[nbr], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (ft_strlen_(base) < 2)
		return ;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		i++;
	}
	if (double_check(base) == 0)
		return ;
	if (nbr < 0)
	{
		write (1, "-", 1);
	}
	print_things((long long)nbr, base);
}
