/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:43:18 by youngski          #+#    #+#             */
/*   Updated: 2022/09/12 06:32:28 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_atoi_base(char *str, char *base);
int		start_base(char *str, int *i);
int		putnbr_base(int for_return, char *base);
int		base_check(char *base);
int		start_flag(char *str, int *i);

int	ft_strlen_(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	zero_work(char *base, char *ret)
{
	free(ret);
	ret = (char *)malloc(sizeof(char) * 2);
	ret[0] = base[0];
	ret[1] = '\0';
}

void	print_things(long nbr, char *base, char *ret, int ret_len)
{
	long	lnbr;
	int		index;
	int		i;

	lnbr = nbr;
	i = 0;
	ret[ret_len] = '\0';
	ret_len--;
	index = ret_len;
	if (nbr == 0)
	{
		zero_work(base, ret);
		return ;
	}
	if (nbr < 0)
	{
		lnbr = -lnbr;
		ret[0] = '-';
	}	
	while (lnbr > 0)
	{
		ret[index] = base[lnbr % ft_strlen_(base)];
		lnbr = lnbr / ft_strlen_(base);
		index--;
	}
}	

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*ret;
	int		before_ret;
	int		i;
	int		j;
	long	before_ret_calc;

	j = 0;
	i = 0;
	if (!base_check(base_from) || !base_check(base_to))
		return (NULL);
	before_ret = ft_atoi_base(nbr, base_from);
	before_ret_calc = before_ret;
	if (before_ret_calc < 0)
		before_ret_calc *= (-1);
	while (before_ret_calc > 0)
	{
		before_ret_calc = before_ret_calc / ft_strlen_(base_to);
		j++;
	}
	if (before_ret < 0)
		j += 1;
	ret = (char *)malloc(sizeof(char) *(j + 1));
	print_things(before_ret, base_to, ret, j);
	return (ret);
}
