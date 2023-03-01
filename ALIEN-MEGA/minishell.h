/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:27 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/02 00:05:32 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>

# include "const.h"
# include "libft/libft.h"

enum e_token
{
	TK_WORD,
	TK_SINGLE_QUOTE,
	TK_DOUBLE_QUOTE,
	TK_PIPE,
	TK_HERE_DOC,
	TK_RD_INPUT,
	TK_RD_OUTPUT,
	TK_RD_OUTPUT_APPEND,
	TK_AND,
	TK_OR,
	TOKEN_OPEN_BRACE,
	TK_CLOSE_BRACE,
	TK_WT_SPACE,
	TK_OPEN_QUOTE
};

typedef struct s_public
{
	int		pid;
	int		exit_status;
}			t_public;

/* ==============> Tokenizer <============== */

typedef struct s_token
{
	int		type;
	char	*value;

}			t_token;

void	add_token(t_list **list, int type, char *value);
void	skip_wt_sapce(t_list **list, char *line, int *i);
void	skip_quote(t_list **list, char *line, int *i, char qoute);
void	skip_word(t_list **list, char *line, int *i);
t_list	**create_token_list(t_list **head, char *line);

int		indexofchar(char *line, char c);

#endif