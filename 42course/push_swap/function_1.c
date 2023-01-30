/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:41:21 by youngski          #+#    #+#             */
/*   Updated: 2022/12/27 22:32:00 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sa(t_list *root1, int flag)
{
	int	data;

	if (!root1 || !(root1->next))
		return ;
	data = root1->data;
	root1->data = root1->next->data;
	root1->next->data = data;
	if (flag == 1)
		ft_printf("sa\n");
}

void	ss(t_list *root1, t_list *root2)
{
	sa(root1, 0);
	sb(root2, 0);
	ft_printf("ss\n");
}

void	pb(t_list **root1, t_list **root2)
{
	t_list	*temp1;

	temp1 = *root1;
	if (!(*root1))
		return ;
	if (!(*root2))
	{
		*root1 = (*root1)->next;
		temp1->next = 0;
		*root2 = temp1;
	}
	else
	{
		(*root1) = (*root1)->next;
		ft_lstadd_front(root2, temp1);
	}
	ft_printf("pb\n");
}

void	pa(t_list **root1, t_list **root2)
{
	t_list	*temp2;

	temp2 = *root2;
	if (!(*root2))
		return ;
	if (!(*root1))
	{
		*root2 = (*root2)->next;
		temp2->next = 0;
		*root1 = temp2;
	}
	else
	{
		(*root2) = (*root2)->next;
		ft_lstadd_front(root1, temp2);
	}
	ft_printf("pa\n");
}
