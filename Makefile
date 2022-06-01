# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 10:07:15 by chanhapa          #+#    #+#              #
#    Updated: 2022/06/02 00:18:16 by chanhapa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rc
RM		= rm -rf
SRCS	= ft_printf.c \
		  _print_c.c \
		  _print_s.c \
		  _print_p.c \
		  _print_di.c \
		  _print_u.c \
		  _print_xX.c \
		  ft_strchr.c
OBJS	= ${SRCS:.c=.o}

all		: ${NAME}

${NAME}	: ${OBJS}
	${AR} ${NAME} $^

%.o		: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean	:
	${RM} ${OBJS}

fclean	:
	make clean
	${RM} ${NAME}

re		:
	make fclean
	make all

.PHONY	: all clean fclean re
