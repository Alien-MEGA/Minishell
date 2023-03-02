/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/02 19:12:59 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_public g_pub;

void sig(int num)
{
	if (num == SIGINT)
		kill(g_pub.pid, SIGINT);
	signal(SIGINT, sig);
	signal(SIGQUIT, sig);
}

char *prompt(void)
{
	char *line;
	t_list *ls;
	int len;
	t_token *t;

	ls = 0;
	len = ft_lstsize(ls);
	line = readline(get_prompt(get_pwd()));
	if (line != 0)
		add_history(line);
	printf("line : %s \n", line);
	create_token_list(&ls, line);
	while (ls != 0)
	{
		t = (t_token *)ls->data;
		printf("type %d , Value : %s \n", t->type, t->value);
		ls = ls->next;
	}
	t_list *lis = get_ls();
	if (lis == 0)
		exit(0);
	while (lis)
	{
		printf("name > %s\n", lis->data);
		lis = lis->next;
	}

	return (line);
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_pub.env = ft_matrixdup(env);
	while (1)
		prompt();
}
