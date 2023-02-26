/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:51:57 by youngski          #+#    #+#             */
/*   Updated: 2023/02/26 21:20:32 by youngski         ###   ########.fr       */
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

void    ft_pass_time(long wait_time, t_arg *arg)
{
    long    start;
    long    now;

    start = ft_get_time();
    while (arg_fin_check(arg) == 1)
    {
        now = ft_get_time();
        if ((now - start) >= wait_time)
            break ;
        usleep(1000);
    }
}

int ft_philo_printf(t_arg *arg, int id, char *msg)
{
    long    now;

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
