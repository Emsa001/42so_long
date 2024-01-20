# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:49:31 by escura            #+#    #+#              #
#    Updated: 2024/01/20 15:51:31 by escura           ###   ########.fr        #
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
CFLAGS = -Iincludes/minilibx
LDFLAGS = -Lincludes/minilibx -lmlx -framework OpenGL -framework AppKit

# Source Files and Object Files
SRC_DIR = src
INCLUDES_DIR = includes
GET_NEXT_LINE = ./includes/get_next_line/get_next_line.c

SRC = $(wildcard $(SRC_DIR)/data/*.c) $(wildcard $(SRC_DIR)/map/*.c) $(wildcard $(SRC_DIR)/main.c) $(SRC_DIR)/render/scene.c $(SRC_DIR)/render/utils.c \
	  $(SRC_DIR)/hooks/key.c $(SRC_DIR)/hooks/mouse.c $(GET_NEXT_LINE)
	
OBJ_DIR = .obj
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Libft
LIBFT_DIR = $(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "${YELLOW}Compiling $(NAME)...${NC}"
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(LIBFT) -o $(NAME) > /dev/null
	@echo "${GREEN}$(NAME) compiled successfully!${NC}"
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}Compiled $< successfully!${NC}"

$(LIBFT):
	$(LIBFT_MAKE)

clean:
	@echo "${YELLOW}Cleaning up...${NC}"
	@$(LIBFT_MAKE) clean > /dev/null
	@rm -rf $(OBJ_DIR) > /dev/null
	@rm -rf $(OBJ_DIR_BONUS) > /dev/null
	@echo "${GREEN}Cleaned up successfully!${NC}"

fclean: clean
	@echo "${YELLOW}Full cleaning up...${NC}"
	@$(LIBFT_MAKE) fclean > /dev/null
	@rm -f $(NAME) > /dev/null
	@rm -f $(NAME_BONUS) > /dev/null
	@echo "${GREEN}Full cleaned up successfully!${NC}"

re: fclean all

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}Compiled $< successfully!${NC}"
	
.PHONY: all clean fclean re bonus