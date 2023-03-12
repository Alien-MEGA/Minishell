/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:27:22 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/13 00:03:32 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	skip_space(t_list *lst, int *i)
{
	if (in(lst, (*i))->type == TK_WT_SPACE)
		(*i)++;
}

void	search_rd(t_list **new_rd, t_list *lst, int *i)
{
	while (in(lst, (*i)) && in(lst, (*i))->type >= TK_RD_INPUT
		&& in(lst, (*i))->type <= TK_RD_OUTPUT_APPEND)
	{
		ft_lstadd_back(new_rd, create_redirect(lst, i));
		skip_space(lst, i);
	}
}

t_tree	*create_command(t_list *lst, int *i)
{
	t_tree	*new_tree;
	t_list	*new_lst;
	t_list	*new_rd;

	new_lst = NULL;
	new_rd = NULL;
	skip_space(lst, i);
	search_rd(&new_rd, lst, i);
	while (in(lst, (*i))
		&& !(in(lst, (*i))->type >= TK_PIPE
		&& in(lst, (*i))->type <= TK_OR))
	{
		ft_lstadd_back(&new_lst,
			ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
		(*i)++;
		if (in(lst, (*i)) && in(lst, (*i) + 1)
			&& in(lst, (*i) + 1)->type >= TK_PIPE
			&& in(lst, (*i) + 1)->type <= TK_OR)
			skip_space(lst, i);	
	}
	search_rd(&new_rd, lst, i);
	new_tree = ft_treenew(new_lst);
	new_tree->redirect_mode = new_rd;
	return (new_tree);
}

t_tree	*create_operator(t_list *lst, int *i)
{
	t_tree	*operator;

	operator = ft_treenew(ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
	(*i)++;
	return (operator);
}

t_list	*create_redirect(t_list *lst, int *i)
{
	t_list	*new_node;

	new_node = NULL;
	ft_lstadd_back(&new_node, ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
	(*i)++;
	ft_lstadd_back(&new_node, ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
	(*i)++;
	ft_lstadd_back(&new_node, ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
	(*i)++;
	return (new_node);
}
