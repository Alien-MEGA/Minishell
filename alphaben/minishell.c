/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/25 19:36:11 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_list *t)
{
	printf("\n");
	while (t)
	{
		if (t->next)
			printf("(%d:%s)->", t->type,t->value);
		else
			printf("(%d:%s)", t->type, t->value);
		t = t->next;
	}
}

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
	char	*prompt;
	prompt = get_prompt(get_pwd());
	line = readline(prompt);
		free(prompt);
	if (line != NULL)
		add_history(line);
	if (line == NULL)
		exit(g_pub.exit_status);
	if (check_line(line) == FALSE)
		return (free(line), FALSE);
	create_token_list(lst, line);
	free(line);
	return (TRUE);
}

void at(){system("leaks minishell");}
int	main(int argc, char **argv, char **env)
{
	t_list	*lst;
	int		line_status;
	t_tree	*tree;

	(void)argc;
	g_pub.env = NULL;
	g_pub.exp_list = malloc(sizeof(char *));
	g_pub.exp_list[0] = NULL;
	g_pub.isdef_env = FALSE;
	load_env(argv[0], env);
	atexit(at);
	export_to_env("PATH", ":ok", OPT_APPEND);
	while (1)
	{
		lst = NULL;
		line_status = prompt(&lst);
		print_list(lst);
		if (line_status == FALSE)
			continue ;
		if (check_syntax(lst) == TRUE)
		{
		lst = ft_fillter(lst);
		//ft_lstclear(&tmp);
		printf("filter: ");
		 exapnd_var_list(lst);
		 t_list *tmp = lst;
		 lst = concater(lst);
		  ft_lstclear(&tmp);
		  wildcard_cmd(lst);
		 // wildcard_redir(lst);
		 print_list(lst);
		 ft_lstclear(&lst);
		}
		else
		ft_lstclear(&lst);
	}
}
