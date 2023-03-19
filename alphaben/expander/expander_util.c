/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:04:18 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/19 18:57:14 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


t_list	*ft_fillter(t_list *lst)
{
	int prev;
	t_list	*newlst;
	t_list *tmp;

	prev = -1;
	newlist = NULL;
	tmp = lst;
	while (lst)
	{
		if (lst->vlaue[0] == 0)
		{
			if (!(istype(prev, TP_WORD) ||(lst->next != NULL && istype(lst->type, TP_WORD))))
			{
				ft_lstadd_back(newlst, ft_lstnew(lst->type, lst->value, NULL));
				prev = lst->type;
			}
			else
			prev = TK_WT_SPACE;

		}
		esle
		{
			ft_lstadd_back(newlst, ft_lstnew(lst->type, lst->value, NULL));
			prev = lst->type;
		}
		lst = lst->next;
	}
	return(ft_lstclear(tmp), new)
}
