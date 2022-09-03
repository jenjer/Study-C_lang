/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:01:38 by youngski          #+#    #+#             */
/*   Updated: 2022/09/01 01:08:19 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	if (str[0] == '\0')
		return (ret);
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
			ret = 0;
		i++;
	}
	return (ret);
}
