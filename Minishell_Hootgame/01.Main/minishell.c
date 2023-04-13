/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/13 21:12:13 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

t_public	g_pub;

void	paddress(void *address)
{
	fprintf(stderr, "%p\n", address);
}

static void	syntax_error(char *token)
{
	g_pub.exit_status = 258;
	return (ft_printf(2,
			"Minishell : syntax error near unexpected `%s'\n",
			token));
}

static int	check_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0')
		return (FALSE);
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (FALSE);
	return (TRUE);
}

static int	prompt(t_list **lst)
{
	char	*line;

	line = readline(PROMPT);
	if (line != NULL)
		add_history(line);
	if (line == NULL)
		exit_cmd(NULL);
	if (check_line(line) == FALSE)
		return (free(line), FALSE);
	create_token_list(lst, line);
	*lst = ft_filter(*lst);
	return (free(line), check_syntax(*lst));
}

static void	init(char **argv, char **env, t_list **lst, t_tree **tree)
{
	*lst = NULL;
	*tree = NULL;
	g_pub.env = NULL;
	g_pub.fd_lst = NULL;
	g_pub.exp_list = malloc(sizeof(char *));
	g_pub.exp_list[0] = NULL;
	g_pub.exit_status = 0;
	g_pub.is_sigset = FALSE;
	g_pub.std_fd.fd_rd = dup(STDIN_FILENO);
	ft_error(g_pub.std_fd.fd_rd, 1);
	g_pub.std_fd.fd_wr = dup(STDOUT_FILENO);
	ft_error(g_pub.std_fd.fd_wr, 1);
	load_env(argv[0], env);
	sig_inint(TP_SIG_MAIN);
	rl_catch_signals = 0;
}

void	reset_loop(t_list **lst, t_tree **tree)
{
	g_pub.is_sigset = FALSE;
	g_pub.should_fork = FALSE;
	ft_lstclear(&g_pub.fd_lst);
	g_pub.fd_lst = NULL;
	ft_treeclear(tree);
	ft_lstclear(lst);
	*lst = NULL;
	sig_inint(TP_SIG_MAIN);
	reset_io();
}

int	main(int argc, char **argv, char **env)
{
	int		line_status;
	t_list	*lst;
	t_tree	*tree;

	(void)argc;
	init(argv, env, &lst, &tree);
	while (1)
	{
		reset_loop(&lst, &tree);
		line_status = prompt(&lst);
		if (line_status == FALSE)
			continue ;
		tree = mk_tree(lst);
		sig_inint(TP_SIG_HRDC);
		run_here_doc(tree);
		if (g_pub.is_sigset == TRUE)
			continue ;
		sig_inint(TP_SIG_EMPTY);
		execute(tree, STDIN_FILENO, STDOUT_FILENO, TRUE);
	}
}
