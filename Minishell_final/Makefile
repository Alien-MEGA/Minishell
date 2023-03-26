# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 14:30:49 by ebennamr          #+#    #+#              #
#    Updated: 2023/03/26 20:17:10 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc -g -fsanitize=address

FLAGS =  #-Wall -Werror -Wextra -fsanitize=address

SRC = minishell.c \
		./lexer/tokenizer.c \
		./lexer/tokenizer_util.c \
		./lexer/lexer.c \
		./lexer/lexer_util.c \
		./utils/string.c \
		./utils/pwd.c \
		./utils/env.c \
		./utils/env_util.c \
		./utils/export.c \
		./utils/export_utils.c \
		./utils/helper.c \
		./utils/signal.c \
		./built-in/cd_cmd.c \
		./built-in/echo_cmd.c \
		./built-in/env_cmd.c \
		./built-in/exit_cmd.c \
		./built-in/export_cmd.c \
		./built-in/pwd_cmd.c \
		./built-in/unset_cmd.c \
		./parser/parser.c \
		./parser/manage_tree.c \
		./parser/tree_utils.c \
		./parser/tool.c \
		./expander/concater.c \
		./expander/expander.c \
		./expander/expander_util.c \
		./expander/wildcard.c \
		./execute/execute.c \
		./execute/here_doc.c \
		./execute/run_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

RL_PATH=$(shell brew --prefix readline)

LIB = -L $(RL_PATH)/lib -lreadline

all : $(NAME)
	@echo "\033[1m\033[35m"
	@printf " ███▄ ▄███▓ ██▓ ███▄    █  ██▓  ██████  ██░ ██ ▓█████  ██▓     ██▓    \n"
	@sleep 0.3;
	@printf "▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    \n"
	@sleep 0.3;
	@printf "▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░    \n"
	@sleep 0.3;
	@printf "▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░  ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    \n"
	@sleep 0.3;
	@printf "▒██▒   ░██▒░██░▒██░   ▓██░░██░▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒\n"
	@sleep 0.3;
	@printf "░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░\n"
	@sleep 0.3;
	@printf "░  ░   ░  ░ ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░\n"
	@sleep 0.3;
	@printf "░      ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ░   ░  ░░ ░   ░  ░░ ░ ░     ░ ░   \n"
	@sleep 0.3;
	@printf "       ░    ▒           ░  ▒ ░░     ░   ░  ░  ░   ░  ░░   ░  ░    ░  ░\n"
	@printf "       ░    ▒           ░  ▒   ______   ░     ░      ░░\n"
	@printf "       ░    ▒           ░   .-|      |-.      ░      ░░\n"
	@printf "       ░    ▒           ░  /            \     ░        \n"
	@printf "       ░    ▒  _        ░ |              |    ░     _  \n"
	@printf "       ░    ▒ ( \       ░ |,  .-.  .-.  ,|    ░    / ) \n"
	@printf "       ░    ▒  > +=._     | )(__/  \__)( |     _.=+ <  \n"
	@printf "       ░    ▒ (_/+=._+=._ |/     /\     \| _.=+_.=+\_) \n"
	@printf "            ▒        +=._ (_     ^^     _)+_.=+        \n"
	@printf "            ▒            +=\__|IIIIII|__/=+            \n"
	@printf "            ▒           _.=+| \IIIIII/ |+=._           \n"
	@printf "            ▒ _     _.=+_.=+\          /+=._+=._     _ \n"
	@printf "            ▒( \_.=+_.=+     \________/     +=._+=._/ )\n"
	@printf "              > _.=+                            +=._ < \n"
	@printf "             (_/                                    \_)\n"
	@echo "\033[0m"

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