/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:13:20 by youngski          #+#    #+#             */
/*   Updated: 2022/09/02 19:37:55 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				count_max(char *arr);

int	count_max(char *arr)
{
	int	i;

	i = 0;
	while (*(arr + i))
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	ret;
	unsigned int	i;

	ret = 0;
	i = 0;
	if (size < 1)
		return (count_max(src));
	while (i < size -1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count_max(src));
}
