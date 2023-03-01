/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/02 00:06:20 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_public g_pub;

void	sig(int num)
{
	if (num == SIGINT)
		kill(g_pub.pid, SIGINT);
	signal(SIGINT, sig);
	signal(SIGQUIT, sig);
}

char	*prompt(int fd)
{
	char	*line;
	t_list	*ls;
	int		len;
	t_token	*t;

	ls = 0;
	len = ft_lstsize(ls);
	line = readline(PROMPT);
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
	return (line);
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	int fd = open("text", O_RDWR | O_APPEND);
	while (1)
		prompt(fd);
}
