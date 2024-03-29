/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:08:16 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/22 14:28:23 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_str_space(char *line)
{
	while (*line)
	{
		if (*line != 32 && !(*line >= 9 && *line <= 13))
			return (0);
		line++;
	}
	return (1);
}

int	do_builtin(t_cover *cover, t_list *head, char **envp)
{
	int		ret;

	ret = 0;
	cover->temp = cover->head;
	cover->builtin = read_cmd(cover->data, &(cover->temp), \
	&(cover->doc->zero));
	dup_pipes(NULL, cover->data->io_fd, cover->data);
	if (check_made_builtin(cover->builtin))
	{
		if (check_builtin(cover->builtin, head, envp) >= 0)
		{
			ret = -1;
		}
	}
	free_spl(cover->builtin);
	dup2(cover->data->io_fd[1], 1);
	close(cover->data->io_fd[1]);
	if (ret == -1)
		free(cover->data->pid);
	return (ret);
}

int	doc_check(t_cover *cover, char *line)
{
	int	doc;

	doc = doc_syntax(line);
	if (doc == -1)
		return (syntax_err());
	if (doc == 1)
	{
		doc = open_heredoc(cover->doc, line);
		if (doc == -1)
			return (-1);
		return (doc);
	}
	return (doc);
}

int	handle_line(char *line, t_cover *cover, char **envp, t_list *head)
{
	int		doc;

	doc = doc_check(cover, line);
	if (doc == -1)
		return (-1);
	else if (doc == 2)
		return (-1);
	else if (doc == 3)
		return (-1);
	cover->head = go_tokenize(line, envp, &(cover->head));
	if (cover->head == NULL)
		return (-1);
	if (check_syntax(cover->head) == -1)
		return (-1);
	if (cover->head->cmds == 1)
		get_rid_null_node(&(cover->head));
	if (cover->head->next == NULL)
		return (g_exit_code);
	init_data(cover->data, *(cover->doc), envp, cover->head);
	if (cover->head->cmds == 1)
		if (do_builtin(cover, head, envp) == -1)
			return (-1);
	g_exit_code = pipe_line(*(cover->data), cover->head, *cover, head);
	set_signal(SHE, SHE);
	return (g_exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	char				*line;
	t_cover				*cover;
	struct termios		term;
	t_list				*head;

	init_main(&head, &cover, &line, &envp);
	tcgetattr(STDIN_FILENO, &term);
	init_prompt_sig(argc, argv);
	while (1)
	{
		line = init_line(line);
		if (*line != '\0' && !is_str_space(line))
			handle_line(line, cover, envp, head);
		free_spl(envp);
		envp = make_envp_arr(head, 0);
		if (cover->doc->name)
		{
			free_spl(cover->doc->name);
			cover->doc->name = NULL;
		}
		free(line);
		dup2(cover->cp_stdout, 1);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	return (g_exit_code);
}
