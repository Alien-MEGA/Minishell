/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/06 23:45:02 by reben-ha         ###   ########.fr       */
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
	printf("==============> Print lst <==============\n\n");
	for (size_t i = 0; in(head, i); i++)
		printf("%s --> ", (in(head, i)->value));
	printf("NULL \n");
}

int	check_type(t_list *lst, int type)
{
	int	i;
	t_token *tk;

	i = 0;
	while (in(lst, i))
	{
		tk = (t_token *)in(lst, i)->data;
		if (type == tk->type)
			return (TRUE);
		i++;	
	}
	return (FALSE);
}

t_tree	*parser(t_list *lst)
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
		else if (in(lst, i)->type == TK_WORD)
		{
			new_node = create_command(lst, &i);
		}
		else if (in(lst, i)->type == TK_RD_OUTPUT
			|| in(lst, i)->type == TK_RD_OUTPUT_APPEND
			|| in(lst, i)->type == TK_RD_INPUT
			|| in(lst, i)->type == TK_HERE_DOC)
		{
			new_node = create_redirect(lst, &i);
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

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("echo"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("hoot"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_PIPE, ft_strdup("|"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("cat"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_PIPE, ft_strdup("&&"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("echo"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("gam"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_PIPE, ft_strdup("|"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("cat"), NULL));
	ft_indexing(lst);
	print_lst(lst);




	// t_tree *test_tree;
	// int i = 0;

	// printf("\n==============> Start test : 1 <==============\n");
	// printf("%s\n", in(lst, i)->value);
	// test_tree = create_command(lst, &i);
	// printf("new index = %d -> %d : %s\n", i, test_tree->type, test_tree->value);

	// printf("\n==============> Start test : 2 <==============\n");
	// printf("%s\n", in(lst, i)->value);
	// test_tree = create_operator(lst, &i);
	// printf("new index = %d -> %d : %s\n", i, test_tree->type, test_tree->value);

	// printf("\n==============> Start test : 3 <==============\n");
	// printf("%s\n", in(lst, i)->value);
	// test_tree = create_command(lst, &i);
	// printf("new index = %d -> %d : %s\n", i, test_tree->type, test_tree->value);

	// printf("\n==============> Start test : 4 <==============\n");
	// printf("%s\n", in(lst, i)->value);
	// test_tree = create_command(lst, &i);
	// printf("new index = %d -> %d : %s\n", i, test_tree->type, test_tree->value);



	for (t_tree *tree = parser(lst); tree; tree = tree->left)
		printf("%d : %s\n", tree->type, tree->value);
	// print_tree(tree, 10);
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
