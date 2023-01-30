/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:53:54 by youngski          #+#    #+#             */
/*   Updated: 2022/11/18 17:12:32 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*deling(void *content, void (*del)(void *))
{
	if (content)
		del(content);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret_start;
	t_list	*ret_last;
	void	*content;

	if (!lst)
		return (0);
	content = f(lst-> content);
	ret_start = ft_lstnew(content);
	if (!ret_start)
		return (deling(content, del));
	ret_last = ret_start;
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		ret_last -> next = ft_lstnew(content);
		ret_last = ret_last->next;
		if (!ret_last)
		{
			ft_lstclear(&ret_start, del);
			return (deling(content, del));
		}
		lst = lst ->next;
	}
	return (ret_start);
}
