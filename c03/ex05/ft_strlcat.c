/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:18:22 by youngski          #+#    #+#             */
/*   Updated: 2022/09/03 23:38:22 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	q;

	dest_len = 0;
	i = 0;
	src_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	q = dest_len;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[q] = src[i];
		i++;
		q++;
	}
	dest[dest_len] = '\0';
	if (size > dest_len)
		return (src_len + dest_len);
	else
		return (src_len + size);
}
