/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:42:20 by youngski          #+#    #+#             */
/*   Updated: 2022/09/12 03:26:00 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		count_length(int size, int all_length, char *seq);
int		str_size(char *arr);

int	str_size(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	ct_len(int size, int all_length, char **strs, int sep_size)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	all_length = -sep_size;
	while (i < size)
	{
		k = 0;
		while (strs[k])
		{
			all_length += (sep_size + str_size(strs[k]));
			k++;
		}
		i++;
	}
	return (all_length);
}

void	create_return(int size, char**strs, char*sep, char *ret)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			ret[k++] = strs[i][j];
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			ret[k++] = sep[j++];
		}
		i++;
	}
	ret[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		i;
	int		full_size;

	full_size = 0;
	if (size == 0)
	{	
		ret = (char *)malloc(1);
		ret[0] = '\0';
	}	
	else
	{
		i = str_size(sep);
		full_size = ct_len(size, full_size, strs, i);
		ret = (char *)malloc(sizeof(char) * full_size + 1);
		create_return(size, strs, sep, ret);
	}
	return (ret);
}
