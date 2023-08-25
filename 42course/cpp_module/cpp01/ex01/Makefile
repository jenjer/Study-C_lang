# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 18:14:08 by youngski          #+#    #+#              #
#    Updated: 2023/08/23 15:55:41 by youngski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS = ${SRCS:.cpp=.o}
CXX = c++ 

NAME = ex01

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : ${NAME}

${NAME} : ${OBJS}
	${CXX}  -o ${NAME} ${OBJS} ${CFLAGS}

%.o	:%.cpp
	${CXX} ${CPPFLAGS} -c $< -o $@ 

clean :
	rm -f ${OBJS} ${BONUSOBJS}

fclean : clean
	rm -f ${NAME}

re : 
	make fclean
	make all

.PHONY : fclean re all clean bonus libft.a
