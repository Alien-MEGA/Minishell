# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:20:52 by reben-ha          #+#    #+#              #
#    Updated: 2023/03/23 14:51:30 by reben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putchar_printf.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putnbr_hex_printf.c \
		ft_putnbr_pos_printf.c \
		ft_putnbr_printf.c \
		ft_putptr_printf.c \
		ft_putstr_fd.c \
		ft_putstr_printf.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_error.c \
		ft_matdup.c \
		ft_free.c \
		ft_index_list.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o : %.c libft.h
	gcc -g -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f $(OBJ)
	rm -f libft.h.gch

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re