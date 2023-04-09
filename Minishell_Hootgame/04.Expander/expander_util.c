/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:04:18 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/09 03:48:43 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

int iscontain_var(char *word)
{
	int i;
	int bool;

	i = 0;
	if (!word || indexofchar(word, '$') == -1)
		return (FALSE);
	while (word[i])
	{
		bool = word[i + 1] == '_' || (ft_isalpha(word[i + 1]) || word[i + 1] == '?');
		if (word[i] == '$' && bool)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_list *ft_filter(t_list *lst)
{
	int prev;
	int bool;
	t_list *nlst;
	t_list *tmp;

	prev = -1;
	nlst = NULL;
	tmp = lst;
	while (lst)
	{
		bool = (!istype(prev, T_W) || !lst->next || !istype(lst->next->type, T_W));
		if (lst->type == TK_WT_SPACE && bool)
			prev = -1;
		else
		{
			ft_lstadd_back(&nlst, ft_lstnew(lst->type,
											ft_strdup(lst->value), 0));
			prev = lst->type;
		}
		lst = lst->next;
	}
	return (ft_lstclear(&tmp), nlst);
}

t_list *get_list_form_var(t_list *lst)
{
	char **words;
	t_list *nlst;
	int i;

	i = 0;
	nlst = NULL;
	words = ft_split(lst->value, ' ');
	if (words[0] == NULL)
		return (free(words), NULL);
	else if (lst->type == TK_WORD && ft_strlen(lst->value) > 0)
	{
		while (words[i])
		{
			ft_lstadd_back(&nlst, ft_lstnew(TK_WORD, words[i], NULL));
			if (words[i + 1] != NULL)
				ft_lstadd_back(&nlst, ft_lstnew(TK_WT_SPACE, ft_strdup(" "), NULL));
			i++;
		}
		free(words);
		return (nlst);
	}
	return (NULL);
}

void insert_list(t_list **head, t_list *lst)
{
	t_list *nlst;
	nlst = NULL;
	if (lst->type == TK_WORD && lst->value[0] != '\0')
	{
		nlst = get_list_form_var(lst);
		if (nlst != NULL)
		{
			if (*head == NULL)
				*head = nlst;
			else
			{
				(*head)->next = nlst;
				*head = ft_lstlast(*head);
			}
		}
	}
}
