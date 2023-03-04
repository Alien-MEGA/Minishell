/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/04 22:03:34 by reben-ha         ###   ########.fr       */
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
	t_tree	*ast;
	int		i;
	int		j;
	char	*cmd_mat;

	i = 0;
	while (((t_token *)in(lst, i)->data)->type == TK_WORD)
		i++;
	/* ==============> make cmd matrix <============== */

	j = 0;
	while (j <= i)
	{
		ft_strjoin_gnl(cmd_mat, ((t_token *)in(lst, j)->data)->value);
		ft_strjoin_gnl(cmd_mat, " ");	
		j++;
	}
	printf("==> %s\n", cmd_mat);

	


















}

void	test()
{
	t_list	*lst;
	t_token	*token_s;

	token_s->value = "echo";
	token_s->type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(token_s));
	token_s->value = "hoot";
	token_s->type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(token_s));
	token_s->value = "|";
	token_s->type = TK_PIPE;
	ft_lstadd_back(&lst, ft_lstnew(token_s));
	token_s->value = "cat";
	token_s->type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(token_s));
	token_s->value = "&&";
	token_s->type = TK_PIPE;
	ft_lstadd_back(&lst, ft_lstnew(token_s));
	token_s->value = "echo";
	token_s->type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(token_s));
	token_s->value = "gam";
	token_s->type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(token_s));
	token_s->value = "|";
	token_s->type = TK_PIPE;
	ft_lstadd_back(&lst, ft_lstnew(token_s));
	token_s->value = "cat";
	token_s->type = TK_WORD;
	ft_lstadd_back(&lst, ft_lstnew(token_s));
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
