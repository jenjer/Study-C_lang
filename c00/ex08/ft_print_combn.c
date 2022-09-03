/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 01:29:29 by youngski          #+#    #+#             */
/*   Updated: 2022/08/30 01:18:07 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	func_add(int *arr, int n, int index);
void	func_print(int *arr, int n);

void	func_add(int *arr, int n, int index)
{
	if (arr[n - 1 - index] == 9 - index)
	{
		func_add(arr, n, index + 1);
		arr[n - 1 - index] = arr[n - 2 - index] + 1;
	}
	else
		arr[n -1 - index] = arr[n -1 - index] + 1;
}

void	func_print(int *arr, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = arr[i] + '0';
		write (1, &c, 1);
		if (i == n -1 && arr[0] != 10 - n)
		{
			write(1, ", ", 2);
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	arr[9];

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	while (arr[0] != 10 - n)
	{
		func_print(arr, n);
		func_add(arr, n, 0);
	}
	func_print(arr, n);
}
