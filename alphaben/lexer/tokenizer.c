/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:45:14 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/01 23:27:59 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_token(t_list **list,int type,char *value)
{
	t_token	*tk_new;
	t_list	*new_node;
	int		len;

	tk_new = malloc(sizeof(t_token));
	ft_error_str(tk_new, 1);
	tk_new->type = type;
	tk_new->value = ft_strdup(value);
	new_node = ft_lstnew(tk_new);
	if (*list == NULL)
		(*list) = new_node;
	else
		ft_lstadd_back(list, new_node);
	len = ft_lstsize(*list);
}

static int check_teken1(char *line, int *i, t_list **list)
{
	int len;

	len = ft_strlen(line);
	if (line[*i] == '|' && *i < len - 1 && line[*i + 1] == '|')
		add_token(list, TK_OR, "||");
	else if (line[*i] == '<' && *i < len - 1 && line[*i + 1] == '<')
		add_token(list, TK_HERE_DOC, "<<");
	else if (line[*i] == '>' && *i < len - 1 && line[*i + 1] == '>')
		add_token(list, TK_HERE_DOC, ">>");
	else if (line[*i] == '&' && *i < len - 1 && line[*i + 1] == '&')
		add_token(list, TK_AND, "&&");
	else
		return (FALSE);
	*i += 1;
	return (TRUE);
}

static int check_teken2(char *line, int i, t_list **list)
{
	if (line[i] == '|')
		add_token(list, TK_PIPE, "|");
	else if (line[i] == '<')
		add_token(list, TK_RD_INPUT, "<");
	else if (line[i] == '>')
		add_token(list, TK_RD_OUTPUT, ">");
	else if (line[i] == '(')
		add_token(list, TOKEN_OPEN_BRACE, "(");
	else if (line[i] == ')')
		add_token(list, TK_CLOSE_BRACE, ")");
	else return (FALSE);
	return (TRUE);
}

t_list	**create_token_list(t_list **head, char *line)
{
	int		i;
	int		len;
	int		bool;
	t_list	*lsit;

	lsit = 0;
	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{

		bool = check_teken1(line, &i, head);
		if (bool == FALSE)
		bool = check_teken2(line, i, head);
		if (bool == FALSE)
		{
			if (line[i] == '"' || line[i] == '\'')
				skip_quote(head, line, &i, line[i]);
			else if (line[i] == ' ' || line[i] == '\t')
				skip_wt_sapce(head, line, &i);
			else
				skip_word(head, line, &i);
		}
		i++;
		bool = FALSE;
	}
	return (head);
}

