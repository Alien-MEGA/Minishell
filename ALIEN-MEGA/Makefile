# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 14:30:49 by ebennamr          #+#    #+#              #
#    Updated: 2023/03/01 23:28:34 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

FLAGS = #-Wall -Werror -Wextra

LIB = -lreadline

SRC = minishell.c \
		string.c \
		./lexer/tokenizer.c \
		./lexer/tokenizer_util.c \

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(LIB) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft

clean :
	rm -f $(OBJ)
	make fclean -C libft

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re