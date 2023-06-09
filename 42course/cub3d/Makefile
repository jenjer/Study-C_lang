# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyopark <gyopark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 19:45:58 by gyopark           #+#    #+#              #
#    Updated: 2023/05/22 17:10:45 by gyopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3d

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -o3 -g3 #-fsanitize=address
MLX         = -L./mlx -lmlx -framework OpenGL -framework AppKit
MLXDIR      = ./mlx
LIBFTDIR    = ./libft
LIBFT       = libft.a

SRCS_MAN    = src/main.c					\
			  src/map_setting.c				\
			  src/map_valid.c				\
			  src/map_direction.c			\
			  src/map_color.c				\
			  src/map2/map2_press.c			\
			  src/map2/map2_cast.c			\
			  src/map2/map2_cast_init.c		\
			  src/map2/map2_cast_texture.c	\
			  src/map2/map2_player.c		\
			  src/map2/map2_ray_cal.c		\
			  src/map2/map2_ray_draw.c		\
			  src/map2/map2_ray_init.c		\
			  src/map3/map3_render.c		\
			  src/map3/map3_loop.c			\
			  gnl/get_next_line.c       	\
			  src/utils.c					\
			  src/utils2.c					\
			  src/utils3.c					\
			  src/map_valid2.c				\
			  src/map_direction2.c			\
			  src/map_setting2.c			\
			  src/map_valid3.c

OBJS_MAN    = ${SRCS_MAN:.c=.o}

$(NAME) : $(OBJS_MAN)
		rm -f $(NAME)
		make clean -C $(MLXDIR)
		make fclean -C $(LIBFTDIR)  
		make all -C $(MLXDIR)
		make all -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(MLX) $^ $(LIBFTDIR)/$(LIBFT) -o $(NAME)

all : $(NAME)

fclean : clean
		rm -f $(NAME)

clean :
		rm -f $(OBJS_MAN) 
		make clean -C $(MLXDIR)
		make clean -C $(LIBFTDIR)

re : 
	make fclean 
	make all

.PHONY : fclean clean re all
