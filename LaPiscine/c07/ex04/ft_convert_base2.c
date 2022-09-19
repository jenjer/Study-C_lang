/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:44:39 by youngski          #+#    #+#             */
/*   Updated: 2022/09/12 04:10:26 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);
int	start_base(char *str, int *i);
int	putnbr_base(int for_return, char *base);
int	base_check(char *base);
int	start_flag(char *str, int *i);

int	start_flag(char *str, int *i)
{
	int	flag;

	flag = 1;
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v' || \
str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		*i = *i + 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			flag *= -1;
		*i = *i + 1;
	}
	return (flag);
}

int	base_check(char *base)
{
	int	i;
	int	j;
	
	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-' ||
					base[j] == ' ' || base[j] == '\t' || base[j] == '\n' ||
					base[j] == '\v' || base[j] == '\f' || base[j] == '\r')
				return (0);
			j++;
		}
		i++;
	}
	return (1);

}

int	is_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	run_base(char *str, char *base, int i)
{
	int	base_len;
	int	for_return;
	
	for_return = 0;
	base_len = 0;
	if (base_check(base) == 0)
		return (0);
	while (base[base_len])
		base_len++;
		
	
	while (str[i] && (is_in_base(str[i], base) >= 0))
	{
		for_return = (for_return * base_len) + is_in_base(str[i], base);
		i++;
	}
	return (for_return);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	for_return;
	int	flag;

	for_return = 0;
	i = 0;
	flag = start_flag(str, &i);
	for_return = run_base(str, base, i);
	return (flag * for_return);
}
