/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:51:48 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 05:12:43 by ebennamr         ###   ########.fr       */
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
# include "libft.h"

typedef struct s_public
{
	unsigned int	exit_status;
	char			**env;
	char			**exp_list;
	char			*path;
	int				isdef_env;
	int				is_sigset;
	int				should_fork;
	t_list			*fd_lst;
}					t_public;

extern t_public	g_pub;

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

/*###############################################################################
#                                 LEXER                                         #
###############################################################################*/

typedef struct s_token
{
	int		type;
	char	*value;
}			t_token;

void	add_token(t_list **list, int type, char *value);
t_list	**create_token_list(t_list **head, char *line);
void	skip_wt_sapce(t_list **list, char *line, int *i);
void	skip_quote(t_list **list, char *line, int *i, char quote);
void	skip_word(t_list **list, char *line, int *i);
int		print_error(char *value);
int		check_syntax(t_list *tokens);
int		check_quote(t_list *tokens);
int		check_brace(t_list *tokens);
int		check_tokens(t_list *tk);
int		istype(int t, int type);
int		check_op_syntax(t_list *prev, t_list *nxt);
int		check_rd_syntax(t_list *nxt);

/*###############################################################################
#                                 PARSER                                        #
###############################################################################*/

typedef struct s_tree
{
	t_list			*lst;
	t_list			*redirect_mode;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

t_tree	*mk_tree(t_list *lst);
t_tree	*pipeline(t_list **lst);
t_tree	*or_and(t_list **lst);
t_tree	*bracket_handle(t_list **lst);
t_tree	*create_command(t_list **lst);
t_tree	*create_operator(t_list **lst);
void	skip_space(t_list **lst);
t_tree	*ft_treenew(t_list *lst);
void	ft_treeswap_root(t_tree **tree, t_tree *new, int option);
void	ft_treeclear(t_tree **tree);

/*###############################################################################
#                                 EXPANDER                                      #
###############################################################################*/

void	wildcard_cmd(t_list *list);
int		wildcard_redir(t_list *list);
void	exapnd_var_list(t_list *lst);
int		expander(t_tree *node);
t_list	*ft_filter(t_list *lst); // Note Used
t_list	*concater(t_list *lst);

/*###############################################################################
#                                 EXECUTE                                       #
###############################################################################*/

typedef struct s_fd
{
	int		fd_wr;
	int		fd_rd;
}			t_fd;

pid_t	execute(t_tree *root, int fd_in, int fd_out, int should_wait);
void	close_pipe_fd(void);
void	dup_fd(int fd_in, int fd_out);
int		wait_pross(pid_t pross);
void	run_here_doc(t_tree *tree);
t_fd	run_redirect(t_list *redirect, t_fd fd_rd);
int		run_builtin(char **cmd, int fd_in, int fd_out);
char	**get_cmd(t_list *lst);
void	execute_x(char **cmd, char **env);

/*###############################################################################
#                                 BUILT-IN                                      #
###############################################################################*/

void	cd_cmd(char *path);
void	echo_cmd(char **cmd);
void	env_cmd(void);
void	exit_cmd(char **cmd);
void	export_cmd(char **cmd);
void	pwd_cmd(void);
void	unset_cmd(char **cmd);

/*###############################################################################
#                                 ENV_UTILS                                     #
###############################################################################*/

typedef struct s_struct
{
	int		i;
	int		j;
}			t_loc;

t_loc	ini_loc(int i, int j);
int		index_in_env(char *key);
void	load_env(char *_path, char **env);
void	export_to_env(char *key, char *value, int option);
void	unset_var(char *key);
char	*expand_env(char *key);
void	add_to_env(char *content);
void	set_shlvl(void);
void	fill_key_value_opt(char *arg, char **key, char **value, int *opt);
void	export_to_explist(char *arg);
int		valid_arg(char *arg);
void	sort_mat(char **arr);
int		check_var(char *var);
void	print_export(char *var);
void	add_to_export(char *content);
void	unset_from_exp(char *key);
char	*get_pwd(void);
char	*get_prompt(char *pwd);
t_list	*get_ls(void);
void	sig_inint(int type);
int		indexofchar(char *line, char c);
char	**mat_join(char **s1, char **s2);
int		ft_strcmp(char *str1, char *str2);
int		iscontain_var(char *word);
char	*expand_word(char *word, int start, int i);
void	ft_insert(t_list **head, t_list *newlst);
void	expand_var_insert(t_list *lst);
void	ft_insert(t_list **head, t_list *newlst);
t_list	*get_list_form_var(t_list *lst);
t_list	*nd_copy(t_list *lst);
void	insert_list(t_list **head, t_list *lst);
t_list	*concater_hrdc(t_list *lst);

#endif
