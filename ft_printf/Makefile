# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 18:21:57 by vkanate           #+#    #+#              #
#    Updated: 2021/12/08 22:48:22 by vkanate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = ft_printf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

$(NAME):	${OBJS}
			ar -rcs $@ $^

%.o : %.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@
 
all:	$(NAME)

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}
		
re:		fclean all