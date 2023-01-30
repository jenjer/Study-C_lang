/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusf_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:00:45 by youngski          #+#    #+#             */
/*   Updated: 2022/12/30 02:03:30 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rb_b(t_list **root2)
{
	t_list	*temp;
	t_list	*end;
	t_list	*second;

	if (! (*root2) || ! ((*root2)->next))
		return ;
	end = *root2;
	temp = *root2;
	second = (*root2)->next;
	while (end->next)
	{
		end = end->next;
	}
	temp->next = 0;
	end->next = temp;
	*root2 = second;
}

void	rrb_b(t_list **root2)
{
	t_list	*temp;
	t_list	*end;
	t_list	*prev;

	if (!(*root2) || !((*root2)->next))
		return ;
	end = *root2;
	temp = *root2;
	while (end->next)
	{
		prev = end;
		end = end->next;
	}
	end->next = *root2;
	*root2 = end;
	prev->next = 0;
}
