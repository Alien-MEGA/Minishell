/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/10 05:07:45 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

t_public	g_pub;

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
	char	*prompt;

	prompt = get_prompt(get_pwd());
	line = readline(prompt);
	free(prompt);
	if (line != NULL)
		add_history(line);
	if (line == NULL)
		exit_cmd(NULL);
	if (check_line(line) == FALSE)
		return (free(line), FALSE);
	create_token_list(lst, line);
	return (free(line), TRUE);
}

static void	init(int argc, char **argv, char **env)
{
	(void)argc;
	g_pub.env = NULL;
	g_pub.fd_lst = NULL;
	g_pub.exp_list = malloc(sizeof(char *));
	g_pub.exp_list[0] = NULL;
	g_pub.exit_status = 0;
	g_pub.is_sigset = FALSE;
	g_pub.token_error = NULL;
	g_pub.std_fd.fd_rd = dup(STDIN_FILENO);
	ft_error(g_pub.std_fd.fd_rd, 1);
	g_pub.std_fd.fd_wr = dup(STDOUT_FILENO);
	ft_error(g_pub.std_fd.fd_wr, 1);
	load_env(argv[0], env);
	sig_inint(TP_SIG_MAIN);
	rl_catch_signals = 0;
}

void	leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **env)
{
	atexit(leaks);
	t_list	*lst;
	int		line_status;
	t_tree	*tree;

	init(argc, argv, env);
	while (1)
	{
		sig_inint(TP_SIG_MAIN);
		reset_std_fd();
		g_pub.is_sigset = FALSE;
		lst = NULL;
		line_status = prompt(&lst);
		if (line_status == FALSE)
			continue ;
		lst = ft_filter(lst);
		if (check_syntax(lst) == TRUE)
		{
			tree = mk_tree(lst);
			if (!tree)
			{
				syntax_error(g_pub.token_error);
				continue ;
			}
			sig_inint(TP_SIG_HRDC);
			run_here_doc(tree);
			if (g_pub.is_sigset == TRUE)
				continue ;
			sig_inint(TP_SIG_EMPTY);
			execute(tree, STDIN_FILENO, STDOUT_FILENO, TRUE);
			ft_treeclear(&tree);
		}
		// ft_lstclear(&lst);
	}
}
