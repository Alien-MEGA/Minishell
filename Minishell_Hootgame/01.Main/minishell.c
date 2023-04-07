/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/07 05:40:13 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	load_env(argv[0], env);
	sig_inint(TP_SIG_MAIN);
	rl_catch_signals = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_list	*lst;
	int		line_status;
	t_tree	*tree;

	init(argc, argv, env);
	while (1)
	{
		int fd = dup(0);
		lst = NULL;
		line_status = prompt(&lst);
		if (line_status == FALSE)
			continue ;
		lst = ft_filter(lst);
		if (check_syntax(lst) == TRUE)
		{
			tree = mk_tree(lst);
			sig_inint(TP_SIG_EMPTY);
			run_here_doc(tree);
			execute(tree, STDIN_FILENO, STDOUT_FILENO, TRUE);
			sig_inint(TP_SIG_MAIN);
			g_pub.is_sigset = FALSE;
			dup2(fd, 0);
			close(fd);
			sig_inint(TP_SIG_MAIN);
		}
		// ft_lstclear(&lst);
	}
}
