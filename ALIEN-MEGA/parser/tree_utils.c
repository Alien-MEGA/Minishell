/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:51:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/02 21:37:53 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree	*ft_treenew(char *value, int type)
{
	t_tree	*new_node;

	new_node = (t_tree *)malloc(sizeof(t_tree));
	ft_error_str(new_node, 1);
	new_node->value = value;
	new_node->type = type;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

t_tree	*ft_treelast(t_tree *tree, int option)
{
	if (tree == NULL)
		return (NULL);
	if (option == LEFT)
		while (tree->left != NULL)
			tree = tree->left;
	if (option == RIGHT)
		while (tree->right != NULL)
			tree = tree->right;
	return (tree);
}

void	ft_treeadd_back(t_tree **tree, t_tree *new, int option)
{
	t_tree	*last;

	if (!tree)
		return ;
	if (!(*tree))
	{
		*tree = new;
		return ;
	}
	last = ft_treelast(*tree, option);
	if (option == LEFT)
		last->left = new;
	if (option == RIGHT)
		last->right = new;
}

void	ft_treeadd_front(t_tree **tree, t_tree *new, int option)
{
	if (*tree && option == LEFT)
		new->left = *tree;
	if (*tree && option == RIGHT)
		new->right = *tree;
	*tree = new;
}

void	ft_treeclear(t_tree **tree)
{
	t_tree	*tmp_left;
	t_tree	*tmp_right;

	tmp_left = (*tree)->left;
	tmp_right = (*tree)->right;
	free(*tree);
	while (tmp_left)
	{
		tmp_left = (*tree)->left;
		free(*tree);
		*tree = tmp_left;
	}
	while (tmp_right)
	{
		tmp_right = (*tree)->right;
		free(*tree);
		*tree = tmp_right;
	}
}
