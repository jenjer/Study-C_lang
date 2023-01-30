# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 17:16:06 by youngski          #+#    #+#              #
#    Updated: 2022/11/30 20:26:39 by youngski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_util.c ./libft/ft_strdup.c ./libft/ft_strlen.c ./libft/ft_strlcpy.c ./libft/ft_itoa.c
OBJS = ${SRCS:.c=.o}
AR = ar


NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
	${AR} -cr ${NAME} ${OBJS}

%.o	:%.c
	${CC} ${CFLAGS} -c $< -o $@ 

clean :
	rm -f ${OBJS} 

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : fclean re all clean  
