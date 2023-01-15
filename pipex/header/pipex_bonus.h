/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:15:43 by youngski          #+#    #+#             */
/*   Updated: 2023/01/12 15:16:35 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct  s_data
{
    int s_argc;
    char **s_argv;
    char **s_envp;
    int *pipe;
    int pid;
    char **order;
    char ***options;
    int *pid_data;
}               t_data;

void    do_run_write(char *argv[], char **envp);
int     first_open(char **argv);
int     final_open(char **argv);
//int       fork_thing(char *argv[], char **envp, int fd, int i);
char    *find_path(char *argv[], char **envp, int i);
int     init_fork(t_data *data, int i, int k);
void    make_orders_options(t_data *data);
int     first_child_work(t_data data, int *pipe);
int     last_child_work(t_data data, int *pipe, int i);
int     child_data_setting(t_data *data);
int     child_work(t_data data, int *pipes, int i);



#endif
