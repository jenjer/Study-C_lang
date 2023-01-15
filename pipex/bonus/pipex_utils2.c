/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:59:51 by youngski          #+#    #+#             */
/*   Updated: 2023/01/12 17:47:52 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex_bonus.h"

int	child_work(t_data data, int *pipes, int i)
{
    t_data  cp_data;

	i--;
    cp_data.s_argc = data.s_argc;
    cp_data.s_argv = data.s_argv;
    cp_data.s_envp = data.s_envp;
    if (child_data_setting(&cp_data))
        return (0);
    make_orders_options(&cp_data);
    dup2(pipes[1],1);
    close(pipes[1]);
    close(pipes[0]);
    execve(cp_data.order[i-1], cp_data.options[i-1], data.s_envp);
    return (1);
}
