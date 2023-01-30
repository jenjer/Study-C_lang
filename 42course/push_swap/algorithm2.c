/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:21:21 by youngski          #+#    #+#             */
/*   Updated: 2022/12/27 22:30:01 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_num_3(t_list **root1, int large)
{
	t_list	*temp;

	temp = *root1;
	while (temp)
	{
		if (temp->data > large)
			large = temp->data;
		temp = temp->next;
	}
	if ((*root1)->data == large)
	{
		ra(root1, 1);
		if ((*root1)->data > (*root1)->next->data)
			sa(*root1, 1);
	}
	else if ((*root1)->next->data == large)
	{
		rra(root1, 1);
		if ((*root1)->data > (*root1)->next->data)
			sa(*root1, 1);
	}
	else
		if ((*root1)->data > (*root1)->next->data)
			sa(*root1, 1);
}

int	find_small(t_list *root1, int size)
{
	int		small;
	int		count;
	t_list	*temp;

	small = 2147483647;
	count = 0;
	temp = root1;
	while (temp)
	{
		if (small > temp->data)
			small = temp->data;
		temp = temp->next;
	}
	temp = root1;
	while (temp)
	{
		if (temp->data == small)
			break ;
		count++;
		temp = temp->next;
	}
	if (count < size / 2)
		return (count);
	else
		return (- (size - count));
}

void	sort_num_4(t_list **root1, t_list **root2, int size)
{
	int		count;
	t_list	*temp;

	temp = *root1;
	count = find_small(*root1, size);
	while (count != 0)
	{
		if (count < 0)
		{
			rra(root1, 1);
			count ++;
			continue ;
		}
		if (count == 0)
			break ;
		ra(root1, 1);
		count--;
	}
	pb(root1, root2);
	sort_num_3(root1, -2147483648);
	pa(root1, root2);
}

void	sort_num_5(t_list **root1, t_list **root2, int size)
{
	int		count;
	t_list	*temp;

	temp = *root1;
	count = find_small(*root1, size);
	while (count != 0)
	{
		if (count < 0)
		{
			while (count)
			{
				rra(root1, 1);
				count ++;
			}
			break ;
		}
		if (count == 0)
			break ;
		ra(root1, 1);
		count--;
	}
	pb(root1, root2);
	sort_num_4(root1, root2, size - 1);
	pa(root1, root2);
	temp = *root1;
}

void	hard_coding(t_list **root1, t_list **root2, int size)
{
	if (size == 2)
	{
		if ((*root1)->data > (*root1)->next->data)
			sa(*root1, 1);
	}
	else if (size == 3)
		sort_num_3(root1, -2147483648);
	else if (size == 4)
		sort_num_4(root1, root2, size);
	else if (size == 5)
		sort_num_5(root1, root2, size);
	else
		sort_all(root1, root2, size);
}
