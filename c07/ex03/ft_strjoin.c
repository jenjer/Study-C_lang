/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:42:20 by youngski          #+#    #+#             */
/*   Updated: 2022/09/11 01:31:59 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ct_len(int size, int all_length, char **strs, int sep_size)
{
	int	i;
	int k;

	k = 0;
	i = 0;
	all_length = -sep_size;
	while (i < size)
	{
		while (strs[k])
		{
			all_length += (sep_size + str_size(strs))
			k++;
		}
		i++;
	}
	return (all_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	k;
	int all_length;
	char *ret;
	int sep_len;

	if (size == 0)
	{
		ret = malloc(1);
		return (ret);
	}	
	sep_len = str_size(sep);
	i = 0;
	all_lenght = ct_len(size, all_length, strs, sep_len) + 1
	ret = malloc(sizeof(char *)*ct_len(size, all_length, strs, sep_len) + 1);
	while (i < size)
	{
		k = 0;
		while (strs[i][k])
		{
			ret[k] 
		}


		i++;
	}

	



	

}
