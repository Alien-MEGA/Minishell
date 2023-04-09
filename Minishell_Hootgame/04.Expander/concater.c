/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:29:58 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/09 05:42:15 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static int	gettype(int type, char *value, int prev_tk)
{
	int	bool1;
	int	bool2;

	bool1 = type != TK_WORD;
	bool2 = indexofchar(value, '*') > 0 || prev_tk == TK_HERE_DOC;
	return (bool1 && bool2);
}

static char	*getword(t_list **lst, int *type, int prev)
{
	char	*value;
	int		bool;

	value = ft_strdup((*lst)->value);

	if (gettype((*lst)->type, (*lst)->value, prev))
		*type = TK_DOUBLE_QUOTE;
	*lst = (*lst)->next;
	while (*lst && istype((*lst)->type, T_W))
	{
		if (gettype((*lst)->type, (*lst)->value, prev))
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
	int		prev;

	newlist = NULL;
	while (lst)
	{
		tp = TK_WORD;
		if (istype(lst->type, T_W) && (lst->next
				&& istype(lst->next->type, T_W)))
		{
			new_value = getword(&lst, &tp, prev);
			ft_lstadd_back(&newlist, ft_lstnew(tp, new_value, NULL));
		}
		else
		{
			ft_lstadd_back(&newlist,
				ft_lstnew(lst->type, ft_strdup(lst->value), NULL));
			prev = lst->type;
			lst = lst->next;
		}
	}
	return (newlist);
}

t_list	*concater_heredoc(t_list *lst)
{
	t_list	*newlist;
	char	*new_value;
	int		tp;
	int		prev;

	newlist = NULL;
	while (lst)
	{
		tp = TK_WORD;
		if (prev == TK_HERE_DOC && istype(lst->type, T_W)
			&& (lst->next && istype(lst->next->type, T_W)))
		{
			new_value = getword(&lst, &tp, prev);
			ft_lstadd_back(&newlist, ft_lstnew(tp, new_value, NULL));
		}
		else
		{
			ft_lstadd_back(&newlist, nd_copy(lst));
			prev = lst->type;
			lst = lst->next;
		}
	}
	return (newlist);
}
