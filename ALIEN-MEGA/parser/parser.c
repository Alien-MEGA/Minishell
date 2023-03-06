/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/06 22:05:29 by reben-ha         ###   ########.fr       */
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
	for (size_t i = 0; in(head, i); i++)
		printf("%s --> ", (char *)(in(head, i)->data));
	printf("NULL ]\n\n");
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

void	parser(t_list *lst)
{
	t_tree	*tree;
	int		i;

	i = -1;
	while (in(lst, ++i))
	{
		if (in(lst, i)->type == TK_PIPE
			|| in(lst, i)->type == TK_OR
			|| in(lst, i)->type == TK_AND)
		{
			create_operator(lst, &i);
		}
		else if (in(lst, i)->type == TK_WORD)
		{
			create_command(lst, &i);
		}
		else if (in(lst, i)->type == TK_RD_OUTPUT
			|| in(lst, i)->type == TK_RD_OUTPUT_APPEND
			|| in(lst, i)->type == TK_RD_INPUT
			|| in(lst, i)->type == TK_HERE_DOC)
		{
			create_redirect(lst, &i);
		}
	}







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
	parser(lst);

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
