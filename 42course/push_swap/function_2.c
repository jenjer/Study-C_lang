/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:35:47 by youngski          #+#    #+#             */
/*   Updated: 2022/12/24 16:10:53 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void sb(t_list *root2, int flag)
{
    int data;

    if (!root2)
        return ;
    data = root2->data;
    root2->data = root2->next->data;
    root2->next->data = data;
	if (flag == 1)
		ft_printf("sb\n");
}

void ra(t_list **root1, int flag)
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
	if (flag == 1)
		ft_printf("ra\n");
}

void rr(t_list **root1, t_list **root2)
{
	ra(root1, 0);
	ra(root2, 0);
	ft_printf("rr\n");
}

void rra(t_list **root1, int flag)
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
	if (flag == 1)
		ft_printf("rra\n");
}

void rrr(t_list **root1, t_list **root2)
{
	rra(root1, 0);
	rra(root2, 0);
	ft_printf("rrr\n");
}

