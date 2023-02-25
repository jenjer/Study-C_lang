/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:36:04 by youngski          #+#    #+#             */
/*   Updated: 2023/02/25 12:08:34 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_check_finish(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	now;

	while (!arg->finish)
	{
		if ((arg->eat_times != 0) && (arg->philo_num == arg->finished_eat))
		{
			arg->finish = 1;
			break ;
		}
		i = 0;
		while (i < arg->philo_num)
		{
			now = ft_get_time();
			if ((now - philo[i].last_eat_time) >= arg->time_to_die)
			{
				ft_philo_printf(arg, i, "died");
				arg->finish = 1;
				break ;
			}
			i++;
		}
	}
}

int	ft_arg_init_mutex(t_arg *arg)
{
	int	i;

	if (pthread_mutex_init(&(arg->print), 0))
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
	free(arg);
	free(philo);
}

unsigned long	ft_get_time(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, 0);
	return ((mytime.tv_sec * (unsigned long)1000)\
			+ (mytime.tv_usec / 100));
}
