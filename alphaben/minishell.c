/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/12 14:05:02 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

char	*prompt(void)
{
	char	*line;
	t_list	*ls;
	int		len;

	ls = NULL;
	len = ft_lstsize(ls);
	//line = readline(get_prompt(get_pwd()));
	ft_printf(1,PROMPT_1);
	line = readline(PROMPT_2);

	if (line != 0)
		add_history(line);
	if(line == 0)
		exit(0);
	printf("line : %s \n", line);

	// cd_cmd(line);
	// printf("old : %s\n",expand_env("OLDPWD"));
	// printf("pwd : %s\n", expand_env("PWD"));
	printf("create token >> \n");
	create_token_list(&ls, line);
	printf("check Syntax token >> \n");
	int b = check_syntax(ls);
	printf("styntax>> %d\n", b);
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
	rl_catch_signals = FALSE;
	load_env(argv[0], env);
		// printf("===================\n");
		// for (int i = 0; g_pub.env[i]; i++)
		// 	printf("%d: %s\n", i, g_pub.env[i]);
		// printf("===================\n");
		sig_inint();
		export();
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
