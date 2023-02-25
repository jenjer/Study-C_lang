/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:51:57 by youngski          #+#    #+#             */
/*   Updated: 2023/02/25 21:54:25 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_fin_check(t_arg *arg)
{
	pthread_mutex_lock(&(arg->finish_mu));
	if (!arg->finish)
	{
		pthread_mutex_unlock(&(arg->finish_mu));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(arg->finish_mu));
		return (2);
	}
	return (2);
}
