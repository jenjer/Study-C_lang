# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngski <youngski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 15:00:59 by youngski          #+#    #+#              #
#    Updated: 2022/12/24 19:17:46 by youngski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c push_swap_util.c sorting.c function_2.c function_1.c main.c algorithm.c  function_3.c algorithm2.c
BONUSSRCS = push_swap_bonus.c
OBJS = ${SRCS:.c=.o}
LIB_A = ./libft/libft.a
DEL_A = push_swap.a
AR = ar
HEADER_D=-I./header

BONUSOBJS = ${BONUSSRCS:.c=.o}

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${LIB_A} ${OBJS}
	cp ${LIB_A} ./push_swap.a
	${CC} ${CFLAGS} ${HEADER_D} ${OBJS} ${NAME}.a -o ${NAME} -g3

%.o	:%.c
	${CC} ${HEADER_D} ${CFLAGS} -c $< -o $@

${LIB_A} :
	make -C  ./libft

bonus : ${BONUSOBJS}
	@make OBJS="${BONUSOBJS}"

clean :
	make  -C ./libft clean
	rm -f ${OBJS} ${BONUSOBJS} ${DEL_A}

fclean : clean
	make  -C ./libft fclean
	rm -f ${NAME}

re : fclean all

.PHONY : fclean re all clean bonus
