/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:32:23 by youngski          #+#    #+#             */
/*   Updated: 2022/09/01 01:07:54 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	if (str[0] == '\0')
		ret = 1;
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
			ret = 0;
		i++;
	}
	return (ret);
}
