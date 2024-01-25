# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:49:31 by escura            #+#    #+#              #
#    Updated: 2024/01/25 20:06:28 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Names
NAME = so_long

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes/minilibx
LDFLAGS = -Lincludes/minilibx -lmlx -framework OpenGL -framework AppKit

# Source Files and Object Files
SRC_DIR = src
BONUS_DIR = bonus
INCLUDES_DIR = includes
GET_NEXT_LINE = ./includes/get_next_line/get_next_line.c

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c) $(GET_NEXT_LINE)
BONUS = $(wildcard $(BONUS_DIR)/*.c) $(wildcard $(BONUS_DIR)/*/*.c) $(GET_NEXT_LINE)
	
OBJ_DIR = .obj
OBJ_DIR_BONUS = .obj_bonus
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_BONUS = $(patsubst $(BONUS_DIR)/%.c, $(OBJ_DIR_BONUS)/%.o, $(BONUS))

# Libft
LIBFT_DIR = $(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

PRINTF_DIR = $(INCLUDES_DIR)/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINTF_MAKE = $(MAKE) -C $(PRINTF_DIR)

all: $(NAME)

$(NAME): $(PRINTF) $(LIBFT) $(OBJ)
	@echo "${YELLOW}Compiling $(NAME)...${NC}"
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME) > /dev/null
	@echo "${GREEN}$(NAME) compiled successfully!${NC}"
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}Compiled $< successfully!${NC}"

$(LIBFT):
	$(LIBFT_MAKE)

$(PRINTF):
	$(PRINTF_MAKE)

bonus: $(PRINTF) $(LIBFT) $(OBJ_BONUS)
	@echo "${YELLOW}Compiling $(NAME)...${NC}"
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ_BONUS) $(LIBFT) $(PRINTF) -o $(NAME) > /dev/null
	@echo "${GREEN}$(NAME) compiled successfully!${NC}"

$(OBJ_DIR_BONUS)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}Compiled $< successfully!${NC}"

clean:
	@echo "${YELLOW}Cleaning up...${NC}"
	@$(LIBFT_MAKE) clean > /dev/null
	@$(PRINTF_MAKE) clean > /dev/null
	@rm -rf $(OBJ_DIR) > /dev/null
	@rm -rf $(OBJ_DIR_BONUS) > /dev/null
	@echo "${GREEN}Cleaned up successfully!${NC}"

fclean: clean
	@echo "${YELLOW}Full cleaning up...${NC}"
	@$(LIBFT_MAKE) fclean > /dev/null
	@$(PRINTF_MAKE) fclean > /dev/null
	@rm -f $(NAME) > /dev/null
	@rm -f $(NAME_BONUS) > /dev/null
	@echo "${GREEN}Full cleaned up successfully!${NC}"

re: fclean all

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}Compiled $< successfully!${NC}"
	
.PHONY: all clean fclean re bonus