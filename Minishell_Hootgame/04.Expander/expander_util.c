/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:04:18 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/04 18:32:06 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

static t_list	*remove_empty(t_list *lst)
{
	int		prev;
	t_list	*nlst;
	t_list	*tmp;

	prev = TK_AND;
	nlst = NULL;
	tmp = lst;
	while (lst)
	{
		if (lst->value[0] == '\0')
		{
			if (!(istype(prev, T_W) || (lst->next
					&& !istype(lst->next->type, T_W))))
			{
				ft_lstadd_back(&nlst,
					ft_lstnew(lst->type, ft_strdup(lst->value), NULL));
				prev = lst->type;
			}
		}
		else
		{
			ft_lstadd_back(&nlst, ft_lstnew(lst->type, ft_strdup(lst->value), NULL));
			prev = lst->type;
		}
		lst = lst->next;
	}
	return (ft_lstclear(&tmp), nlst);
}

static t_list	*remove_sapce(t_list *lst)
{
	int		prev;
	int		bool;
	t_list	*nlst;
	t_list	*tmp;

	prev = -1;
	nlst = NULL;
	tmp = lst;
	while (lst)
	{
		bool = (!istype(prev, T_W)
				|| !lst->next || !istype(lst->next->type, T_W));
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

t_list	*ft_filter(t_list *lst)
{
	t_list	*tmp;

	//tmp = remove_empty(lst);
	return (remove_sapce(lst));
}
