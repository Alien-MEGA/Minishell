/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/10 16:54:49 by reben-ha         ###   ########.fr       */
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

t_tree	*mk_tree(t_list *lst)
{
	t_tree	*tree;
	t_tree	*new_node;
	int		i;

	i = 0;
	tree = NULL;
	while (in(lst, i))
	{
		if (in(lst, i)->type == TK_PIPE
			|| in(lst, i)->type == TK_OR
			|| in(lst, i)->type == TK_AND)
		{
			new_node = create_operator(lst, &i);
		}
		else if (in(lst, i)->type == TK_WORD
			|| in(lst, i)->type == TK_RD_OUTPUT
			|| in(lst, i)->type == TK_RD_OUTPUT_APPEND
			|| in(lst, i)->type == TK_RD_INPUT
			|| in(lst, i)->type == TK_HERE_DOC)
		{
			new_node = create_command(lst, &i);
		}
		if (!tree)
			tree = new_node;
		else
			ft_treelast(tree, LEFT)->left = new_node;
	}
	return (tree);
}

void	test()
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(TK_RD_INPUT, ft_strdup("<"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("infile"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("echo"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("-n"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("hoot"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_PIPE, ft_strdup("|"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("cat"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_OR, ft_strdup("||"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("ls"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("-l"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("-a"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_PIPE, ft_strdup("|"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("cat"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_RD_OUTPUT, ft_strdup(">"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("outfile"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_RD_OUTPUT, ft_strdup(">"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("of"), NULL));
	ft_indexing(lst);
	print_lst(lst);
	printf("\n\n");


	mk_tree(lst);
	
}
/* ==============> Test <============== */
	// t_tree *tree = mk_tree(lst);
	// t_list *tmp;
	// for (size_t i = 0; tree != NULL ; i++)
	// {
	// 	tmp = tree->lst;
	// 	while (tmp)
	// 	{
	// 		printf("%s -> ", tmp->value);
	// 		tmp = tmp->next;
	// 	}
	// 	if (tree->redirect_mode != NULL)
	// 	{
	// 		printf("++> redirect_mode : ");
	// 		tmp = tree->redirect_mode;
	// 		while (tmp)
	// 		{
	// 			printf("%s -> ", tmp->value);
	// 			tmp = tmp->next;
	// 		}
	// 	}
	// 	printf("\n");
	// 	tree = tree->left;
	// }