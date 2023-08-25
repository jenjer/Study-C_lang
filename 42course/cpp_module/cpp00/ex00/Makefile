# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 18:14:08 by youngski          #+#    #+#              #
#    Updated: 2023/03/29 18:20:48 by youngski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}
CXX = c++ 

NAME = megaphone

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
