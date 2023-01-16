/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:19:34 by youngski          #+#    #+#             */
/*   Updated: 2023/01/16 11:27:46 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_data
{
	int		s_argc;
	char	**s_argv;
	char	**s_envp;
	int		*pipe;
	int		pid;
	char	**order;
	char	***options;
	int		*pid_data;
}				t_data;

void	do_run_write(char *argv[], char **envp);
int		first_open(char **argv);
int		final_open(char **argv);
char	*find_path(char *argv[], char **envp, int i);
int		init_fork(t_data *data, int i);
void	make_orders_options(t_data *data);
int		first_child_work(t_data data, int *pipe);
int		last_child_work(t_data data, int *pipe);
int		child_data_setting(t_data *data);
int		child_work(t_data data, int *pipes, int i);
int		msg(char *err);
int		msg_error(char *err);

#endif
