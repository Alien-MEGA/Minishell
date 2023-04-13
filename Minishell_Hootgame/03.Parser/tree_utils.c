/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:51:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/13 22:12:07 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

t_tree	*ft_treenew(t_list *lst)
{
	t_tree	*new_node;

	new_node = (t_tree *)malloc(sizeof(t_tree));
	ft_error_str(new_node, 1);
	new_node->lst = lst;
	new_node->redirect_mode = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

void	ft_treeswap_root(t_tree **tree, t_tree *new, int option)
{
	if (*tree && option == LEFT)
		new->left = *tree;
	if (*tree && option == RIGHT)
		new->right = *tree;
	*tree = new;
}

static void	rm_tmp_file(t_list *redirect)
{
	while (redirect)
	{
		if (redirect->type == TK_HERE_DOC
			&& redirect->next != NULL)
			unlink(redirect->next->value);
		redirect = redirect->next;
	}
}

void	ft_treeclear(t_tree **tree)
{
	if (!tree || !(*tree))
		return ;
	ft_treeclear(&(*tree)->left);
	ft_treeclear(&(*tree)->right);
	ft_lstclear(&(*tree)->lst);
	rm_tmp_file((*tree)->redirect_mode);
	ft_lstclear(&(*tree)->redirect_mode);
	free(*tree);
	*tree = NULL;
}
