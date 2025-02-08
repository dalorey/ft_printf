# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 16:19:02 by dlorenzo          #+#    #+#              #
#    Updated: 2025/02/08 20:06:50 by dlorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libftprintf.a

# Directories
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include Libft headers
INCLUDES = -I$(LIBFT_DIR)

# Source Files
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)
LIBFT_OBJ = $(LIBFT_DIR)/*.o

# Test environment
TEST = test
TEST_SRC = test.c
TEST_BIN = $(TEST)

# Compilation rules
all: $(LIBFT) $(NAME)

# Compile Libft first
$(LIBFT):
	make -C $(LIBFT_DIR) # Run make inside Libft folder

$(NAME): $(OBJ) $(LIBFT)
	$(AR) $(NAME) $(OBJ) $(LIBFT_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -I. -c $< -o $@

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

.PHONY: all clean fclean re test