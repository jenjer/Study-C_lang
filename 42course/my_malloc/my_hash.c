/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:13:28 by youngski          #+#    #+#             */
/*   Updated: 2022/12/09 23:15:28 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int my_hash(char *t)
{
	int	i;

	i = 0;
	while (*t)
	{
		i = *t;
		t++;
	}
	return (i);
}
