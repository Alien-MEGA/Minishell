/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/04 19:33:28 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_tree(t_tree *tree, int depth)
{
	if (tree == NULL)
		return ;
	print_tree(tree->right, depth + 4);
	for (int i = 0; i < depth; i++)
		printf(" ");
	printf("%s\n", tree->value);
	print_tree(tree->left, depth + 4);
}

void	print_lst(t_list *head)
{
	printf("[ ");
	for (int i = 0; head; i++)
	{
		printf("%s -> ", head->data);	
		head = head->next;	
	}
	printf("NULL ]\n\n");
}

int	check_type(t_list *lst, int type)
{
	int	i;

	i = 0;
	while (in(lst, i))
	{
		if (type == in(lst, i)->data.type)
			return (TRUE);
		i++;	
	}
	return (FALSE);
}


void	parser(t_list *lst)
{
	t_tree	*ast;
	int		i;

	while (in(lst, i))
	{
		if (in(lst, i)->data.type == TK_WORD)
		{
			ft_treeadd_back(&ast, ft_treenew(, ), LEFT);
		}
		
	}




















}







void	test()
{
	t_list	*lst;

	ft_lstadd_back(&lst, ft_lstnew("echo hoot"));
	ft_lstadd_back(&lst, ft_lstnew("|"));
	ft_lstadd_back(&lst, ft_lstnew("cat"));
	ft_lstadd_back(&lst, ft_lstnew("&&"));
	ft_lstadd_back(&lst, ft_lstnew("echo"));
	ft_lstadd_back(&lst, ft_lstnew("gam"));
	ft_lstadd_back(&lst, ft_lstnew("|"));
	ft_lstadd_back(&lst, ft_lstnew("cat"));
	print_lst(lst);
	ft_indexing(lst);
	parser(lst);
}

/* ====> Exemple : echo hoot | cat && echo gam | cat <====== */
/* ==============> TEST <============== */
// t_tree	*tree;

// tree = ft_treenew("&&", TK_AND);

// ft_treeadd_back(&tree, ft_treenew("|", TK_PIPE), RIGHT);
// ft_treeadd_back(&tree, ft_treenew("|", TK_PIPE), LEFT);

// ft_treeadd_back(&tree->left, ft_treenew("cat", TK_WORD), RIGHT);
// ft_treeadd_back(&tree->left, ft_treenew("ls", TK_WORD), LEFT);

// ft_treeadd_back(&tree->right, ft_treenew("cat", TK_WORD), LEFT);
// ft_treeadd_back(&tree->right, ft_treenew("ls", TK_WORD), RIGHT);
