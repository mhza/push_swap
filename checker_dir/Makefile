# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 15:46:45 by mhaziza           #+#    #+#              #
#    Updated: 2017/02/01 18:53:37 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I. -g
RM		=   rm -f
SRCS	=	main.c \
			set_link.c \
			checker.c \
			link_utils.c \
			link_utils2.c \
			stdout_utils.c \
			ope_utils.c \

OBJS	=   $(SRCS:.c=.o)

LIBFT_PATH	= ../libft

all:	$(NAME)

$(NAME):$(OBJS)
	@$(CC) $(CFLAG) $(SRCS) -L../libft -lft -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
