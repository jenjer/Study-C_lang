/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:02:23 by youngski          #+#    #+#             */
/*   Updated: 2023/01/16 11:02:33 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

int	msg_error(char *err)
{
	perror(err);
	return (0);
}
