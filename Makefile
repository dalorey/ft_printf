# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 16:19:02 by dlorenzo          #+#    #+#              #
#    Updated: 2025/02/05 18:09:15 by dlorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libftprintf.a
LFLAGS = -L. -lftprintf

# Directories
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include Libft headers
INCLUDES = -I$(LIBFT_DIR)

# Source Files
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)

# Bonus
#BONUS_SRC = 
#BONUS_OBJ = $(BONUS_SRC:.c=.o)

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
	$(AR) $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(TEST_BIN)

re: fclean all

# Bonus rule
#bonus: $(OBJ) $(BONUS_OBJ)
#	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)

# Test rule
test: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LFLAGS) -o $(TEST_BIN) Libft/libft.a

.PHONY: all clean fclean re bonus test