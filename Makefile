# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 02:21:14 by earnaud           #+#    #+#              #
#    Updated: 2021/07/13 16:35:54 by earnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c \
				operations.c \
				utils.c \
				utils2.c \
				finder.c \
				algo_for_3.c \
				algo_for_5.c \
				insertionv2.c \
				push_best.c

OBJS		= $(SRCS:.c=.o)
NAME		= push_swap
cc			= clang
CFLAGS		= -g #-Wall -Wextra -Werror
%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)
		
fclean:		clean
			$(RM) $(NAME)

re:			fclean all

test:		RAND:=$(shell ./generator/rand_generator 500)
test:		all
			@./push_swap $(RAND) | wc 

.PHONY:		all clean fclean re