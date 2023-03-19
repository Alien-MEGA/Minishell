/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:23:34 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/19 17:32:36 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int ismatch(char *wd_card, char *word)
{
	if (*wd_card == '\0' && *word == '\0')
		return (TRUE);
	if (*wd_card == '*')
	{
		while (*(wd_card + 1) == '*')
			wd_card++;
	}
	if (*wd_card == '*' && *(wd_card + 1) != '\0' && *word == '\0')
		return FALSE;
	if (*wd_card == *word)
		return ismatch(wd_card + 1, word + 1);

	if (*wd_card == '*')
		return ismatch(wd_card + 1, word) || ismatch(wd_card, word + 1);
	return (FALSE);
}

t_list	*wild_card_expand(char *exper)
{
	t_list	*newlist;
	t_list	*list_file;
	t_list	*tmp;


	list_file = get_ls();
	tmp = list_file;
	newlist = NULL;
	if (list_file == NULL)
		return (NULL);
	while (list_file)
	{
		if (ismatch(exper, list_file->value))
		{
			ft_lstadd_back(&newlist, ft_lstnew(TK_WORD, ft_strdup(list_file->value), NULL));
			ft_lstadd_back(&newlist, ft_lstnew(TK_WT_SPACE, ft_strdup(" "), NULL));
		}
	list_file = list_file->next;
	}
	ft_lstclear(&tmp);
	free(tmp);
	return (newlist);
}

static	void ft_insert(t_list **head, t_list *newlst)
{
	t_list *headnext;

	headnext = (*head)->next;

	free((*head)->value);
	(*head)->value = newlst->value;
	(*head)->value = newlst->value;
	(*head)->next = newlst->next;
	ft_lstadd_back(head, headnext);
	free(newlst);
}

void	wildcard(t_list *list)
{
	t_list	*newlist;
	int per_type;
	int bool;

	per_type = TK_WT_SPACE;
	while (list)
	{
		bool = list->type == TK_WORD && (!istype(per_type, TP_WORD) && per_type != TK_HERE_DOC);
		if (indexofchar(list->value, '*') != -1 && bool)
		{
			newlist = wild_card_expand(list->value);
			if (newlist != NULL)
				ft_insert(&list, newlist);
		}

	per_type = list->type;
	list = list->next;
	}
}
