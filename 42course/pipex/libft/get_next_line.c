/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:42:40 by youngski          #+#    #+#             */
/*   Updated: 2022/12/28 17:13:26 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mynode	*create_node(int fd)
{
	t_mynode	*ret;

	ret = (t_mynode *)malloc(sizeof(t_mynode));
	if (!ret)
		return (0);
	ret->content = (char *)malloc(BUFFER_SIZE + 1);
	if (!ret->content)
	{
		free(ret);
		return (0);
	}
	ret->content[BUFFER_SIZE] = 0;
	ret->content[0] = 0;
	ret->fd = fd;
	ret->next = 0;
	ret->size = 0;
	return (ret);
}

char	*free_node(t_mynode **root, int fd)
{
	t_mynode	*temp;
	t_mynode	*prev;

	prev = 0;
	temp = *root;
	while (temp)
	{
		if (temp->fd == fd)
		{
			if (!prev)
				*root = temp->next;
			else
				prev->next = temp->next;
			free(temp->content);
			free(temp);
			temp = NULL;
			return (0);
		}
		prev = temp;
		temp = temp -> next;
	}
	return (0);
}	

t_mynode	*find_node(t_mynode **root, int fd)
{
	t_mynode	*temp;

	if (*root == NULL)
	{
		*root = create_node(fd);
		if (!root)
			return (0);
	}
	temp = *root;
	while (temp->next && temp->fd != fd)
	{
		temp = temp->next;
	}
	if (temp->fd == fd)
		return (temp);
	temp->next = create_node(fd);
	if (!temp->next)
		return (0);
	return (temp->next);
}

int	read_line(t_mynode *temp, t_mynode **root)
{
	if (!temp->size)
	{
		temp->size = read(temp->fd, temp->content, BUFFER_SIZE);
		if (temp->size >= 0)
			temp->content[temp->size] = 0;
	}
	if (temp->size < 0)
	{
		free_node(root, temp->fd);
		return (-1);
	}
	return (1);
}

char	*get_next_line(int fd)
{	
	static t_mynode	*root;
	t_mynode		*temp;

	if (BUFFER_SIZE <= 0)
		return (0);
	temp = find_node(&root, fd);
	if (!temp)
		return (0);
	return (make_return(temp, &root));
}
