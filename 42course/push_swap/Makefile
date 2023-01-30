# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngski <youngski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 15:00:59 by youngski          #+#    #+#              #
#    Updated: 2022/12/30 22:06:33 by youngski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c push_swap_util.c sorting.c function_2.c function_1.c main.c algorithm.c  function_3.c algorithm2.c bonusf_3.c argument.c
BONUSSRCS = checker_main.c push_swap.c push_swap_util.c sorting.c algorithm.c algorithm2.c bonusf_1.c bonusf_2.c bonusf_3.c function_2.c function_1.c function_3.c argument.c

OBJS = ${SRCS:.c=.o}
BONUSOBJS = ${BONUSSRCS:.c=.o}

LIB_A = ./libft/libft.a
DEL_A = push_swap.a
AR = ar
HEADER_D=-I./header
NAME = push_swap
BONUS_NAME = checker
CFLAGS = -Wall -Wextra -Werror
BONUS_AR = checker.a

all : ${NAME}

${NAME} : ${LIB_A} ${OBJS}
	cp ${LIB_A} ./push_swap.a
	${CC} ${CFLAGS} ${HEADER_D} ${OBJS} ${NAME}.a -o ${NAME} -g3

${LIB_A} :
	make -C  ./libft

%.o	:%.c
	${CC} ${HEADER_D} ${CFLAGS} -c $< -o $@



${BONUS_AR} : ${LIB_A}
	cp ${LIB_A} ./checker.a

${BONUS_} : ${LIB_A} 

${BONUS_NAME} : ${BONUS_}
	${CC} ${CFLAGS} ${HEADER_D} ${BONUSOBJS} ${BONUS_AR} -o ${BONUS_NAME} -g3


bonus : ${BONUSOBJS} ${BONUS_AR} ${BONUS_NAME} 

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
