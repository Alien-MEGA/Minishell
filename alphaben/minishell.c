/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/19 15:46:07 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_line(char *line)
{
	int i;

	i = 0;
	if (line[0] == '\0')
		return (FALSE);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0')
		return (FALSE);
	return (TRUE);
}

int prompt(t_list **lst)
{
	char *line;
	char *prompt;

	prompt = get_prompt(get_pwd());
	if (isatty(0))
		ft_printf(2, prompt);
	free(prompt);
	line = readline(NULL);
	if (line == NULL)
		exit(g_pub.exit_status);
	if (line != NULL)
		add_history(line);
	if (check_line(line) == FALSE) // Modif : 2 segfault is handle
		return (free(line),FALSE);

	create_token_list(lst, line);
	return (free(line), TRUE);
}
void at(){system("leaks minishell");}
int main(int argc, char **argv, char **env)
{
	t_list *lst;
	int line_status;

	(void)argc;
	g_pub.env = NULL;
	g_pub.exp_list = malloc(sizeof(char *));
	g_pub.exp_list[0] = NULL;
	load_env(argv[0], env);
	//sig_inint();
	atexit(at);
	//  lst = get_ls();
	// for (size_t i = 0; lst; i++)
	// {
	// 	printf("%s:", lst->value);
	// 	lst = lst->next;
	// }

	while (1)
	{
		lst = NULL;
		line_status = prompt(&lst);
		wildcard(lst);
		t_list *tmp = lst;
		for (size_t i = 0;lst; i++)
		{
			printf("%s:",lst->value);
			lst = lst->next;
		}
		ft_lstclear(&tmp);

		// if (line_status == FALSE)
		// 	continue;
		// if (check_syntax(lst) == TRUE)
		// 	test(lst);
		// else
		// 	ft_lstclear(&lst);
	}
}
