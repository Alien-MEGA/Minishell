# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 14:30:49 by ebennamr          #+#    #+#              #
#    Updated: 2023/04/12 00:39:49 by ebennamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc -g 

FLAGS = -Wall -Werror -Wextra

SRC = ./01.Main/minishell.c \
	./02.Lexer/checker.c \
	./02.Lexer/checker_util.c \
	./02.Lexer/tokenizer.c \
	./02.Lexer/tokenizer_util.c \
	./03.Parser/ast.c \
	./03.Parser/ast_utils.c \
	./03.Parser/tree_utils.c \
	./04.Expander/concater.c \
	./04.Expander/expander.c \
	./04.Expander/expander_util.c \
	./04.Expander/wildcard.c \
	./04.Expander/expander_hepler.c\
	./05.Execute/execute.c \
	./05.Execute/execute_utils.c \
	./05.Execute/here_doc.c \
	./05.Execute/redirection_utils.c \
	./05.Execute/run_utils.c \
	./06.Built-in/cd_cmd.c \
	./06.Built-in/echo_cmd.c \
	./06.Built-in/env_cmd.c \
	./06.Built-in/exit_cmd.c \
	./06.Built-in/export_cmd.c \
	./06.Built-in/pwd_cmd.c \
	./06.Built-in/unset_cmd.c \
	./07.Env_utils/env.c \
	./07.Env_utils/env_util.c \
	./07.Env_utils/export.c \
	./07.Env_utils/export_utils.c \
	./07.Env_utils/helper.c \
	./07.Env_utils/pwd.c \
	./07.Env_utils/signal.c \
	./07.Env_utils/string.c \
	./08.Libft/ft_atoi.c \
	./08.Libft/ft_bzero.c \
	./08.Libft/ft_calloc.c \
	./08.Libft/ft_error.c \
	./08.Libft/ft_free.c \
	./08.Libft/ft_index_list.c \
	./08.Libft/ft_isalnum.c \
	./08.Libft/ft_isalpha.c \
	./08.Libft/ft_isascii.c \
	./08.Libft/ft_isdigit.c \
	./08.Libft/ft_isprint.c \
	./08.Libft/ft_itoa.c \
	./08.Libft/ft_lstadd_back.c \
	./08.Libft/ft_lstadd_front.c \
	./08.Libft/ft_lstclear.c \
	./08.Libft/ft_lstdelone.c \
	./08.Libft/ft_lstiter.c \
	./08.Libft/ft_lstlast.c \
	./08.Libft/ft_lstnew.c \
	./08.Libft/ft_lstsize.c \
	./08.Libft/ft_matdup.c \
	./08.Libft/ft_memchr.c \
	./08.Libft/ft_memcmp.c \
	./08.Libft/ft_memcpy.c \
	./08.Libft/ft_memmove.c \
	./08.Libft/ft_memset.c \
	./08.Libft/ft_printf.c \
	./08.Libft/ft_putchar_fd.c \
	./08.Libft/ft_putchar_printf.c \
	./08.Libft/ft_putendl_fd.c \
	./08.Libft/ft_putnbr_fd.c \
	./08.Libft/ft_putnbr_hex_printf.c \
	./08.Libft/ft_putnbr_pos_printf.c \
	./08.Libft/ft_putnbr_printf.c \
	./08.Libft/ft_putptr_printf.c \
	./08.Libft/ft_putstr_fd.c \
	./08.Libft/ft_putstr_printf.c \
	./08.Libft/ft_split.c \
	./08.Libft/ft_strchr.c \
	./08.Libft/ft_strdup.c \
	./08.Libft/ft_striteri.c \
	./08.Libft/ft_strjoin.c \
	./08.Libft/ft_strlcat.c \
	./08.Libft/ft_strlcpy.c \
	./08.Libft/ft_strlen.c \
	./08.Libft/ft_strmapi.c \
	./08.Libft/ft_strncmp.c \
	./08.Libft/ft_strnstr.c \
	./08.Libft/ft_strrchr.c \
	./08.Libft/ft_strtrim.c \
	./08.Libft/ft_substr.c \
	./08.Libft/get_next_line.c \
	./08.Libft/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

RL_PATH=$(shell brew --prefix readline)

LIB = -L $(RL_PATH)/lib -lreadline

all : $(NAME)

# @echo "\033[1m\033[35m"
# @printf " ███▄ ▄███▓ ██▓ ███▄    █  ██▓  ██████  ██░ ██ ▓█████  ██▓     ██▓    \n"
# @sleep 0.3;
# @printf "▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    \n"
# @sleep 0.3;
# @printf "▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░    \n"
# @sleep 0.3;
# @printf "▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░  ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    \n"
# @sleep 0.3;
# @printf "▒██▒   ░██▒░██░▒██░   ▓██░░██░▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒\n"
# @sleep 0.3;
# @printf "░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░\n"
# @sleep 0.3;
# @printf "░  ░   ░  ░ ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░\n"
# @sleep 0.3;
# @printf "░      ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ░   ░  ░░ ░   ░  ░░ ░ ░     ░ ░   \n"
# @sleep 0.3;
# @printf "       ░    ▒           ░  ▒ ░░     ░   ░  ░  ░   ░  ░░   ░  ░    ░  ░\n"
# @printf "       ░    ▒           ░  ▒   ______   ░     ░      ░░\n"
# @printf "       ░    ▒           ░   .-|      |-.      ░      ░░\n"
# @printf "       ░    ▒           ░  /            \     ░        \n"
# @printf "       ░    ▒  _        ░ |              |    ░     _  \n"
# @printf "       ░    ▒ ( \       ░ |,  .-.  .-.  ,|    ░    / ) \n"
# @printf "       ░    ▒  > +=._     | )(__/  \__)( |     _.=+ <  \n"
# @printf "       ░    ▒ (_/+=._+=._ |/     /\     \| _.=+_.=+\_) \n"
# @printf "            ▒        +=._ (_     ^^     _)+_.=+        \n"
# @printf "            ▒            +=\__|IIIIII|__/=+            \n"
# @printf "            ▒           _.=+| \IIIIII/ |+=._           \n"
# @printf "            ▒ _     _.=+_.=+\          /+=._+=._     _ \n"
# @printf "            ▒( \_.=+_.=+     \________/     +=._+=._/ )\n"
# @printf "              > _.=+                            +=._ < \n"
# @printf "             (_/                                    \_)\n"
# @echo "\033[0m"
$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(LIB) $(OBJ) -o $(NAME)

%.o: %.c 00.Include/minishell.h 00.Include/const.h 00.Include/libft.h
	$(CC) $(FLAGS) -I $(RL_PATH)/include -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
