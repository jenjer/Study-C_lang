/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:48:47 by gyopark           #+#    #+#             */
/*   Updated: 2023/02/20 15:25:02 by gyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_doc	*init_doc(t_doc *doc)
{
	doc->name = NULL;
	doc->count = 0;
	doc->limiters = NULL;
	doc->zero = 0;
	return (doc);
}

void	init_main(t_list **head, t_cover **cover, char **line, char ***envp)
{
	*head = 0;
	*line = 0;
	*cover = 0;
	init_env_list(*envp, head);
	*envp = make_envp_arr(*head, 0);
	*cover = init_cover(*cover);
	init_fd((*cover)->data);
}
