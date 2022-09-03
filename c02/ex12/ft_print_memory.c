/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:14:04 by youngski          #+#    #+#             */
/*   Updated: 2022/09/03 17:03:13 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	print_first(char c);
void	print_second(char c);
void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_first(char c)
{
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	int				count;
	unsigned char	for_hex[16];

	i = 0;
	if (size < 0)
		return ;
	while (i < size)
	{
	k = 0;
	i += 16;
	}
	return (addr);
}
