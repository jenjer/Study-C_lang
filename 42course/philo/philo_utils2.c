/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:51:57 by youngski          #+#    #+#             */
/*   Updated: 2023/03/18 19:25:20 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_died_in_func(t_philo *philo, t_arg *arg, int i, long now)
{
	if (((now - philo[i].last_eat_time) > arg->time_to_die) && !arg->finish)
		return (1);
	else
		return (0);
	return (0);
}

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

void	ft_pass_time(long wait_time, t_arg *arg)
{
	long	start;
	long	now;
	int		count;

	start = ft_get_time();
	while (arg_fin_check(arg) == 1)
	{
		count = 0;
		now = ft_get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(100);
	}
}

int	ft_philo_printf(t_arg *arg, int id, char *msg)
{
	long	now;

	now = ft_get_time();
	if (now == -1)
	{
		return (-1);
	}
	pthread_mutex_lock(&(arg->print));
	if (arg_fin_check(arg) == 1)
		printf("%lu %d %s \n", now - arg->start_time, id + 1, msg);
	pthread_mutex_unlock(&(arg->print));
	return (0);
}
