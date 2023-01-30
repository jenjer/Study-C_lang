/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:28:05 by youngski          #+#    #+#             */
/*   Updated: 2022/11/30 20:35:47 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_anything(int arg, char *degree, char *print, int index)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	if (arg < 0)
	{
		write(1, "-", 1);
		flag = 1;
		arg *= -1;
	}
	while (arg)
	{
		print[index--] = degree[arg % 10];
		arg = arg / 10;
		count++;
	}
	write(1, print, count);
	if (flag == 1)
		count++;
	return (count);
}

int	check_limit(void *arg, int flag)
{
	int				i;
	unsigned int	ui;

	i = 0;
	ui = 0;
	if (flag == 0)
		i = *(int *)arg;
	else
		ui = *(unsigned int *)arg;
	if (i == 2147483647)
		return (write (1, "2147483647", 10));
	if (ui == 4294967295)
		return (write (1, "4294967295", 10));
	else if (i == -2147483648)
		return (write (1, "-2147483648", 11));
	return (0);
}

int	print_decimal(va_list ap)
{
	ssize_t	arg;
	int		temp;
	char	*print;
	int		len;

	arg = va_arg(ap, int);
	temp = check_limit(&arg, 0);
	if (temp)
		return (temp);
	print = ft_itoa(arg);
	if (!print)
		return (-1);
	len = ft_strlen(print);
	write (1, print, len);
	free(print);
	return (len);
}

int	print_udecimal(va_list ap)
{
	ssize_t	arg;
	char	*print;
	int		len;

	arg = va_arg(ap, unsigned int);
	print = ft_itoa(arg);
	if (!print)
		return (-1);
	len = ft_strlen(print);
	write (1, print, len);
	free(print);
	return (len);
}

int	print_hex(va_list ap, int flag)
{
	char			*print;
	unsigned int	temp;
	char			*hex;
	unsigned int	count;

	count = 0;
	temp = va_arg(ap, unsigned int);
	if (temp == 0)
		return (write (1, "0", 1));
	hex = "0123456789ABCDEF";
	if (flag == 0)
		hex = "0123456789abcdef";
	print = make_hex(temp, hex);
	if (!print)
		return (-1);
	while (*print)
	{
		write(1, print, 1);
		print++;
		count++;
	}
	if (print - count)
		free(print - count);
	return (count);
}
