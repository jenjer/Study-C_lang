/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:45:18 by youngski          #+#    #+#             */
/*   Updated: 2022/12/27 12:54:02 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_five(t_list *root1)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = root1;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	return i;
}

void sorting_all_list(t_list **root1, t_list **root2, int size)
{
	hard_coding(root1, root2, size);
}

int make_ans(t_list **root1, int size)
{
	t_list *root2;
	(void) size;

	root2 = 0;
	t_list *temp;
	temp = *root1;
	hard_coding(root1, &root2, size);
	return 0;
}
