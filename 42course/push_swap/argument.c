/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:26:31 by youngski          #+#    #+#             */
/*   Updated: 2023/01/01 19:37:03 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_number_right(long data, int *ret)
{
	if (data == 21474836999)
	{
		*ret = 0;
		return (1);
	}
	return (0);
}

void	make_root(t_list **root1, char ***argv_fin, int *ret, int i)
{
	long	data;
	int		k;

	while (argv_fin[++i] != 0)
	{
		k = 0;
		data = ft_atoi(argv_fin[i][k]);
		if (check_number_right(data, ret))
			return ;
		ft_lstadd_back(root1, ft_lstnew(ft_atoi(argv_fin[i][k++])));
		while (argv_fin[i][k])
		{
			data = ft_atoi(argv_fin[i][k]);
			if (check_number_right(data, ret))
				return ;
			ft_lstadd_back(root1, ft_lstnew(ft_atoi(argv_fin[i][k++])));
			*ret += 1;
		}
		*ret += 1;
	}	
}

void	free_lot_pointer(char ***argv_fin)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (argv_fin[i])
	{
		k = 0;
		while (argv_fin[i][k])
			free(argv_fin[i][k++]);
		free(argv_fin[i]);
		i++;
	}
}

int	argument_setting(int argc, char *argv[], t_list **root1, int ret)
{
	char	***argv_fin;
	int		i;

	argv++;
	i = -1;
	argv_fin = (char ***)malloc(sizeof(char **) * argc);
	if (!argv_fin)
		return (0);
	argv_fin[argc -1] = 0;
	while (++i < argc -1)
	{
		argv_fin[i] = ft_split(argv[i], ' ');
		if (argv_fin[i][0] == NULL)
		{
			ret = 0;
			free_lot_pointer(argv_fin);
			free(argv_fin);
			return (0);
		}
	}
	make_root(root1, argv_fin, &ret, -1);
	free_lot_pointer(argv_fin);
	free(argv_fin);
	return (ret);
}

int	null_argv_check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i])
			return (1);
		i++;
	}
	if (argv[i][0] == 0)
		return (1);
	return (0);
}
