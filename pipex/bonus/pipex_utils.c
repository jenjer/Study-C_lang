/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:24:30 by youngski          #+#    #+#             */
/*   Updated: 2023/01/12 18:52:43 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

int	final_open(char **argv)
{
	int	fd;

    fd = open(argv[4], O_WRONLY);
    if (fd < 0)
        ft_printf("fail to file open");
    return (fd);	
}

int child_data_setting(t_data *data)
{
    data->options = (char ***)malloc(sizeof(char **) * (data->s_argc - 3));
    if (data->options == 0)
      return (1);
    data->order = (char **)malloc(sizeof(char *) * (data->s_argc -3));
    if (data ->order == 0)
      return (1);
	return (0);
}

char	*find_path(char *argv[], char **envp, int i)
{
	int		k;
	char	**str;
	char	*sp_path;
	char	**temp;

	k = -1;
	while (envp[++k])
	{
		if (!ft_strncmp("PATH", envp[k], 4))
			break ;
	}
	str = ft_split(envp[k] + 5, ':');
	argv[i] = ft_strjoin("/", argv[i]);
	k = -1;
	while (str[++k])
	{
		temp = ft_split(argv[i], ' ');
		sp_path = ft_strjoin(str[k], temp[0]);
		if (access(sp_path, X_OK) == 0 )
			break;
	}
	if (access(sp_path, X_OK) == 0)
		return (sp_path);
	else
		return (0);
}

int	init_fork(t_data *data, int i, int k)
{
	int pipes[2];

	pipe(pipes);
	if (pipes[0] == -1 || pipes[1] == -1)
		return (0);
	data->pid = fork();
	if (data->pid == -1)
		return (0);
	else if (data->pid == 0)
	{
		if (i == 2)
			first_child_work(*data, pipes);
		else if (i == data->s_argc - 2)
			last_child_work(*data, pipes, k);
		else  
			child_work(*data, pipes, i);
	}
	else if (data->pid != 0)
	{
		dup2(pipes[0], 0);
		close(pipes[0]);
		close(pipes[1]);
	}
	return (1);
}

void	make_orders_options(t_data *data)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (++i < data->s_argc - 1)
	{
		data->order[k++] = find_path(data->s_argv, data->s_envp, i);

	}
	i = 1;
	k = 0;
	while (++i < data->s_argc - 1)
		data->options[k++] = ft_split(data->s_argv[i], ' ');
}
