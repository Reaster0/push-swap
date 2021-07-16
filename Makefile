# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 02:21:14 by earnaud           #+#    #+#              #
#    Updated: 2021/07/16 18:18:28 by earnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c \
				operations.c \
				operations2.c \
				operations3.c \
				utils.c \
				utils2.c \
				utils3.c \
				finder.c \
				algo_for_3.c \
				algo_for_5.c \
				insertionv2.c \
				algo_function.c \
				algo_function2.c

OBJS		= $(SRCS:.c=.o)
NAME		= push_swap
cc			= clang
CFLAGS		= -g -Wall -Wextra -Werror
%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			$(CC) $(CFLAGS) ./generator/main.c -o rand_generator

clean:
			$(RM) $(OBJS)
		
fclean:		clean
			$(RM) $(NAME)
			$(RM) rand_generator

re:			fclean all


test:		RAND:=$(shell ./rand_generator 100)
test:		
			test starting!
			@./push_swap $(RAND) | wc 

.PHONY:		all clean fclean re