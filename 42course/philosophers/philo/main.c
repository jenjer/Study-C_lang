/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:22:50 by youngski          #+#    #+#             */
/*   Updated: 2023/02/26 14:24:32 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_philo	*philo;
	int		error;

	if (argc != 5 && argc != 6)
		return (print_error("error argc", 3));
	error = ft_arg_init(&arg, argc, argv);
	if (error)
		return (print_error("error arg init", error));
	error = ft_philo_init(&philo, &arg);
	if (error)
		return (print_error("error philo init", error));
	error = ft_philo_start(&arg, philo);
	if (error)
		return (print_error("error philo start", error));
	return (0);
}
