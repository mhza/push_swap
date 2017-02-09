# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 17:18:53 by mhaziza           #+#    #+#              #
#    Updated: 2017/02/09 11:48:01 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS	=	push_swap
CHECKER	=	checker
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror
RM		=   rm -f
MKDIR	= mkdir -p
CHECKER_DIR	= checker_dir/
PUSH_SWAP_DIR	= push_swap_dir/
LIBFT	= -Llibft -lft
LIBFT_PATH	= ./libft
INC_DIR= includes/
PS_SRC	=	main.c \
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
			only_three.c
CHECKER_SRC	=	main_checker.c \
			checker.c \
			stdout_utils.c
SHARED_SRC	=	set_link.c \
			link_utils.c \
			ope_utils.c \

SHARED_OBJ= $(SHARED_SRC:.c=.o)
PS_OBJ	=	$(PS_SRC:.c=.o)
CHECKER_OBJ	=	$(CHECKER_SRC:.c=.o)
VPATH	=	srcs/checker_dir/:srcs/push_swap_dir/:srcs/shared/

########################
#    Makefile rules    #
########################

all: libft $(CHECKER) $(PS)
libft:
	@make -C libft

# Executables
$(CHECKER): $(CHECKER_OBJ) $(SHARED_OBJ)
	@$(CC) -o $@ $(CFLAGS) $^ -I $(INC_DIR) $(LIBFT)
	@echo "Compiling [$@]"
$(PS): $(PS_OBJ) $(SHARED_OBJ)
	@$(CC) -o $@ $(CFLAGS) $^ -I $(INC_DIR) $(LIBFT)
	@echo "Compiling [$@]"


# Object files
$(CHECKER_OBJ): $(CHECKER_SRC)
	@$(CC) -c $^ $(CFALGS) -I $(INC_DIR)
	@echo "Compiling [$^]"
$(SHARED_OBJ): $(SHARED_SRC)
	@$(CC) -c $^ $(CFALGS) -I $(INC_DIR)
	@echo "Compiling [$^]"
$(PS_OBJ): $(PS_SRC)
	@$(CC) -c $^ $(CFALGS) -I $(INC_DIR)
	@echo "Compiling [$^]"


# Cleaning rules
clean:
	@rm -f $(PS_OBJ) $(SHARED_OBJ) $(CHECKER_OBJ)
	@echo "Cleaning [$(PS_OBJ) $(SHARED_OBJ) $(CHECKER_OBJ)]"
fclean: clean
	@rm -rf $(CHECKER) $(PS)
	@make fclean -C libft
	@echo "Cleaning [libft checker push_swap]"
re: fclean all
.PHONY: clean fclean re libft
