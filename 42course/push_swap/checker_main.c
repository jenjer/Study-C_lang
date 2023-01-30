/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:44:00 by youngski          #+#    #+#             */
/*   Updated: 2022/12/31 00:06:23 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	word_check1(char *c, t_list **root1, t_list **root2)
{
	if (ft_strcmp(c, "sa\n"))
		sa_b(root1);
	else if (ft_strcmp(c, "sb\n"))
		sb_b(root2);
	else if (ft_strcmp(c, "ss\n"))
		ss_b(root1, root2);
	else if (ft_strcmp(c, "pa\n"))
		pa_b(root1, root2);
	else if (ft_strcmp(c, "pb\n"))
		pb_b(root1, root2);
	else
		return (0);
	return (1);
}

int	word_check2(char *c, t_list **root1, t_list **root2)
{
	if (ft_strcmp(c, "ra\n"))
		ra_b(root1);
	else if (ft_strcmp(c, "rb\n"))
		rb_b(root2);
	else if (ft_strcmp(c, "rr\n"))
		rr_b(root1, root2);
	else if (ft_strcmp(c, "rra\n"))
		rra_b(root1);
	else if (ft_strcmp(c, "rrb\n"))
		rrb_b(root2);
	else if (ft_strcmp(c, "rrr\n"))
		rrr_b(root1, root2);
	else
		return (0);
	return (1);
}

void	fin_check(t_list **root1, t_list **root2, int i, int argc)
{
	int		*arr;
	int		flag;

	flag = 0;
	if ((*root2))
	{
		ft_printf("KO\n");
		return ;
	}
	arr = make_arr(*root1);
	while (++i < argc - 2)
	{
		if (arr[i] > arr[i + 1])
		{
			flag = 1;
			break ;
		}
		else
			flag = 0;
	}
	if (flag == 1)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(arr);
}

void	checker_run(t_list **root1, int argc)
{
	char	*t;
	t_list	*root2;
	int		order;
	int		flag;

	flag = 0;
	root2 = 0;
	order = 0;
	while (1)
	{
		t = get_next_line(0);
		if (!t)
			break ;
		if (word_check1(t, root1, &root2) == word_check2(t, root1, &root2))
		{
			flag = 1;
			ft_printf("Error\n");
			free(t);
			break ;
		}
		free(t);
	}
	if (flag == 0)
		fin_check(root1, &root2, -1, argc);
}

int	main(int argc, char *argv[])
{
	t_list	*root1;
	int		i;
	int		flag;

	flag = 0;
	root1 = 0;
	i = 1;
	if (argc == 1)
		return (0);
	argc = argument_setting(argc, argv, &root1, 0);
	if ((root1 == NULL) || overlaped(root1) || argc == 0)
	{
		ft_printf("Error\n");
		ft_lstclear(&root1);
		return (0);
	}
	checker_run(&root1, argc + 1);
	ft_lstclear(&root1);
	return (0);
}
