/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:51:23 by youngski          #+#    #+#             */
/*   Updated: 2022/12/09 22:52:59 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MALLOC_H
#define MY_MALLOC_H

# include <stdlib.h>

int	my_hash(char *t);
void	**make_buffer(void ***temp);
void	del_malloc(void *temp, int flag);
void	delete_all(void ***buffer, int size);
void	*my_malloc(int size);
void	delete_temp(void ***buffer, void *temp);

#endif

