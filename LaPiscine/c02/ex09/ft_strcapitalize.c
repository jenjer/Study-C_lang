/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:12:39 by youngski          #+#    #+#             */
/*   Updated: 2022/09/02 22:26:05 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	tf;

	i = 0;
	tf = 1;
	while (str[i] != '\0')
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] = str[i] + 32;
		if (tf == 1 && str[i] <= 'z' && str[i] >= 'a')
		{
			str[i] = str[i] - 32;
			tf = 0;
		}
		else if (32 > str[i] || (str[i] < 91 && str[i] > 64))
		{
			tf = 0;
		}
		else if (47 < str[i] && 58 > str[i])
			tf = 0;
		else if (!(str[i] <= 'z' && str[i] >= 'a'))
			tf = 1;
		i++;
	}
	return (str);
}
