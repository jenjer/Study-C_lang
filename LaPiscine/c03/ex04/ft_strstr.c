/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:52:19 by youngski          #+#    #+#             */
/*   Updated: 2022/09/03 22:04:59 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	k;
	int	flag;

	i = 0;
	k = 0;
	if (to_find == NULL)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i + k] == to_find[k])
		{
			while (str[i + k] == to_find[k])
			{
				if (to_find[k + 1] == '\0')
					return (str + i);
				k++;
			}
		}
		k = 0;
		i++;
	}
	return (NULL);
}
