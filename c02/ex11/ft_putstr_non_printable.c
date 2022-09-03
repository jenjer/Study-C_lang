/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:13:40 by youngski          #+#    #+#             */
/*   Updated: 2022/09/02 22:23:56 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	print_hex(unsigned char c);
void	printing(unsigned char *str);

void	print_hex(unsigned char c)
{
	int	num1;
	int	num2;

	num1 = (unsigned char)c / 16;
	num2 = (unsigned char)c % 16;
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[num1], 1);
	write(1, &"0123456789abcdef"[num2], 1);
}

void	printing(unsigned char *str)
{
	unsigned int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 127 || (str[i] >= 0 && str[i] <= 31))
		{
			print_hex(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*mystring;

	mystring = (unsigned char *)str;
	printing(mystring);
}
