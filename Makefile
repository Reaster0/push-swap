# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 02:21:14 by earnaud           #+#    #+#              #
#    Updated: 2021/07/23 17:16:37 by earnaud          ###   ########.fr        #
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
CFLAGS		= -Wall -Wextra -Werror
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