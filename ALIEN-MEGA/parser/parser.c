/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/05 00:29:30 by reben-ha         ###   ########.fr       */
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
	printf("%s\n", tree->data);
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
	char	*cmd_str;
	char	**cmd_mat;

	cmd_str = NULL;
	while (start < end)
	{
		cmd_str = ft_strjoin_gnl(cmd_str, ((t_token *)in(lst, start)->data)->value);
		cmd_str = ft_strjoin_gnl(cmd_str, " ");	
		start++;
	}
	cmd_mat = ft_split(cmd_str, ' ');
	printf("==============> Print Cmd <============== \n");
	for (size_t i = 0; cmd_mat[i]; i++)
		printf(" %d :         %s\n", (int)i, cmd_mat[i]);
	return (cmd_mat);	
}

void	parser(t_list *lst)
{
	t_tree	*ast;
	int		i;
	char	**cmd_mat;

	// i = -1;
	// while (in(lst, ++i))
	// 	printf("%s == %d\n", ((t_token *)in(lst, i)->data)->value, ((t_token *)in(lst, i)->data)->type);

	ast = NULL;
	i = 0;
	while (((t_token *)in(lst, i)->data)->type == TK_WORD)
		i++;
	cmd_mat = make_cmd(lst, 0, i);
	printf("\n%p\n", ast);
	ft_treeadd_back(&ast, ft_treenew(cmd_mat), LEFT);

	// // ft_treeadd_front(&ast, ft_treenew(((t_token *)in(lst, i)->data)->value), LEFT);
	
	print_tree(ast, 10);










}

void	test()
{
	t_list	*lst;

	t_token token_1;
	token_1.value = ft_strdup("echo");
	token_1.type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(&token_1));

	t_token token_2;
	token_2.value = ft_strdup("hoot");
	token_2.type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(&token_2));

	t_token token_3;
	token_3.value = ft_strdup("|");
	token_3.type = TK_PIPE;
	ft_lstadd_back(&lst, ft_lstnew(&token_3));

	t_token token_4;
	token_4.value = ft_strdup("cat");
	token_4.type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(&token_4));

	t_token token_5;
	token_5.value = ft_strdup("&&");
	token_5.type = TK_PIPE;
	ft_lstadd_back(&lst, ft_lstnew(&token_5));

	t_token token_6;
	token_6.value = ft_strdup("echo");
	token_6.type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(&token_6));

	t_token token_7;
	token_7.value = ft_strdup("gam");
	token_7.type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(&token_7));

	t_token token_8;
	token_8.value = ft_strdup("|");
	token_8.type = TK_PIPE;
	ft_lstadd_back(&lst, ft_lstnew(&token_8));

	t_token token_9;
	token_9.value = ft_strdup("cat");
	token_9.type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(&token_9));

	ft_indexing(lst);
	print_lst(lst);
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
