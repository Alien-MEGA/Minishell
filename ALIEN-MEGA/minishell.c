/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/13 22:57:49 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(t_list **lst)
{
	char	*line;

	line = readline(get_prompt(get_pwd()));
	// line = ft_strdup("cat | ls"); // test
	if (line != NULL)
		add_history(line);
	if(line == NULL)
		exit(g_pub.exit_status);
	create_token_list(lst, line);
	free(line);
}

int	main(int argc, char **argv, char **env)
{
	t_list	*lst;

	(void)argc;
	g_pub.env = NULL;
	g_pub.exp_list = malloc(sizeof(char *));
	g_pub.exp_list[0] = NULL;
	load_env(argv[0], env);
	while (1)
	{
		lst = NULL;
		prompt(&lst);
		if (check_syntax(lst) == TRUE)
			test(lst);
		else
			ft_lstclear(&lst);















	}
}
