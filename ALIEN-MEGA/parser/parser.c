/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/06 17:55:26 by reben-ha         ###   ########.fr       */
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

char	**make_cmd(t_list *lst, int start, int end)
{
	char	*cmd;

	cmd = NULL;
	while (start < end)
	{
		cmd = ft_strjoin_gnl(cmd, ((t_token *)in(lst, start)->data)->value);
		cmd = ft_strjoin_gnl(cmd, " ");	
		start++;
	}
	printf("==============> Print Cmd <============== \n");
		printf("%s\n", cmd);
	return (cmd);	
}

void	parser(t_list *lst)
{
	t_tree	*tree;
	int		i;

	
	








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
