/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:19:04 by youngski          #+#    #+#             */
/*   Updated: 2022/12/30 17:03:25 by youngski         ###   ########.fr       */
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

void	sa_b(t_list **root1);
void	sb_b(t_list **root2);
void	ss_b(t_list **root1, t_list **root2);
void	pb_b(t_list **root1, t_list **root2);
void	pa_b(t_list **root1, t_list **root2);
void	ra_b(t_list **root1);
void	rb_b(t_list **root2);

void	rra_b(t_list **root1);
void	rrb_b(t_list **root2);
void	rrr_b(t_list **root1, t_list **root2);
void	rr_b(t_list **root1, t_list **root2);

void	rra(t_list **root1, int flag);
void	rrb(t_list **root2, int flag);
void	rrr(t_list **root1, t_list **root2);
void	rr(t_list **root1, t_list **root2);
void	make_list_index(t_list *root1, int *arr, int size);
void	hard_coding(t_list **root1, t_list **root2, int size);

int		push_swap(int argc, char *argv[]);
int		*bubble_sort(int *arr, int size);
int		do_run(t_list **root1, int argc, int flag);
int		make_ans(t_list **root1, int size);
int		*make_arr(t_list *root);
int		find_large_sorted(int *arr);
int		check_five(t_list *root1);
int		find_small(t_list *root1, int size);
int		overlaped(t_list *root);
int		max(char *str);
int		find_argc(char **argv);

void	sort_num_5(t_list **root1, t_list **root2, int size);
void	sort_num_4(t_list **root1, t_list **root2, int size);
void	sort_num_3(t_list **root1, int large);
void	sort_all(t_list **root1, t_list **root2, int size);
void	move_b(t_list **root1, t_list **root2, int size, int num);
void	move_a(t_list **root1, t_list **root2, int size);
void	show_leaks(void);
void	checker_split(int *i, int *flag, int *argc, char ***argv);
void	split_run(int argc, char **argv, t_list **root1);

int		argument_setting(int argc, char *argv[], t_list **root1, int ret);
int		null_argv_check(int argc, char **argv);

#endif
