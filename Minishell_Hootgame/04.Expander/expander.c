/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:06:35 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/10 00:20:42 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static char	*get_next_key(char *word, int *i)
{
	int	start;

	start = *i;
	if (word[*i] == '\0')
		return (NULL);
	if (word[*i] == '?')
		return ((*i)++, ft_strdup("?"));
	if (word[*i] != '_' && !ft_isalpha(word[*i]))
		return (NULL);
	(*i)++;
	while (word[*i])
	{
		if (word[*i] != '_' && !ft_isalnum(word[*i]))
			return (ft_substr(word, start, *i - start));
		(*i)++;
	}
	return (ft_strdup(&word[start]));
}

char	*expand_word(char *word, int start, int i)
{
	char	*key;
	char	*new_word;
	char	*tmp;
	int		num;

	num = 0;
	new_word = ft_strdup("");
	while (word[i])
	{
		if (word[i] == '$')
		{
			num = i++;
			key = get_next_key(word, &i);
			if (key)
			{
				tmp = ft_substr(word, start, num - start);
				new_word = ft_strjoin_gnl(new_word, tmp);
				free(tmp);
				tmp = expand_env(key);
				new_word = ft_strjoin_gnl(new_word, tmp);
				free(tmp);
				start = i;
			}
			free(key);
		}
		else
			i++;
	}
	tmp = ft_substr(word, start, i - start);
	new_word = ft_strjoin_gnl(new_word, tmp);
	return (free(tmp), new_word);
}

static t_list	*exapnd_var_list_cmd(t_list *lst)
{
	t_list	*new_list;
	t_list	*tmp;

	tmp = lst;
	new_list = NULL;
	while (lst)
	{
		if (lst->type != TK_SINGLE_QUOTE && iscontain_var(lst->value))
			expand_cmd_helper(&new_list, lst);
		else
			ft_lstadd_back(&new_list, nd_copy(lst));
		lst = lst->next;
	}
	return (ft_lstclear(&tmp), new_list);
}

static t_list	*exapnd_var_list_redir(t_list *lst)
{
	t_list	*new_list;
	t_list	*tmp;

	new_list = NULL;
	tmp = lst;
	while (lst)
	{
		if (lst->type != TK_SINGLE_QUOTE && iscontain_var(lst->value))
		{
			if (expand_redi_helper(&new_list, lst) == FALSE)
				return (ft_lstclear(&tmp), NULL);

		}
		else
			ft_lstadd_back(&new_list, nd_copy(lst));
		if (lst->type == TK_HERE_DOC)
		{
			ft_lstadd_back(&new_list, nd_copy(lst->next));
			lst = lst->next->next;
		}
		else
		lst = lst->next;
	}
	return (ft_lstclear(&tmp), new_list);
}

int	expander(t_tree *node)
{
	if (node->redirect_mode != NULL)
	{
		node->redirect_mode = exapnd_var_list_redir(node->redirect_mode);
		if (node->redirect_mode == NULL)
			return (redir_err(), FALSE);
	}
	node->lst = exapnd_var_list_cmd(node->lst);
	node->redirect_mode = concater(node->redirect_mode);
	node->lst = concater(node->lst);
	if (wildcard_redir(node->redirect_mode) == FALSE)
	{
		g_pub.exit_status = 1;
		return (FALSE);
	}
	wildcard_cmd(node->lst);
	return (TRUE);
}
