# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 15:46:45 by mhaziza           #+#    #+#              #
#    Updated: 2017/02/08 12:25:23 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I. -g
RM		=   rm -f
SRCS	=	main_checker.c \
			checker.c \
			stdout_utils.c \

OBJS	=   $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
