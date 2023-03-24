/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:59 by youngski          #+#    #+#             */
/*   Updated: 2022/12/28 21:44:37 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlcpy_1(char *dest, char *src, size_t n, int flag)
{
	size_t	i;

	i = 0;
	if (flag == 1)
	{
		while (src[i] && i + 1 < n && src[i] != '\n')
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (flag == 0)
	{
		while (src[i] && i + 1 < n)
		{
			dest[i] = src[i];
			i++;
		}
	}		
	if (src[i] == '\n')
		dest[i++] = '\n';
	dest[i] = 0;
}

char	*cp_save_to_ret(t_mynode *temp, char *src, ssize_t i)
{
	ssize_t	k;
	char	*ret;

	k = 0;
	while (temp->content[i] && temp->content[i] != '\n')
		i++;
	if (temp->content[i] == '\n')
		i++;
	while (src[k])
		k++;
	ret = (char *)malloc(sizeof(char) * (i + k + 1));
	if (!ret)
		return (0);
	ft_strlcpy_1(ret, src, k + 1, 1);
	ft_strlcpy_1(ret + k, temp->content, i + 1, 1);
	ft_strlcpy_1(temp->content, (temp->content) + i, (temp->size) - i + 1, 0);
	temp->size -= i;
	free(src);
	if (!ret[0])
	{
		free(ret);
		return (0);
	}
	return (ret);
}

char	*read_loop(t_mynode **root, t_mynode *temp, char *ret, size_t i)
{
	while (1)
	{
		if (temp->content[0] == 0)
		{
			if (read_line(temp, root) == -1)
			{
				free(ret);
				return (0);
			}
			if (temp->size <= 0)
			{
				free_node(root, temp ->fd);
				break ;
			}
		}
		ret = cp_save_to_ret(temp, ret, 0);
		if (!ret)
			return (free_node(root, temp->fd));
		while (ret[i] && ret[i] != '\n')
			i++;
		if (ret[i] == '\n')
			break ;
	}
	return (ret);
}

char	*make_return(t_mynode *temp, t_mynode **root)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc(sizeof(char));
	if (!ret)
		return (free_node(root, temp->fd));
	ret[0] = 0;
	ret = read_loop(root, temp, ret, i);
	if (!ret)
		return (0);
	if (!ret[0])
	{
		free(ret);
		return (0);
	}
	return (ret);
}
