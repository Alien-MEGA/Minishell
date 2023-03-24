/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:27 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/24 14:59:43 by ebennamr         ###   ########.fr       */
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
# include <sys/stat.h>
# include <errno.h>
# include <dirent.h>
# include "readline/readline.h"
# include "readline/history.h"

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
	TK_OPEN_BRACE,
	TK_CLOSE_BRACE,
	TK_WT_SPACE,
	TK_OPEN_QUOTE
};

typedef struct s_public
{
	unsigned int	exit_status;
	char			**env;
	char			**exp_list;
	char			*path;
	int				isdef_env;
}					t_public;

t_public	g_pub;

typedef struct s_struct
{
	int		i;
	int		j;
}			t_loc;

t_loc	ini_loc(int i, int j);
/* ==============> Tokenizer <============== */
int		check_quote(t_list *tokens);
int		check_brace(t_list *tokens);
/* 	=============> /lexer_util/ <============== */
int		istype(int t, int type);
int		check_op_syntax(t_list *prev, t_list *nxt);
int		check_rd_syntax(t_list *nxt);
int		check_syntax(t_list *tokens);
int		check_tokens(t_list *tk);
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
char	**mat_join(char **s1, char **s2);
int		ft_strcmp(char *str1, char *str2);

	/* ==============> /utils/pwd <============== */
char	*get_pwd(void);
char	*get_prompt(char *pwd);
char	*wildcard_exp(char *word);
t_list	*get_ls(void);

/* ==============> /utils/env/ <============== */
void	load_env(char *_path, char **env);
void	export_to_env(char *key, char *value, int option);
void	unset_var(char *key);
char	*expand_env(char *key);
void	add_to_env(char *content);
void	set_shlvl(void);
void	fill_key_value_opt(char *arg, char **key, char **value, int *opt);
void	export_args(char **args);
void	export_to_explist(char *arg);
void	add_to_export(char *content);
void	unset_from_exp(char *key);

/* ==============> /utils/signal/ <============== */
void	sig_inint(void);
	/* ==============> /utils/unset <============== */
void	unset_cmd(char **args);
/* ==============> /utils/export <============== */
void	sort_mat(char **arr);
void	export(void);
int		valid_arg(char *arg);
	/* ==============> /utils/export_utils <============== */
int		check_var(char *var);
void	print_export(char *var);
/* ==============> built-in <============== */
/* ==============> /built-in/ <============== */
void	echo_cmd(char *command_line);
void	exit_cmd(char *command_line);
void	cd_cmd(char *path);
/* ==============> Parser <============== */
/* ==============> /parser/ <============== */
typedef struct s_tree
{
	t_list			*lst;
	t_list			*redirect_mode;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

t_tree	*ft_treenew(t_list *lst);
t_tree	*ft_treelast(t_tree *tree, int option);
void	ft_treeadd_back(t_tree **tree, t_tree *new, int option);
void	ft_treeswap_root(t_tree **current_root, t_tree *new_root, int option);
void	ft_treeclear(t_tree **tree);

void	syntax_error(char *token);
t_tree	*mk_tree(t_list *lst);
void	test(t_list *lst);

t_tree	*create_command(t_list **lst);
t_tree	*create_operator(t_list **lst);
t_list	*create_redirect(t_list **lst);

void	skip_space(t_list **lst);
t_tree	*bracket_handle(t_list **lst);
t_tree	*pipeline(t_list **lst);
t_tree	*or_and(t_list **lst);
t_tree	*mk_tree(t_list *lst);

void	printList(t_list *lst, t_list *rd);
void	printTree(t_tree *tree);

/* ==============> execute <============== */
/* ==============> /execute/ <============== */

typedef struct s_fd
{
	int		fd_wr;
	int		fd_rd;
}			t_fd;
# define C_IN 0
# define C_OUT 1
# define C_X 2

typedef struct s_flag
{
	int		should_wait;
	int		flag;
}			t_flag;

char	*here_doc(char *delimiter);
void	execute_x(char **cmd, char **env);
pid_t	execute(t_tree *root, int fd_in, int fd_out, int should_wait);
int		wait_pross(pid_t pross);
//=================================> parsser c >=================
void	wildcard_cmd(t_list *list);
void	wildcard_redir(t_list *list);
void	exapnd_var_list(t_list *lst);
t_list	*ft_fillter(t_list *lst);
t_list	*concater(t_list *lst);
void	print_list(t_list *t);

#endif
