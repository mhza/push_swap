# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 17:18:53 by mhaziza           #+#    #+#              #
#    Updated: 2017/02/01 19:09:41 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I. -g
RM		=   rm -f
SRCS	=	push_swap_dir/main.c \
			push_swap_dir/set_link.c \
			push_swap_dir/link_utils.c \
			push_swap_dir/link_utils2.c \
			push_swap_dir/stdout_utils.c \

OBJS	=   $(SRCS:.c=.o)

LIBFT_PATH	= libft

all:	$(NAME)

$(NAME):$(OBJS)
	@$(CC) $(CFLAG) $(SRCS) -L./libft -lft -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
