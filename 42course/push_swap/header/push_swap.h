/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:19:04 by youngski          #+#    #+#             */
/*   Updated: 2022/12/27 12:53:18 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	sa(t_list *root1, int flag);
void	sb(t_list *root2, int flag);
void	ss(t_list *root1, t_list *root2);
void	pb(t_list **root1, t_list **root2);
void	pa(t_list **root1, t_list **root2);
void	ra(t_list **root1, int flag);
void	rb(t_list **root2, int flag);

void	rra(t_list **root1, int flag);
void	rrb(t_list **root2, int flag);
void	rrr(t_list **root1, t_list **root2);
void	rr(t_list **root1, t_list **root2);
void	make_list_index(t_list *root1, int *arr, int size);
void	hard_coding(t_list **root1, t_list **root2, int size);

int		push_swap(int argc, char *argv[]);
int		*bubble_sort(int *arr, int size);
int		do_run(t_list *root1, int argc);
int		make_ans(t_list **root1, int size);
int		*make_arr(t_list *root);
int		find_large_sorted(int *arr);
int		check_five(t_list *root1);
int		find_small(t_list *root1, int size);

void	sort_num_5(t_list **root1, t_list **root2, int size);
void	sort_num_4(t_list **root1, t_list **root2, int size);
void	sort_num_3(t_list **root1, int large);
void	sort_all(t_list **root1, t_list **root2, int size);
void	move_b(t_list **root1, t_list **root2, int size);

#endif
