/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/07 19:51:01 by ebennamr         ###   ########.fr       */
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
	while (ls)
	{
		printf("type : %d <> value %s \n", ls->type, ls->value);
		ls = ls->next;
	}
	free(line);
	return (line);
}
void at()
{
	system("leaks minishell");
}
int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_pub.env = NULL;
	g_pub.exp_list = malloc(sizeof(char *));
	g_pub.exp_list[0] = NULL;
		load_env(argv[0], env);
		export_args(argv);
	//export_to_env("PWD", ".", OPT_APPEND);
	//unset_var("_");
	//unset_var("PWD");
	//unset_var("SHLVL");
	printf("===================\n");
	// // char **join = mat_join(argv,argv);
	// // sort_mat(join);
	export();
	// // for (size_t i = 0; join[i] != 0; i++)
	// // 	printf("%s\n", join[i]);
	printf("===================\n");


	atexit(at);
	 while (1)
	 	prompt();
}
/*
add file lexer
		int	check_quote(t_list *tokens); check if exist open token
		int check_brace(t_list *tokens) check if num of open brace diffrent num of colse brace exmp: ()) or (()
		modifed : tokenizer.c  tokenizer_utlils.c minishell.h lexer.c

*/
