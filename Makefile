# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 14:59:04 by lopoka            #+#    #+#              #
#    Updated: 2024/06/04 15:37:48 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ofast -flto -I ./includes
MLX42 = sources/MLX42

LIBS = ${MLX42}/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS	=	sources/fractol.c \
			sources/complex_num.c \
			sources/complex_pow.c \
			sources/sets.c \
			sources/bonus_sets.c \
			sources/colors.c \
			sources/hooks.c \
			sources/init.c \
			sources/show_img.c \
			sources/close.c \
			sources/map.c 

OFILES = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

${NAME}: ${OFILES}
	cmake ${MLX42} -B ${MLX42}/build && make -C ${MLX42}/build -j4
	${CC} -o ${NAME} ${CFLAGS} ${OFILES} ${LIBS} -flto

clean:
	rm -rf ${OFILES} ${MLX42}/build

fclean: clean
	rm -rf ${NAME} ${OFILES} ${MLX42}/build

re: fclean all

.PHONY: all, clean, fclean, re, mlx42
