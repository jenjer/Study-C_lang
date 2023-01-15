/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:56:16 by youngski          #+#    #+#             */
/*   Updated: 2022/12/24 21:11:10 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	max(char *str)
{
	long	i;
	long	for_return;
	int		flag;

	i = 0;
	flag = 1;
	for_return = 0;
	if (str[0] == '-')
	{
		flag = -1;
		i = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		for_return = for_return * 10 + (str[i] - 48);
		i++;
	}
	if (flag == -1)
		for_return *= -1;
	if (for_return > 2147483647 || for_return < -2147483648)
		return (1);
	return (0);
}

int	error_check(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		return (0);
	while (argv[++i])
	{
		j = -1;
		if (max(argv[i]))
			return (0);
		if (argv[i][0] == 0)
			return (0);
		while (argv[i][++j])
		{
			if (j == 0 && argv[i][j] == '-' && argv[i][j + 1])
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
	}
	if (i < argc)
		return (0);
	return (1);
}

int	overlaped(t_list *root)
{
	t_list	*rt_next;

	while (root)
	{
		rt_next = root->next;
		while (rt_next)
		{
			if (root->data == rt_next->data)
				return (1);
			rt_next = rt_next->next;
		}
		root = root->next;
	}
	return (0);
}

int	push_swap(int argc, char *argv[])
{
	t_list	*root1;
	int		i;

	root1 = 0;
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&root1, ft_lstnew(atoi(argv[i])));
		i++;
	}
	if ((! error_check(argc, argv)) || overlaped(root1))
	{
		ft_printf("Error");
		return (0);
	}
	do_run(root1, argc);
	return (0);
}
