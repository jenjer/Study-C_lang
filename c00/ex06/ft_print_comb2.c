/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 05:06:12 by youngski          #+#    #+#             */
/*   Updated: 2022/08/25 14:42:00 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	print_int_one(int number);
void	print_int_two(int number1, int number2);

void	print_int_one(int number)
{
	char	world[2];
	int		temp0;
	int		temp1;

	temp1 = number % 10;
	temp0 = number / 10;
	world[0] = temp0 + '0';
	world[1] = temp1 + '0';
	write(1, world, 2);
}

void	print_int_two(int number1, int number2)
{
	char	sp;

	sp = ' ';
	print_int_one(number1);
	write(1, &sp, 1);
	print_int_one(number2);
}

void	ft_print_comb2(void)
{
	int		first;
	int		second;
	char	comma[2];

	comma[0] = ',';
	comma[1] = ' ';
	first = 0;
	second = 1;
	while (first < 99)
	{
		while (second < 100)
		{
			print_int_two (first, second);
			if (first != 98)
				write (1, comma, 2);
			second++;
		}
		first++;
		second = first +1;
	}
}
