/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:23:34 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/27 02:33:20 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

static int	ismatch(char *wd_card, char *word)
{
	if (*wd_card == '\0' && *word == '\0')
		return (TRUE);
	if (*wd_card == '*')
	{
		while (*(wd_card + 1) == '*')
			wd_card++;
	}
	if (*wd_card == '*' && *(wd_card + 1) != '\0' && *word == '\0')
		return (FALSE);
	if (*wd_card == *word)
		return (ismatch(wd_card + 1, word + 1));
	if (*wd_card == '*')
		return (ismatch(wd_card + 1, word) || ismatch(wd_card, word + 1));
	return (FALSE);
}

static t_list	*wild_card_expand(char *exper)
{
	t_list	*nlst;
	t_list	*lstfile;
	t_list	*tmp;

	lstfile = get_ls();
	tmp = lstfile;
	nlst = NULL;
	if (lstfile == NULL)
		return (NULL);
	while (lstfile)
	{
		if (ismatch(exper, lstfile->value))
		{
			ft_lstadd_back(&nlst, ft_lstnew(0, ft_strdup(lstfile->value), 0));
			ft_lstadd_back(&nlst, ft_lstnew(TK_WT_SPACE, ft_strdup(" "), NULL));
		}
	lstfile = lstfile->next;
	}
	ft_lstclear(&tmp);
	free(tmp);
	return (nlst);
}

static	void	ft_insert(t_list **head, t_list *newlst)
{
	t_list	*headnext;
	t_list	*tmp;

	headnext = (*head)->next;
	if (headnext != NULL && headnext->type == TK_WT_SPACE)
	{
		tmp = headnext;
		headnext = headnext->next;
		free(tmp->value);
		free(tmp);
	}
	free((*head)->value);
	(*head)->value = newlst->value;
	(*head)->value = newlst->value;
	(*head)->next = newlst->next;
	ft_lstadd_back(head, headnext);
	free(newlst);
}

void	wildcard_cmd(t_list *list)
{
	t_list	*nlst;
	int		per_type;
	int		bool;

	per_type = TK_WT_SPACE;
	while (list)
	{
		bool = (list->type == TK_WORD && (!istype(per_type, T_W)));
		if (indexofchar(list->value, '*') != -1 && bool)
		{
			nlst = wild_card_expand(list->value);
			if (nlst != NULL)
				ft_insert(&list, nlst);
		}
	per_type = list->type;
	list = list->next;
	}
}

int	wildcard_redir(t_list *list)
{
	t_list	*nlst;
	int		per_type;
	int		len;

	per_type = -1;
	while (list)
	{
		if (list->type == TK_WORD &&  indexofchar(list->value, '*') != -1 && per_type != TK_HERE_DOC)
		{
			nlst = wild_card_expand(list->value);
			len = ft_lstsize(nlst);
			if (len > 1)
			{
				ft_printf(STDERR_FILENO, "minishell:*: ambiguous redirect");
				ft_lstclear(&nlst);
				return (FALSE);
			}
			if (nlst != NULL)
				ft_insert(&list, nlst);
		}
		if (list->type == TK_HERE_DOC)
			per_type = list->type;
		list = list->next;
	}
	return (TRUE);
}
