# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 16:59:26 by made-jes          #+#    #+#              #
#    Updated: 2025/03/08 12:02:59 by made-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

# PATHS

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

INC = ./includes

SRC_DIR = ./sources

OBJ_DIR = ./obj

OBJ_DIR_BONUS = ./objbonus

# Source files

COMMON_SRCS = operations/ft_push.c operations/ft_rev_rotate.c \
			operations/ft_rotate.c operations/ft_swap.c \
			create_stack.c parsing.c sorting.c free_exit.c \
			stack_utils.c stack_utils2.c set_targets.c \
			pushing.c \

MAIN_SRC = push_swap.c \

BONUS_SRC = checker/checker.c \


SRCS = $(addprefix $(SRC_DIR)/, $(COMMON_SRCS) $(MAIN_SRC))

SRCS_BONUS = $(addprefix $(SRC_DIR)/, $(COMMON_SRCS) $(BONUS_SRC))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJS_BONUS= $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR_BONUS)/%.o)

# Compiler flags
CC = gcc -g 

CFLAGS = -Wall -Wextra -Werror -I $(INC)

# Rules
all: $(NAME)

bonus: $(BONUS)

$(LIBFT):
	@echo "Libft is compiling..."
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "Libft is compiled!"
	
	@echo "push_swap is compiling.."

$(OBJ_DIR_BONUS):
	@mkdir -p $(OBJ_DIR_BONUS)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling bonus $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) > /dev/null
	@echo "push_swap is compiled!"

$(BONUS): $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS) > /dev/null
	@echo "checker is compiled!"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@echo "Objects cleaned!"

fclean: clean
	@echo "Cleaning project..."
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@echo "All cleaned!"

re: fclean all

.PHONY: all re clean fclean bonus