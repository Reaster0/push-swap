# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 02:21:14 by earnaud           #+#    #+#              #
#    Updated: 2021/06/28 15:32:16 by earnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c \
				operations.c \
				utils.c \
				utils2.c \
				finder.c \
				first_algo.c \
				second_algo.c \
				algo_for_3.c \
				algo_for_5.c \
				algo_merge.c \
				third_algo.c \
				insertionv2.c \
				push_a_best.c

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

.PHONY:		all clean fclean re