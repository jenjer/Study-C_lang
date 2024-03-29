/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:03:57 by youngski          #+#    #+#             */
/*   Updated: 2023/02/20 15:26:12 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_path_gone(char **path)
{
	if (path && path[0] != NULL)
		return (1);
	return (0);
}

char	**get_path(char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH", 4))
		envp++;
	if (!*envp)
		return (0);
	return (ft_split(*envp + 5, ':'));
}

int	is_file_directory(char *cmd)
{
	struct stat	file_info;

	if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "/", 1) == 0)
	{
		if (lstat(cmd, &file_info) < 0)
			exit_error(cmd, 0, 1);
		else if (S_ISDIR(file_info.st_mode))
		{
			ft_putstr_fd(cmd, 2);
			write(2, ": ", 2);
			ft_putstr_fd("is a directory\n", 2);
			exit (126);
		}
	}
	return (0);
}

int	find_cmd(char **path, char *path_cmd)
{
	int			i;
	char		*tmp;
	int			fd;
	struct stat	file_info;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], path_cmd);
		fd = access(tmp, X_OK);
		lstat(tmp, &file_info);
		if (fd != -1 && !S_ISDIR(file_info.st_mode))
		{
			free(path_cmd);
			return (1);
		}
		close(fd);
		free(tmp);
	}
	free(path_cmd);
	return (0);
}

int	check_command(char **path, char *cmd)
{
	char		*path_cmd;

	is_file_directory(cmd);
	if (access(cmd, X_OK) != -1)
		return (1);
	if (!path)
	{
		ft_putstr_fd(cmd, 2);
		write(2, ": ", 2);
		ft_putstr_fd("No such file or directory\n", 2);
		g_exit_code = 127;
		exit (127);
	}
	path_cmd = ft_strjoin("/", cmd);
	if (find_cmd(path, path_cmd) == 1)
		return (1);
	return (0);
}
