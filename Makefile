# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 19:02:58 by vkanate           #+#    #+#              #
#    Updated: 2022/01/14 15:11:46 by vkanate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CC_FLAGS = -Wall -Wextra -Werror -I.

HEADER		= minitalk.h

S_SRCS		= server.c minitalk_utils.c
C_SRCS		= client.c minitalk_utils.c

C_OBJS	= ${C_SRCS:.c=.o}
S_OBJS	= ${S_SRCS:.c=.o}

S_BONUS_SRCS		= server_bonus.c minitalk_utils.c
C_BONUS_SRCS		= client_bonus.c minitalk_utils.c

C_OBJS_BONUS	= ${C_BONUS_SRCS:.c=.o}
S_OBJS_BONUS	= ${S_BONUS_SRCS:.c=.o}

all: client server

bonus: client_bonus server_bonus

client: $(C_SRCS) $(HEADER)
	(make -C ft_printf)
	gcc $(CC_FLAGS) $(C_SRCS) -c
	gcc $(CC_FLAGS) -L ft_printf -lftprintf $(C_OBJS) -o client

server: $(S_SRCS) $(HEADER)
	(make -C ft_printf)
	$(CC) $(CC_FLAGS) $(S_SRCS) -c
	$(CC) $(CC_FLAGS) -L ft_printf -lftprintf $(S_OBJS) -o server
	
client_bonus: $(C_BONUS_SRCS) $(HEADER)
	(make -C ft_printf)
	$(CC) $(CC_FLAGS) $(C_BONUS_SRCS) -c
	$(CC) $(CC_FLAGS) -L ft_printf -lftprintf $(C_OBJS_BONUS) -o client_bonus

server_bonus: $(S_BONUS_SRCS) $(HEADER)
	(make -C ft_printf)
	$(CC) $(CC_FLAGS) $(S_BONUS_SRCS) -c
	$(CC) $(CC_FLAGS) -L ft_printf -lftprintf $(S_OBJS_BONUS) -o server_bonus


clean:
			(make clean -C ft_printf)
			rm -f ${C_OBJS}
			rm -f ${C_OBJS_BONUS}
			rm -f ${S_OBJS}
			rm -f ${S_OBJS_BONUS}

fclean:		clean
			(make fclean -C ft_printf)
			rm -f client
			rm -f server
			rm -f client_bonus
			rm -f server_bonus

re:			fclean all
