/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:50:23 by youngski          #+#    #+#             */
/*   Updated: 2022/09/10 21:03:35 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H 

# include <unistd.h>

typedef int	t_bool;
void	ft_putchar(char *str);
t_bool	ft_is_even(int nbr);

# define EVEN(n) n % 2 == 0
# define FALSE 0
# define TRUE 1
# define EVEN_MSG  "I have an even number of arguments.\n"
# define ODD_MSG  "I have and odd number of arguments.\n"
# define SUCCESS  TRUE

#endif
