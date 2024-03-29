/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:36:36 by youngski          #+#    #+#             */
/*   Updated: 2023/03/19 14:08:29 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_action(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left]));
	ft_philo_printf(arg, philo->id, "has token a left fork");
	if (arg->philo_num != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->right]));
		ft_philo_printf(arg, philo->id, "has taken a right fork");
		ft_philo_printf(arg, philo->id, "is eating");
		philo->eat_count = philo->eat_count + 1;
		pthread_mutex_lock(&(philo->last_eat_time_mu));
		philo->last_eat_time = ft_get_time();
		pthread_mutex_unlock(&(philo->last_eat_time_mu));
		ft_pass_time((long long)arg->time_to_eat, arg);
		pthread_mutex_lock(&(philo->last_eat_time_mu));
		pthread_mutex_unlock(&(philo->last_eat_time_mu));
	}
	else
	{
		make_while(arg);
		return (0);
	}
	pthread_mutex_unlock(&(arg->forks[philo->right]));
	pthread_mutex_unlock(&(arg->forks[philo->left]));
	return (0);
}

void	ft_last_philo_action(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->right]));
	ft_philo_printf(arg, philo->id, "has token a left fork");
	if (arg->philo_num != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->left]));
		ft_philo_printf(arg, philo->id, "has taken a right fork");
		ft_philo_printf(arg, philo->id, "is eating");
		pthread_mutex_lock(&(philo->last_eat_time_mu));
		philo->last_eat_time = ft_get_time();
		pthread_mutex_unlock(&(philo->last_eat_time_mu));
		philo->eat_count = philo->eat_count + 1;
		ft_pass_time((long long)arg->time_to_eat, arg);
	}
	pthread_mutex_unlock(&(arg->forks[philo->left]));
	pthread_mutex_unlock(&(arg->forks[philo->right]));
}

void	add_finished_eat(t_arg *arg)
{
	pthread_mutex_lock(&(arg->finished_eat_mu));
	arg->finished_eat++;
	pthread_mutex_unlock(&(arg->finished_eat_mu));
}

void	*ft_thread(void *argv)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = argv;
	arg = philo->arg;
	if (philo->id % 2 == 1)
		usleep(1000);
	pthread_mutex_lock(&(arg->start));
	pthread_mutex_unlock(&(arg->start));
	while (arg_fin_check(arg))
	{
		ft_philo_action(arg, philo);
		if (arg->eat_times == philo->eat_count)
		{
			pthread_mutex_lock(&(arg->finished_eat_mu));
			arg->finished_eat += 1;
			pthread_mutex_unlock(&(arg->finished_eat_mu));
			break ;
		}
		ft_philo_printf(arg, philo->id, "is sleeping");
		ft_pass_time((long)arg->time_to_sleep, arg);
		ft_philo_printf(arg, philo->id, "is thinking");
	}
	return (0);
}

int	ft_philo_start(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(arg->start));
	while (i < arg->philo_num)
	{
		pthread_mutex_lock(&(philo[i].last_eat_time_mu));
		philo[i].last_eat_time = ft_get_time();
		pthread_mutex_unlock(&(philo[i].last_eat_time_mu));
		if (pthread_create((&philo[i].thread), 0, ft_thread, &(philo[i])))
			return (1);
		i++;
	}
	pthread_mutex_unlock(&(arg->start));
	pthread_mutex_lock(&(arg->start));
	pthread_mutex_unlock(&(arg->start));
	ft_philo_check_finish(arg, philo, -1, 0);
	i = 0;
	while (i < arg->philo_num)
		pthread_join(philo[i++].thread, 0);
	ft_free_thread(arg, philo);
	return (0);
}
