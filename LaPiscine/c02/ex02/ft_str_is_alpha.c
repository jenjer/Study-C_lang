/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:47:36 by youngski          #+#    #+#             */
/*   Updated: 2022/08/31 14:20:09 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		ret;
	char	c;

	i = 0;
	ret = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c > 122 || (90 < c && 97 > c) || 65 > c)
			ret = 0;
		i++;
	}
	return (ret);
}
