# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 21:56:26 by azorlutu          #+#    #+#              #
#    Updated: 2025/02/17 21:56:28 by azorlutu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = pipex.c utils.c handle_errors.c pipex_bonus.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
