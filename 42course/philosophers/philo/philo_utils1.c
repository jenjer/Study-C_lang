/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:36:04 by youngski          #+#    #+#             */
/*   Updated: 2023/02/26 22:43:55 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_check_finish(t_arg *arg, t_philo *philo, int i, long now)
{
	while (arg_fin_check(arg))
	{
		pthread_mutex_lock(&(arg->finished_eat_mu));
		if (((arg->eat_times != 0) && (arg->philo_num == arg->finished_eat)))
		{
			change_finish(arg);
			break ;
		}
		pthread_mutex_unlock(&(arg->finished_eat_mu));
		i = -1;
		while (++i < arg->philo_num)
		{
			pthread_mutex_lock(&(philo[i].last_eat_time_mu));
			now = ft_get_time();
			if (((now - philo[i].last_eat_time) > arg->time_to_die))
			{
				pthread_mutex_unlock(&(philo[i].last_eat_time_mu));
				ft_philo_printf(arg, i, "died\n");
				change_finish(arg);
				break ;
			}
			pthread_mutex_unlock(&(philo[i].last_eat_time_mu));
		}
	}
	pthread_mutex_unlock(&(arg->finish_mu));
}

int	ft_arg_init_mutex(t_arg *arg)
{
	int	i;

	if (pthread_mutex_init(&(arg->print), 0) || \
			pthread_mutex_init(&(arg->finish_mu), 0) \
			|| pthread_mutex_init(&(arg->finished_eat_mu), 0))
		return (1);
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->philo_num);
	if (!(arg->forks))
		return (1);
	i = 0;
	while (i < arg->philo_num)
	{
		if (pthread_mutex_init(&(arg->forks[i]), 0))
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_thread(t_arg *arg, t_philo *philo)
{
	free(arg->forks);
	if (philo)
		free(philo);
}

unsigned long	ft_get_time(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, 0);
	return ((mytime.tv_sec * (unsigned long)1000) + (mytime.tv_usec / 1000));
}

int	time_check(t_arg *arg)
{
	unsigned long	now;

	now = ft_get_time();
	if (now - arg->start_time >= (unsigned long)arg->time_to_die)
	{
		ft_philo_printf(arg, -2, "time to die");
		return (1);
	}
	return (0);
}
