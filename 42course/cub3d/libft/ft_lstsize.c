/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:43:16 by youngski          #+#    #+#             */
/*   Updated: 2022/11/15 13:06:47 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*temp;

	len = 0;
	if (!lst)
		return (0);
	temp = lst;
	while (temp->next)
	{
		len++;
		temp = temp->next;
	}
	if (temp->next == NULL)
		len++;
	return (len);
}
