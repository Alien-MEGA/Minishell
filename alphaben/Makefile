# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 14:30:49 by ebennamr          #+#    #+#              #
#    Updated: 2023/02/28 20:02:27 by ebennamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######### Variale Block  ################
CC = cc
FLAGS = #-Wall -Werror -Wextra
LIB = -lreadline -L libft -lft
SRC = minishell.c string.c tokenizer.c tokenizer_util.c
OBJ = $(SRC:.c=.o)

NAME = minishell

############# Target ##############
all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) $(LIB) $(OBJ) -o $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean :
	cd libft ; rm *.o
	cd ..
	rm $(OBJ)

fclean : clean
		rm (NAME)
