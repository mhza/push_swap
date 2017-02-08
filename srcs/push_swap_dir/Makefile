# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 17:18:53 by mhaziza           #+#    #+#              #
#    Updated: 2017/02/08 13:57:28 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I.
RM		=   rm -f
SRCS	=	main.c \
			chainedlk_utils.c \
			ope_getstr.c \
			get_inversions.c \
			quick.c \
			quick_utils.c \
			quick_pack.c \
			quick_pack_utils.c \
			under_five_sort.c \
			three_left_sort.c \
			three_left_nsort.c \

OBJS	=   $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	@$(CC) $(CFLAG) $(SRCS) -L../libft -lft -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
