/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:19:07 by youngski          #+#    #+#             */
/*   Updated: 2023/01/16 16:43:26 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

int	first_child_work(t_data data, int *pipes)
{
	int		fd;
	t_data	cp_data;

	cp_data.s_argc = data.s_argc;
	cp_data.s_argv = data.s_argv;
	cp_data.s_envp = data.s_envp;
	if (child_data_setting(&cp_data))
		return (0);
	make_orders_options(&cp_data);
	fd = open(data.s_argv[1], O_RDONLY);
	if (fd <= 0)
	{
		msg_error("fail to file open");
		exit(0);
	}
	dup2(fd, 0);
	close(fd);
	dup2(pipes[1], 1);
	close(pipes[1]);
	close(pipes[0]);
	execve(cp_data.order[0], cp_data.options[0], data.s_envp);
	return (1);
}

int	last_child_work(t_data data, int *pipes, int i)
{
	int		fd_write;
	t_data	cp_data;
	char	*t;

	i--;
	cp_data.s_argc = data.s_argc;
	cp_data.s_argv = data.s_argv;
	cp_data.s_envp = data.s_envp;
	if (child_data_setting(&cp_data))
		return (0);
	make_orders_options(&cp_data);
	t = data.s_argv[data.s_argc - 1];
	fd_write = open(t, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_write <= 0)
		return (0);
	close(pipes[1]);
	dup2(fd_write, 1);
	close(pipes[0]);
	execve(cp_data.order[i], cp_data.options[i], data.s_envp);
	return (1);
}

void	keep_stdio(int *origin_fd)
{
	origin_fd[0] = dup(STDIN_FILENO);
	origin_fd[1] = dup(STDOUT_FILENO);
}

int	err_data_setting(t_data *data, int argc, char **argv, char **envp)
{
	data->s_argc = argc;
	data->s_argv = argv;
	data->s_envp = envp;
	data->pid_data = (int *)malloc(sizeof(int *) * argc -3);
	if (!(data->pid_data))
		return (0);
	return (1);
}

int	main(int argc, char *argv[], char **envp)
{
	int		k;
	int		j;
	t_data	data;

	j = 2;
	if (argc < 4)
	{
		ft_printf("check argument number\n");
		return (0);
	}
	if (!err_data_setting(&data, argc, argv, envp))
		return (0);
	k = 0;
	while (++k <= argc -3)
	{
		if (!init_fork(&data, j++, k))
			return (0);
	}
	waitpid(data.pid, NULL, 0);
	k = 2;
	while (++k < argc - 1)
		wait(0);
	free(data.pid_data);
	return (0);
}
