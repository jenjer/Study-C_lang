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
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		count_length(int size, int all_length, char *seq);
int		str_size(char *arr);
char	*ft_strcpy(char *dest, char *src);

int	str_size(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	ct_len(int size, char **strs, int sep_size)
{
	int	i;
	int	all_length;
	
	i = 0;
	all_length = -sep_size;
	while (i < size)
	{
		all_length += (sep_size + str_size(strs[i]));
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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		full_size;

	full_size = 0;
	if (size == 0)
	{	
		ret = (char *)malloc(1);
		return (ret);
	}	
	full_size = ct_len(size, strs, str_size(sep));
	ret = malloc(sizeof(char) * full_size + 1);
	if (ret == NULL)
	{
		return (0);
	}
	create_return(size, strs, sep, ret);
	return (ret);
}
int	main(void)
{
	int		index;
	char	**strs;
	char	*sep;
	char	*result;
	int	size;

	size = 3;
	strs = (char **)malloc(3 * sizeof(char *));
	strs[0] = (char *)malloc(sizeof(char) * 5 + 1);
	strs[1] = (char *)malloc(sizeof(char) * 7 + 1);
	strs[2] = (char *)malloc(sizeof(char) * 14 + 1);
	strs[0] = "Hello";
	strs[1] = "";
	strs[2] = "world";
	sep = " ";
	result = ft_strjoin(size, strs, sep);
	printf("%s$\n", result);
	free(result);
}
	
