/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:29:58 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/24 18:07:15 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*getword(t_list **lst, int *type)
{
	char	*value;
	char	*tmp;

	value = ft_strdup((*lst)->value);
	if ((*lst)->type != TK_WORD && indexofchar((*lst)->value, '*') != -1)
		*type = TK_DOUBLE_QUOTE;
	*lst = (*lst)->next;
	while (*lst && istype((*lst)->type, T_W))
	{
		if ((*lst)->type != TK_WORD && indexofchar((*lst)->value, '*') != -1)
			*type = TK_DOUBLE_QUOTE;
		value = ft_strjoin_gnl(value, (*lst)->value);
		*lst = (*lst)->next;
	}
	return (value);
}

t_list	*concater(t_list *lst)
{
	t_list	*newlist;
	char	*new_value;
	int		tp;

	newlist = NULL;
	while (lst)
	{
		tp = TK_WORD;
		if (istype(lst->type, T_W) && (lst->next
				&& istype(lst->next->type, T_W)))
		{
			new_value = getword(&lst, &tp);
			ft_lstadd_back(&newlist, ft_lstnew(tp, new_value, NULL));
		}
		else
		{
			ft_lstadd_back(&newlist,
				ft_lstnew(lst->type, ft_strdup(lst->value), NULL));
			lst = lst->next;
		}
	}
	return (newlist);
}
