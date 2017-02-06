# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 17:18:53 by mhaziza           #+#    #+#              #
#    Updated: 2017/02/06 21:42:22 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I.
RM		=   rm -f
SRCS	=	main.c \
			set_link.c \
			link_utils.c \
			link_utils2.c \
			stdout_utils.c \
			chainedlk_utils.c \
			chainedlk_utils2.c \
			ope_utils.c \
			ft_strreal.c \
			ope_getstr.c \
			algo_utils.c \
			quick.c \
			quick_utils.c \
			quick_pack.c \
			quick_pack_utils.c \
			under_five_sort.c \
			three_left_sort.c \
			three_left_nsort.c \


OBJS	=   $(SRCS:.c=.o)

LIBFT_PATH	= ../libft

all:	$(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAG) $(SRCS) -L../libft -lft -o $(NAME) -g

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re:		fclean all

.PHONY:		all clean fclean re
