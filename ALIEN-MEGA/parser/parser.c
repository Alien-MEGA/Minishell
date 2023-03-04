/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/04 15:31:18 by reben-ha         ###   ########.fr       */
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

void	parser(t_list *lst)
{
	




	
}




































































	
void	def_pri(t_list *lst)
{
	int		prio;
	int		switch_side;

	lst->data->		   
	                                   
	switch_side = LEFT;
	while (in(lst, i))
	{
		if (in(lst, i)->data->type == TK_AND
			|| in(lst, i)->data->type == TK_OR)
		{
			in(lst, i)->level_tree = TOP;
			in(lst, i)->level_side = -1;
			level_tree++;
		}
		else if (in(lst, i)->data->type == TK_PIPE)
		{
			in(lst, i)->level_tree = level_tree;
			in(lst, i)->level_side = switch_side;
			level_tree++;
		}
		else if (in(lst, i)->data->type == TK_WORD)
		{
			in(lst, i)->level_tree = 2;
			in(lst, i)->level_side = switch_side;
			level_tree++;
		}
		i++;
	}
}

// void	parser(t_list *lst)
// {
// 	/* && → || → | → Word */

// 	/* search for () */
// 	/* else search for || or && */
// 	/* else search for | */
// 	// def_pri();
// 	print_tree(tree, 10);
// }

// void	test()
// {
// 	t_list	*lst;

// 	ft_lstadd_back(&lst, ft_lstnew("echo hoot"));
// 	ft_lstadd_back(&lst, ft_lstnew("|"));
// 	ft_lstadd_back(&lst, ft_lstnew("cat"));
// 	ft_lstadd_back(&lst, ft_lstnew("&&"));
// 	ft_lstadd_back(&lst, ft_lstnew("echo"));
// 	ft_lstadd_back(&lst, ft_lstnew("gam"));
// 	ft_lstadd_back(&lst, ft_lstnew("|"));
// 	ft_lstadd_back(&lst, ft_lstnew("cat"));
// 	print_lst(lst);
// 	ft_indexing(lst);
// 	parser(lst);
// }

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
