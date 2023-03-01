# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 14:30:49 by ebennamr          #+#    #+#              #
#    Updated: 2023/03/01 18:42:57 by ebennamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######### Variale Block  ################
CC = cc
FLAGS = #-Wall -Werror -Wextra
LIB = -lreadline
SRC = minishell.c string.c tokenizer.c tokenizer_util.c\
		dir.c env.c 
OBJ = $(SRC:.c=.o)
LIBFT = ./libft/libft.a

NAME = minishell

############# Target ##############
all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
		$(CC) $(FLAGS) $(LIB) $(LIBFT) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT) :
	make -C ./libft/

clean :
	make fclean -C ./libft/
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re
