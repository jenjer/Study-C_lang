# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 15:00:01 by youngski          #+#    #+#              #
#    Updated: 2023/02/24 15:50:23 by youngski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c error.c init_func.c philo_utils.c philo_utils1.c ft_atoi.c
OBJS = ${SRCS:.c=.o}
AR = ar

NAME = philo

CFLAGS = -Wall -Wextra -Werror -g3 -pthread

all : ${NAME}

${NAME} : ${OBJS}
	${AR} -cr ${NAME} ${OBJS}

%.o	:%.c
	${CC} ${CFLAGS} -c $< -o $@ 

clean :
	rm -f ${OBJS} ${BONUSOBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : fclean re all clean
