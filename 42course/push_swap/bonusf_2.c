/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusf_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:59:27 by youngski          #+#    #+#             */
/*   Updated: 2022/12/28 20:16:51 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sb_b(t_list **root2)
{
	int	data;

	if (! (*root2))
		return ;
	data = (*root2)->data;
	(*root2)->data = (*root2)->next->data;
	(*root2)->next->data = data;
}

void	ra_b(t_list **root1)
{
	t_list	*temp;
	t_list	*end;

	if (!(*root1) || !((*root1)->next))
		return ;
	end = *root1;
	temp = *root1;
	*root1 = (*root1)->next;
	while (end->next)
	{
		end = end->next;
	}
	end->next = temp;
	temp->next = 0;
}

void	rr_b(t_list **root1, t_list **root2)
{
	ra_b(root1);
	rb_b(root2);
}

void	rra_b(t_list **root1)
{
	t_list	*temp;
	t_list	*end;
	t_list	*prev;

	if (!(*root1) || !((*root1)->next))
		return ;
	end = *root1;
	temp = *root1;
	while (end->next)
	{
		prev = end;
		end = end->next;
	}
	end->next = *root1;
	*root1 = end;
	prev->next = 0;
}

void	rrr_b(t_list **root1, t_list **root2)
{
	rra_b(root1);
	rrb_b(root2);
}
