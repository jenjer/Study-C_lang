/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:09:35 by youngski          #+#    #+#             */
/*   Updated: 2022/11/30 20:34:58 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list ap, int flag)
{
	char	*t;
	char	k;
	int		count;

	count = 0;
	if (flag == 0)
	{
		t = va_arg(ap, char *);
		if (t == 0)
			count += write (1, "(null)", 6);
		else
			count += write (1, t, ft_strlen(t));
	}
	if (flag == 1)
	{
		k = va_arg(ap, unsigned int);
		write(1, &k, 1);
		count++;
	}
	return (count);
}

char	*make_hex(size_t t_temp, char *hex)
{
	char	*ret;
	size_t	count;
	size_t	i;

	if (t_temp == 0)
		return (ft_strdup("0"));
	count = 0;
	i = t_temp;
	while (i)
	{
		i /= 16;
		count++;
	}
	ret = (char *)malloc(count + 1);
	if (!ret)
		return (0);
	ret[count--] = 0;
	while (t_temp)
	{
		ret[count] = hex[t_temp % 16];
		t_temp /= 16;
		count--;
	}
	return (ret);
}

int	print_memo(va_list ap)
{
	int		ret;
	size_t	temp;
	size_t	len;
	char	*ans;
	char	*hex;

	ret = 0;
	len = 0;
	hex = "0123456789abcdef";
	temp = va_arg(ap, size_t);
	write (1, "0x", 2);
	ans = make_hex(temp, hex);
	if (!ans)
		return (-1);
	while (*ans)
	{
		write(1, ans, 1);
		ans++;
		ret++;
	}
	if (ans - ret)
		free(ans - ret);
	return (ret + 2);
}

int	err_check(const char *str, va_list ap)
{
	char	*dec;

	dec = "0123456789";
	str++;
	if (!str)
		return (-1);
	if (*str == 'c')
		return (print_str(ap, 1));
	if (*str == 's')
		return (print_str(ap, 0));
	if (*str == 'p')
		return (print_memo(ap));
	if (*str == 'd')
		return (print_decimal(ap));
	if (*str == 'i')
		return (print_decimal(ap));
	if (*str == 'u')
		return (print_udecimal(ap));
	if (*str == 'x')
		return (print_hex(ap, 0));
	if (*str == 'X')
		return (print_hex(ap, 1));
	if (*str == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		char_check;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			char_check = err_check(str, ap);
			if (char_check < 0)
				return (-1);
			count += char_check;
			str += 2;
			continue ;
		}
		write(1, str, 1);
		str++;
		count++;
	}
	va_end(ap);
	return (count);
}
