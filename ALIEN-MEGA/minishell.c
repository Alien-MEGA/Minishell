/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/03 21:48:42 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prompt(void)
{
	char	*line;
	t_list	*ls;
	int		len;

	ls = 0;
	len = ft_lstsize(ls);
	line = readline(get_prompt(get_pwd()));
	if (line != 0)
		add_history(line);
	if (line == 0)
		exit(0);
	printf("line : %s \n", line);
	create_token_list(&ls, line);
	return (line);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	// load_env(argv[0], env);
	// while (1)
	// 	prompt();
	parser();
}
