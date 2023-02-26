/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:36:36 by youngski          #+#    #+#             */
/*   Updated: 2023/02/26 18:31:36 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_pass_time(long long wait_time, t_arg *arg)
{
	long long	start;
	long long	now;

	start = ft_get_time();
	while (arg_fin_check(arg) == 1)
	{
		now = ft_get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
}

int	ft_philo_printf(t_arg *arg, int id, char *msg)
{
	long long	now;

	now = ft_get_time();
	if (now == -1)
	{
		return (-1);
	}
	pthread_mutex_lock(&(arg->print));
	if (arg_fin_check(arg) == 1)
		printf("%lld %d %s \n", now - arg->start_time, id + 1, msg);
	pthread_mutex_unlock(&(arg->print));
	return (0);
}

int	ft_philo_action(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left]));
	ft_philo_printf(arg, philo->id, "has token a left fork");
	if (arg->philo_num != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->right]));
		ft_philo_printf(arg, philo->id, "has taken a right fork");
		ft_philo_printf(arg, philo->id, "is eating");
		pthread_mutex_lock(&(philo->last_eat_time_mu));
		philo->last_eat_time = ft_get_time();
		pthread_mutex_unlock(&(philo->last_eat_time_mu));
		philo->eat_count = philo->eat_count + 1;
		ft_pass_time((long long)arg->time_to_eat, arg);
		pthread_mutex_unlock(&(arg->forks[philo->right]));
	}
	pthread_mutex_unlock(&(arg->forks[philo->left]));
	return (0);
}

void	*ft_thread(void *argv)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = argv;
	arg = philo->arg;
	if (philo->id % 2)
		usleep(500);
	while (arg_fin_check(arg))
	{
		ft_philo_action(arg, philo);
		if (arg->eat_times == philo->eat_count)
		{
			pthread_mutex_lock(&(arg->finished_eat_mu));
			arg->finished_eat++;
			pthread_mutex_unlock(&(arg->finished_eat_mu));
			break ;
		}
		ft_philo_printf(arg, philo->id, "is sleeping");
		ft_pass_time((long long)arg->time_to_sleep, arg);
		ft_philo_printf(arg, philo->id, "is thinking");
	}
	return (0);
}

int	ft_philo_start(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < arg->philo_num)
	{
		pthread_mutex_lock(&(philo[i].last_eat_time_mu));
		philo[i].last_eat_time = ft_get_time();
		pthread_mutex_unlock(&(philo[i].last_eat_time_mu));
		if (pthread_create((&philo[i].thread), 0, ft_thread, &(philo[i])))
			return (1);
		i++;
	}
	ft_philo_check_finish(arg, philo, -1, 0);
	i = 0;
	while (i < arg->philo_num)
		pthread_join(philo[i++].thread, 0);
	ft_free_thread(arg, philo);
	return (0);
}
