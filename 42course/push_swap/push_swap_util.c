/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:18:41 by youngski          #+#    #+#             */
/*   Updated: 2022/12/30 17:03:05 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	do_run(t_list **root1, int argc, int flag)
{
	int	*arr;
	int	i;

	i = -1;
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
	if (flag == 0)
	{
		free(arr);
		return (0);
	}
	arr = bubble_sort(arr, argc);
	make_list_index(*root1, arr, argc - 1);
	make_ans(root1, argc -1);
	free(arr);
	return (0);
}	

int	make_chunk(int size)
{
	if (size <= 100)
		return (15);
	else if (size <= 500)
		return (30);
	else if (size <= 1000)
		return (45);
	else if (size <= 2000)
		return (65);
	else if (size <= 5000)
		return (150);
	return (200);
}

void	move_b(t_list **root1, t_list **root2, int size, int num)
{
	int	chunk;
	int	flag;
	int	temp;

	temp = size;
	chunk = make_chunk(size);
	flag = 0;
	while (*root1)
	{
		if (num > (*root1)->data)
		{
			pb(root1, root2);
			chunk++;
			num++;
		}
		else if (num <= (*root1)->data && chunk >= (*root1)->data)
		{
			pb(root1, root2);
			rb(root2, 1);
			chunk++;
			num++;
		}
		else
			ra(root1, 1);
	}
}

int	find_large(t_list *root1, int size)
{
	int		small;
	int		count;
	t_list	*temp;

	small = -1;
	count = 0;
	temp = root1;
	while (temp)
	{
		if (small < temp->data)
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

void	move_a(t_list **root1, t_list **root2, int size)
{
	int		count;
	t_list	*temp;

	while (*root2)
	{
		temp = *root2;
		count = find_large(*root2, size--);
		while (count != 0)
		{
			if (count < 0)
			{
				while (count)
				{
					rrb(root2, 1);
					count ++;
				}
				break ;
			}
			if (count == 0)
				break ;
			rb(root2, 1);
			count--;
		}
		pa(root1, root2);
	}
}
