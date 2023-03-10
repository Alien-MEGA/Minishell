/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:53:06 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/10 17:53:52 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_tree(t_tree *tree)
{
	if (tree == NULL)
		return;

	printf("						%s								\n", tree->lst->value);

	if (tree->left != NULL && tree->right != NULL) {
		printf("		  %s							%s				\n", tree->left->lst->value, tree->right->lst->value);
		if (tree->left->left != NULL && tree->left->right != NULL && tree->right->left != NULL && tree->right->right != NULL) {
			printf("%s					%s			%s				%s		\n", tree->left->left->lst->value, tree->left->right->lst->value, tree->right->left->lst->value, tree->right->right->lst->value);
		}
	}

	// recursively print left and right subtrees
	print_tree(tree->left);
	print_tree(tree->right);
}

void	print_lst(t_list *head)
{
	printf("==============> Print lst <==============\n\n");
	for (size_t i = 0; in(head, i); i++)
		printf("%s --> ", (in(head, i)->value));
	printf("NULL \n");
}

int	check_type(t_list *lst, int type)
{
	int	i;

	i = 0;
	while (in(lst, i))
	{
		if (type == lst->type)
			return (TRUE);
		i++;	
	}
	return (FALSE);
}
