/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:11:46 by youngski          #+#    #+#             */
/*   Updated: 2022/11/30 17:35:08 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		print_decimal(va_list ap);
int		print_udecimal(va_list ap);
int		print_hex(va_list ap, int flag);
char	*make_hex(size_t temp, char *hex);
int		ft_printf(const char *str, ...);

#endif
