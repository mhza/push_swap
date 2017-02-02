# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 17:18:53 by mhaziza           #+#    #+#              #
#    Updated: 2017/02/02 16:25:44 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I. -g
RM		=   rm -f
SRCS	=	main.c \
			set_link.c \
			link_utils.c \
			link_utils2.c \
			stdout_utils.c \
			lked_utils.c \
			ope_utils.c \
			ft_strreal.c \
			ope_getstr.c \
			algo_small_set.c \


OBJS	=   $(SRCS:.c=.o)

LIBFT_PATH	= ../libft

all:	$(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAG) $(SRCS) -L../libft -lft -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
