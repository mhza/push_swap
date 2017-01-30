# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 17:18:53 by mhaziza           #+#    #+#              #
#    Updated: 2017/01/30 17:19:20 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I. -g
RM		=   rm -f
SRCS	=	push_swap.c \

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
