/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:27:22 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/07 21:19:18 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree	*create_command(t_list *lst, int *i)
{
	t_list	*new_lst;
	int		start;
	int		end;

	new_lst = NULL;
	start = (*i);
	/* this while stop there is one of this type 
	(PIPE, HERE_DOC, RD_INPUT, RD_OUTPUT, RD_OUTPUT_APPEND, AND, OR) */
	while (in(lst, (*i)) && (in(lst, (*i))->type >= TK_PIPE && in(lst, (*i))->type <= TK_OR))
	{
		ft_lstadd_back(&new_lst,
			ft_lstnew(in(lst, start)->type, in(lst, start)->value, NULL));
		(*i)++;
	}
	return (ft_treenew(new_lst));
}

t_tree	*create_operator(t_list *lst, int *i)
{
	t_tree	*operator;

	operator = ft_treenew(ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
	(*i)++;
	return (operator);
}

t_tree	*create_redirect(t_list *lst, int *i)
{
	t_list	*new_node;

	ft_lstadd_back(&new_node, ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
	(*i)++;
	ft_lstadd_back(&new_node, ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
	(*i)++;
	return (ft_treenew(new_node));
}
