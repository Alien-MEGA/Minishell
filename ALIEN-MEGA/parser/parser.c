/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/06 17:39:58 by reben-ha         ###   ########.fr       */
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
