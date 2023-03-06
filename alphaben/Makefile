# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 14:30:49 by ebennamr          #+#    #+#              #
#    Updated: 2023/03/06 18:35:19 by ebennamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc -g

FLAGS = #-Wall -Werror -Wextra


SRC = minishell.c \
		string.c \
		./lexer/tokenizer.c \
		./lexer/tokenizer_util.c \
		./utils/pwd.c \
		./utils/env.c \
		./parser/parser.c \
		./parser/tree_utils.c\
		./utils/env_util.c\
		./utils/export.c\
		./utils/export_utils.c\
		./lexer/lexer.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

RL_PATH=$(shell brew --prefix readline)

LIB = -L $(RL_PATH)/lib -lreadline

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(LIB) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I $(RL_PATH)/include -c $< -o $@

$(LIBFT) :
	make -C libft

clean :
	rm -f $(OBJ)
	make fclean -C libft

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

