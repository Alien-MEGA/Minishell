/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:51:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/10 04:36:29 by reben-ha         ###   ########.fr       */
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

void	ft_treeclear(t_tree **tree)
{
	if (!tree || !(*tree))
		return ;
	ft_treeclear(&(*tree)->left);
	ft_treeclear(&(*tree)->right);
	ft_lstclear(&(*tree)->lst);
	ft_lstclear(&(*tree)->redirect_mode);
	free(*tree);
}
