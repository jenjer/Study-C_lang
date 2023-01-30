# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngski <youngski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 15:00:59 by youngski          #+#    #+#              #
#    Updated: 2023/01/28 15:18:07 by youngski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c setting_map.c error.c key_interupt.c clear_game.c

OBJS = ${SRCS:.c=.o}
LMLX = -lmlx -framework OpenGl -framework Appkit

LIB_A = ./libft/libft.a
DEL_A = solong.a
HEADER_D = -I./mlx
NAME = so_long
CFLAGS = -Wall -Wextra -Werror

all : ${NAME} ${OBJS}

${NAME} : ${OBJS} ${LIB_A}
	cp ${LIB_A} ./solong.a
	make all -C ./mlx
	${CC} ${CFLAGS} ${OBJS} ${LIB_A} ${LMLX} -o ${NAME} -g3

${LIB_A} :
	make -C ./libft

%.o	:%.c
	${CC} ${HEADER_D} ${CFLAGS} -c $< -o $@

clean :
	make -C ./libft clean
	rm ./libft/libft.a
	rm -f ${OBJS} ${DEL_A}

fclean : clean
	make -C ./libft fclean
	rm -f ${NAME}

re : 
	make fclean
	make all

.PHONY : fclean re all clean bonus
