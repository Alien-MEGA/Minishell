/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:29:58 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/10 01:08:07 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static int	gettype(int type, char *value, int prev_tk)
{
	int	bool1;
	int	bool2;

	bool1 = type != TK_WORD;
	bool2 = indexofchar(value, '*') > 0;
	return (bool1 && (bool2 || prev_tk == TK_HERE_DOC));
}

static char	*getword(t_list **lst, int *type, int prev)
{
	char	*value;
	int		bool;

	value = ft_strdup((*lst)->value);
	ft_error_str(value, 1);
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
	int		tp;
	int		prev;
	t_list	*tmp;

	newlist = NULL;
	tmp = lst;
	while (lst)
	{
		tp = TK_WORD;
		if (istype(lst->type, T_W) && istype(nxt_type(lst), T_W))
			ft_lstadd_back(&newlist, ft_lstnew(tp,
					getword(&lst, &tp, prev), NULL));
		else
		{
			ft_lstadd_back(&newlist, nd_copy(lst));
			prev = lst->type;
			lst = lst->next;
		}
	}
	return (ft_lstclear(&tmp), newlist);
}

t_list	*concater_heredoc(t_list *lst)
{
	t_list	*newlist;
	char	*new_value;
	int		tp;
	int		prev;
	t_list	*tmp;

	tmp = lst;
	newlist = NULL;
	while (lst)
	{
		tp = TK_WORD;
		if (prev == TK_HERE_DOC && istype(lst->type, T_W)
			&& istype(nxt_type(lst), T_W))
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
	return (ft_lstclear(&tmp), newlist);
}
