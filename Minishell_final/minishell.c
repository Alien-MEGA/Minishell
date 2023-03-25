/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/25 23:17:41 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_line(char *line)
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

int	prompt(t_list **lst)
{
	char	*line;

	line = readline(get_prompt(get_pwd()));
	// line = ft_strdup("touch text");
	// line = ft_strdup("ls >> outfile");
	// line = ft_strdup("cat < outfile");
	// line = ft_strdup("cat << outfile");
	if (line != NULL)
		add_history(line);
	if (line == NULL)
		exit(g_pub.exit_status);
	if (check_line(line) == FALSE)
		return (FALSE);
	create_token_list(lst, line);
	free(line);
	return (TRUE);
}

int	main(int argc, char **argv, char **env)
{
	t_list	*lst;
	int		line_status;
	t_tree	*tree;

	(void)argc;
	g_pub.env = NULL;
	g_pub.exp_list = malloc(sizeof(char *));
	g_pub.exp_list[0] = NULL;
	load_env(argv[0], env);
	while (1)
	{
		lst = NULL;
		line_status = prompt(&lst);
		if (line_status == FALSE)
			continue ;
		if (check_syntax(lst) == TRUE)
		{
			tree = mk_tree(lst);
			execute(tree, STDIN_FILENO, STDOUT_FILENO, TRUE);










			// exit(0);
			// exit(WEXITSTATUS(g_pub.exit_status));
		}
		// ft_lstclear(&lst);
	}
}