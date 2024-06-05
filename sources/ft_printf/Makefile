# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 13:52:43 by lopoka            #+#    #+#              #
#    Updated: 2024/05/17 10:04:18 by lopoka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
	   ft_prnt_c.c \
	   ft_prnt_s.c \
	   ft_prnt_p.c \
	   ft_prnt_d.c \
	   ft_prnt_u.c \
	   ft_prnt_lx.c \
	   ft_prnt_ux.c \
	   ft_realloc.c \
	   ft_printf_realloc.c \
	   ft_prnt_add.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
CRLIB = ar rcs
OFILES = ${SRCS:c=o}

${NAME} : ${OFILES}
	${CRLIB} ${NAME} ${OFILES}

all : ${NAME}

%.o : %.c ft_printf.h
	${CC} ${CFLAGS} -c -o $@ $<

clean :
	rm -f ${OFILES} ${BONUS_OFILES}

fclean :
	rm -f ${NAME} ${OFILES} ${BONUS_OFILES}

re : fclean all
