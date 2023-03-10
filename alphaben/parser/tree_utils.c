// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   tree_utils.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/02 20:51:26 by reben-ha          #+#    #+#             */
// /*   Updated: 2023/03/09 17:05:09 by reben-ha         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../minishell.h"

// t_tree	*ft_treenew(t_list *lst)
// {
// 	t_tree	*new_node;

// 	new_node = (t_tree *)malloc(sizeof(t_tree));
// 	ft_error_str(new_node, 1);
// 	new_node->lst = lst;
// 	new_node->redirect_mode = NULL;
// 	new_node->left = NULL;
// 	new_node->right = NULL;
// 	return (new_node);
// }

// t_tree	*ft_treelast(t_tree *tree, int option)
// {
// 	if (tree == NULL)
// 		return (NULL);
// 	if (option == LEFT)
// 		while (tree->left != NULL)
// 			tree = tree->left;
// 	if (option == RIGHT)
// 		while (tree->right != NULL)
// 			tree = tree->right;
// 	return (tree);
// }

// void	ft_treeadd_back(t_tree **tree, t_tree *new, int option)
// {
// 	t_tree	*last;

// 	if (!tree)
// 		return ;
// 	if (!(*tree))
// 	{
// 		*tree = new;
// 		return ;
// 	}
// 	if (option == LEFT)
// 		(*tree)->left = new;
// 	if (option == RIGHT)
// 		(*tree)->right = new;
// }

// void	ft_treeswap_root(t_tree **tree, t_tree *new, int option)
// {
// 	if (*tree && option == LEFT)
// 		new->left = *tree;
// 	if (*tree && option == RIGHT)
// 		new->right = *tree;
// 	*tree = new;
// }

// void	ft_treeclear(t_tree **tree)
// {
// 	if ((*tree)->left != NULL)
// 		ft_treeclear(&(*tree)->left);
// 	if ((*tree)->right != NULL)
// 		ft_treeclear(&(*tree)->right);
// 	free(*tree);
// }
 