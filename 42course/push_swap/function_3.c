/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:29:43 by youngski          #+#    #+#             */
/*   Updated: 2022/12/27 15:41:01 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rb(t_list **root2, int flag)
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
	if (flag == 1)
		ft_printf("rb\n");
}

void	rrb(t_list **root2, int flag)
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
	if (flag == 1)
		ft_printf("rrb\n");
}
