/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:27 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/02 17:34:41 by ebennamr         ###   ########.fr       */
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
# include <errno.h>
# include "readline/readline.h"
# include <dirent.h>

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
	int				pid;
	unsigned int	exit_status;
	char			**env;
}			t_public;

/* ==============> Tokenizer <============== */
/* ==============> /lexer/ <============== */

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


/* ==============> /minishell/ <============== */
int		indexofchar(char *line, char c);

/* ==============> /utils/pwd <============== */
char	*get_pwd(void);
char	*get_prompt(char *pwd);
char	*wildcard_exp(char *word);
t_list	*get_ls();

	/* ==============> /utils/env/ <============== */
	void load_env(char **env);
void	export_to_env(char *key, char *value, int option);
void	unset_var(char *key);
char	*expand_env(char *key);

#endif
