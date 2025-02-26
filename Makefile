# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 10:12:54 by dlorenzo          #+#    #+#              #
#    Updated: 2025/02/25 16:54:55 by dlorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libftprintf.a

# Directories
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include Libft headers
INCLUDES = -I$(LIBFT)

# Source Files
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)
LIBFT_OBJ = $(LIBFT_DIR)/*.o

# Bonus Files
OBJ_BONUS = $(SRC:.c=.o)

# Test environment
TEST = test
TEST_SRC = test.c
TEST_BIN = $(TEST)

# Compilation rules
all: $(LIBFT) $(NAME)

# Compile Libft first
$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(AR) $(NAME) $(OBJ) $(LIBFT_OBJ) $?
	@echo "\033[32m*** $(NAME) created! ***\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -I. -c $< -o $@

#bonus: $(OBJ_BONUS) $(LIBFT)
#	$(AR) $(NAME) $(OBJ) $(LIBFT_OBJ) $?
#	@echo "\033[32m*** $(NAME) created! ***\033[0m"

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(TEST_BIN)

re: fclean all

# Test rule
test: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) $(LIBFT) -o $(TEST_BIN)

# Check Norm
norm:
	norminette -R CheckForbiddenSourceHeader || true

.PHONY: all clean fclean re test