# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 11:03:41 by youngski          #+#    #+#              #
#    Updated: 2023/03/18 19:29:07 by youngski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c error.c init_func.c philo_utils.c philo_utils1.c ft_atoi.c \
	   philo_utils2.c
OBJS = ${SRCS:.c=.o}

BONUSOBJS = ${BONUSSRCS:.c=.o}

NAME = philo

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} 

%.o	:%.c
	${CC} ${CFLAGS} -c $< -o $@ 

bonus : ${BONUSOBJS}
	@make OBJS="${BONUSOBJS}"

clean :
	rm -f ${OBJS} ${BONUSOBJS}

fclean : clean
	rm -f ${NAME}

re : 
	make fclean
	make all

.PHONY : fclean re all clean bonus 
