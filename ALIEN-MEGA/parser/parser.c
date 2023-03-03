/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/03 22:20:32 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/* && → || → | → Word */

/* search for () */
/* else search for || or && */
/* else search for | */

void	print_tree(t_tree *tree, int depth)
{
	if (tree == NULL)
		return;
	print_tree(tree->right, depth + 4);
	for (int i = 0; i < depth; i++)
	{
		printf(" ");
	}
	printf("%s\n", tree->value);
	print_tree(tree->left, depth + 4);
}

void parser()
{
	t_tree *tree;

	tree = ft_treenew("&&", TK_AND);

	ft_treeadd_back(&tree, ft_treenew("|", TK_PIPE), RIGHT);
	ft_treeadd_back(&tree, ft_treenew("|", TK_PIPE), LEFT);

	ft_treeadd_back(&tree->left, ft_treenew("cat", TK_WORD), RIGHT);
	ft_treeadd_back(&tree->left, ft_treenew("ls", TK_WORD), LEFT);

	ft_treeadd_back(&tree->right, ft_treenew("cat", TK_WORD), LEFT);
	ft_treeadd_back(&tree->right, ft_treenew("ls", TK_WORD), RIGHT);
	print_tree(tree, 10);
}
