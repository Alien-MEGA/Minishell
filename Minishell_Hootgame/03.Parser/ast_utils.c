/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:27:22 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/11 00:07:32 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static t_list	*create_redirect(t_list **lst)
{
	t_list	*new_node;

	new_node = NULL;
	ft_lstadd_back(&new_node, nd_copy(*lst));
		(*lst) = (*lst)->next;
	skip_space(lst);
	while ((*lst)
		&& !((*lst)->type >= TK_PIPE
			&& (*lst)->type <= TK_WT_SPACE))
	{
		ft_lstadd_back(&new_node, nd_copy(*lst));
		(*lst) = (*lst)->next;
	}
	return (new_node);
}

static void	search_rd(t_list **new_rd, t_list **lst)
{
	while ((*lst) && (*lst)->type >= TK_HERE_DOC
		&& (*lst)->type <= TK_RD_OUTPUT_APPEND)
	{
		ft_lstadd_back(new_rd, create_redirect(lst));
		skip_space(lst);
	}
}

static void	create_cmd(t_list **lst, t_list **new_lst)
{
	while ((*lst)
		&& !((*lst)->type >= TK_PIPE
			&& (*lst)->type <= TK_CLOSE_BRACE))
	{
		ft_lstadd_back(new_lst,
			nd_copy(*lst));
			(*lst) = (*lst)->next;
		if ((*lst) && (*lst)->next
			&& (*lst)->type >= TK_PIPE
			&& (*lst)->type <= TK_CLOSE_BRACE)
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
		return (g_pub.token_error = ft_strdup("("), NULL);
	create_cmd(lst, &new_lst);
	if ((*lst) && (*lst)->type == TK_OPEN_BRACE)
		return (g_pub.token_error = ft_strdup("("), NULL);
	search_rd(&new_rd, lst);
	if ((*lst) && (*lst)->type == TK_OPEN_BRACE)
		return (g_pub.token_error = ft_strdup("("), NULL);
	new_tree = ft_treenew(new_lst);
	new_tree->redirect_mode = new_rd;
	return (new_tree);
}

t_tree	*create_operator(t_list **lst)
{
	t_tree	*operator;

	operator = ft_treenew(nd_copy(*lst));
		(*lst) = (*lst)->next;
	return (operator);
}
