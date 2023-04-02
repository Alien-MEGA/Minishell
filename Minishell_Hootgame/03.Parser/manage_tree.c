/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:27:22 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/02 00:29:31 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

void	skip_space(t_list **lst)
{
	if ((*lst) && (*lst)->type == TK_WT_SPACE)
		(*lst) = (*lst)->next;
}

void	search_rd(t_list **new_rd, t_list **lst)
{
	while ((*lst) && (*lst)->type >= TK_HERE_DOC
		&& (*lst)->type <= TK_RD_OUTPUT_APPEND)
	{
		ft_lstadd_back(new_rd, create_redirect(lst));
		skip_space(lst);
	}
}

t_tree	*create_command(t_list **lst)
{
	t_tree	*new_tree;
	t_list	*new_lst;
	t_list	*new_rd;

	new_lst = NULL;
	new_rd = NULL;
	skip_space(lst);
	if ((*lst) && (*lst)->type == TK_OPEN_BRACE)
		return (bracket_handle(lst));
	search_rd(&new_rd, lst);
	if ((*lst) && (*lst)->type == TK_OPEN_BRACE)
		return (syntax_error((*lst)->value), NULL);
	while ((*lst)
		&& !((*lst)->type >= TK_PIPE
			&& (*lst)->type <= TK_OR)
		&& (*lst)->type != TK_CLOSE_BRACE)
	{
		ft_lstadd_back(&new_lst,
			ft_lstnew((*lst)->type, (*lst)->value, NULL));
			(*lst) = (*lst)->next;
		if ((*lst) && (*lst)->next
			&& (((*lst)->next->type >= TK_PIPE && (*lst)->next->type <= TK_OR)
				|| (*lst)->next->type == TK_CLOSE_BRACE))
			skip_space(lst);
	}
	if ((*lst) && (*lst)->type == TK_OPEN_BRACE)
		return (bracket_handle(lst));
	search_rd(&new_rd, lst);
	if ((*lst) && (*lst)->type == TK_OPEN_BRACE)
		return (bracket_handle(lst));
	new_tree = ft_treenew(new_lst);
	new_tree->redirect_mode = new_rd;
	return (new_tree);
}

t_tree	*create_operator(t_list **lst)
{
	t_tree	*operator;

	operator = ft_treenew(ft_lstnew((*lst)->type, (*lst)->value, NULL));
		(*lst) = (*lst)->next;
	return (operator);
}

t_list	*create_redirect(t_list **lst)
{
	t_list	*new_node;

	new_node = NULL;
	ft_lstadd_back(&new_node, ft_lstnew((*lst)->type, (*lst)->value, NULL));
		(*lst) = (*lst)->next;
	skip_space(lst);
	while ((*lst)
		&& !((*lst)->type >= TK_PIPE
			&& (*lst)->type <= TK_WT_SPACE))
	{
		ft_lstadd_back(&new_node, ft_lstnew((*lst)->type, (*lst)->value, NULL));
		(*lst) = (*lst)->next;
	}
	return (new_node);
}
