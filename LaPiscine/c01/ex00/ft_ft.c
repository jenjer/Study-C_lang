/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 23:32:54 by youngski          #+#    #+#             */
/*   Updated: 2022/08/26 21:16:03 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
void	ft_ft(int *nbr);

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int main(){
	int k = 10;
	int *nbr = &k;
	printf("%d\n",k);
	ft_ft(nbr);
	printf("%d\n",k);
}
