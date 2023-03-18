/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:22:50 by youngski          #+#    #+#             */
/*   Updated: 2023/03/18 18:10:46 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnum(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			;
		else
			return (1);
		i++;
	}
	return (0);
}

int	check_arg(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isnum(argv[i]))
		{
			printf("%s\n", argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_philo	*philo;
	int		error;

	if (argc != 5 && argc != 6)
		return (print_error("error argc", 3));
	if (check_arg(argv))
		return (print_error("error argv", 3));
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
