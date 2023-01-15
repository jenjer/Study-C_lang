/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:16:09 by youngski          #+#    #+#             */
/*   Updated: 2022/12/28 21:21:57 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i] && s2[i] && s2[i] == s1[i])
	{
		i++;
	}
	k = s1[i] - s2[i];
	if (k == 0)
		return (1);
	else
		return (0);
}
