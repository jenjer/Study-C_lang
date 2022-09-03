/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:43:45 by youngski          #+#    #+#             */
/*   Updated: 2022/08/25 14:45:58 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ft_print_comb(void)
{
	char	mynum[3];
	char	comma[2];

	mynum[0] = '0';
	mynum[1] = '1';
	mynum[2] = '2';
	comma[0] = ',';
	comma[1] = ' ';
	while (mynum[0] <= '7')
	{
		while (mynum[1] <= '8')
		{	
			while (mynum[2] <= '9')
			{
				write(1, &mynum, 3);
				if (mynum[0] != '7' || mynum[1] != '8' || mynum[2] != '9')
					write(1, &comma, 2);
				mynum[2]++;
			}
			mynum[1]++;
			mynum[2] = mynum[1] +1;
		}
		mynum[1] = mynum[0] + 1;
		mynum[0]++;
	}
}
