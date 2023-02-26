/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:51:57 by youngski          #+#    #+#             */
/*   Updated: 2023/02/26 17:21:48 by youngski         ###   ########.fr       */
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
		return (0);
	}
	pthread_mutex_unlock(&(arg->finish_mu));
	return (0);
}

void	change_finish(t_arg *arg)
{
	pthread_mutex_lock(&(arg->finish_mu));
	arg->finish = 1;
	pthread_mutex_unlock(&(arg->finish_mu));
}
