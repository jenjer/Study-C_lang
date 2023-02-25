/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:23:33 by youngski          #+#    #+#             */
/*   Updated: 2023/02/25 21:47:19 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <memory.h>


typedef struct s_arg
{
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finished_eat_mu;
	pthread_mutex_t	finish_mu;
	int				philo_num;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			time_to_end;
	int				eat_times;
	int				finished_eat;
	int				finish;
	long			start_time;

}	t_arg;

typedef struct	s_philo
{
	t_arg			*arg;
	pthread_mutex_t	last_eat_time_mu;
	int				id;
	int				left;
	int				right;
	long			last_eat_time;
	int				eat_count;
	pthread_t		thread;
}	t_philo;

void			ft_pass_time(long long wait_time, t_arg *arg);
int				ft_philo_printf(t_arg *arg, int id, char *msg);
int				ft_philo_action(t_arg *arg, t_philo *philo);
void			*ft_thread(void *argv);
int				ft_philo_start(t_arg *arg, t_philo *philo);
void			ft_philo_check_finish(t_arg *arg, t_philo *philo);
int				ft_arg_init_mutex(t_arg *arg);
int				ft_arg_init(t_arg *arg, int argc, char *argv[]);
int				ft_philo_init(t_philo **philo, t_arg *arg);
unsigned long	ft_get_time(void);
void			ft_free_thread(t_arg *arg, t_philo *philo);

int				print_error(char *msg, int num);
int				time_check(t_arg *arg);

int				ft_atoi(const char *str);


#endif
