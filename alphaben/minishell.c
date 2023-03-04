/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/04 15:59:26 by ebennamr         ###   ########.fr       */
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
	if(line == 0)
		exit(0);
	printf("line : %s \n", line);
	create_token_list(&ls, line);
	return (line);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	load_env(argv[0] ,env);
	//export_to_env("PWD", ".", OPT_APPEND);
	unset_var("_");
	unset_var("PWD");
	//unset_var("SHLVL");
	printf("===================\n");
	for (size_t i = 0; g_pub.env[i] != 0; i++)
	printf("%s\n",g_pub.env[i]);
	printf("===================\n");
	printf("after :%s \n+++++\n", expand_env("SHLVL"));
	//system("leaks minishell");
	// while (1)
	//	prompt();
}
