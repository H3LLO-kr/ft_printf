# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 10:07:15 by chanhapa          #+#    #+#              #
#    Updated: 2022/06/01 14:44:36 by chanhapa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rc
RM		= rm -rf
SRCS	= ft_printf.c libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_strchr.c
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
