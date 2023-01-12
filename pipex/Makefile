# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngski <youngski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 15:00:59 by youngski          #+#    #+#              #
#    Updated: 2023/01/12 15:13:29 by youngski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c pipex_utils.c
BONUSSRCS = ./bonus/main.c ./bonus/pipex_utils2.c ./bonus/pipex_utils.c

OBJS = ${SRCS:.c=.o}
BONUSOBJS = ${BONUSSRCS:.c=.o}

LIB_A = ./libft/libft.a
DEL_A = pipex.a
AR = ar
HEADER_D=-I./header
NAME = pipex
BONUS_NAME = pipex_bonus
CFLAGS = -Wall -Wextra -Werror


all : ${NAME}

${NAME} : ${LIB_A} ${OBJS}
	cp ${LIB_A} ./pipex.a
	${CC} ${CFLAGS} ${HEADER_D} ${OBJS} ${NAME}.a -o ${NAME} -g3

${LIB_A} :
	make -C  ./libft

%.o	:%.c
	${CC} ${HEADER_D} ${CFLAGS} -c $< -o $@



${BONUS_NAME} : ${BONUSOBJS} ${LIB_A}
	cp ${LIB_A} ./pipex.a
	${CC} ${CFLAGS} ${HEADER_D} ${BONUSOBJS} ${NAME}.a -o ${BONUS_NAME} -g3


bonus : ${BONUS_NAME}

clean :
	make  -C ./libft clean
	rm -f ${OBJS} ${BONUSOBJS} ${DEL_A}

fclean : clean
	make  -C ./libft fclean
	rm -f ${NAME} ${BONUS_NAME} ${BONUS_NAME}.a

re : 
	make fclean
	make all

.PHONY : fclean re all clean bonus
