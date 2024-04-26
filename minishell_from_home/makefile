# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 15:55:33 by npiyapan          #+#    #+#              #
#    Updated: 2024/04/26 12:24:59 by npiyapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	when at 42 
#				bin/%.o: src/%.c $(HEADER) Makefile
#				CFLAGS = -Wall -Werror -Wextra
#	when at home 
#				bin/%.o: src/%.c
#				CFLAGS = -Wno-nullability-completeness

NAME = minishell

HEADER = include/minishell.h

LIBFT_DIR =  libft/
LIBFT = $(LIBFT_DIR)libft.a

OBJ_DIR = bin/
CC = cc
# CFLAGS = -Wall -Werror -Wextra
# CFLAGS = -Wall -Werror -Wextra -g
# CFLAGS = -fsanitize=thread -g -lpthread
CFLAGS = -Wno-nullability-completeness -fsanitize=address

SRC_DIR = src/
SRC_FILE = minishell utils parse_env signals my_loop

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILE)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILE)))

READLINE_DIR = $(shell brew --prefix readline)

# READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib
READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib -I $(READLINE_DIR)/include

all:	$(NAME)

bin/%.o: src/%.c
# bin/%.o: src/%.c $(HEADER) Makefile
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@ -I $(READLINE_DIR)/include

$(NAME): $(OBJ) 
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(READLINE_LIB) -o $(NAME)

clean:
	rm -rf bin
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)libft.a

re: fclean all

.PHONY: all bonus clean fclean re
