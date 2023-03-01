/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/01 23:36:17 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	line = readline(PROMPT);
	ft_error_str(line, 0);
	ft_printf(fd, ":::: %s\n", line);
	// if (line != 0)
	// 	add_history(line);
	// printf("line : %s \n",line);
	// /* Token */
	// t_list *ls = 0;
 	// create_token_list(&ls,line);
	// len = ft_lstsize(ls);

	// // t = (t_token *)ls->content;
	// // printf("type %d , Value : %s \n", t->type, t->value);
	// while (ls != 0)
	// {
	// 	t = (t_token *)ls->content;
	// 	printf("type %d , Value : %s \n", t->type, t->value);
	// 	ls = ls->next;
	// }
	return (line);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	int	fd = open("text", O_RDWR | O_APPEND);
	while (1)
		prompt(fd);
}
