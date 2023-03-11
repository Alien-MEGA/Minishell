/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/11 22:43:49 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// in(lst, (*index));
// < infile echo -n hoot | cat | ls -l -a || cat > outfile > of;

t_tree	*pipeline(t_list *lst, int *index)
{
	t_tree	*tree;

	tree = create_command(lst, index);
	while (in(lst, (*index))
			&& in(lst, (*index))->type == TK_PIPE)
	{
		ft_treeswap_root(&tree, create_operator(lst, index), LEFT);
		tree->right = create_command(lst, index);
	}
	return (tree);
}

t_tree	*or_and(t_list *lst, int *index)
{
	t_tree	*tree;

	tree = pipeline(lst, index);
	while (in(lst, (*index))
			&& (in(lst, (*index))->type == TK_OR
			|| in(lst, (*index))->type == TK_AND))
	{
		ft_treeswap_root(&tree, create_operator(lst, index), LEFT);
		tree->right = pipeline(lst, index);
	}
	return (tree);
}

t_tree	*mk_tree(t_list *lst)
{
	t_tree	*tree;
	int		index;

	tree = NULL;
	index = 0;
	return (or_and(lst, &index));
}

/* ==============> Test <============== */

void	test()
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(TK_RD_INPUT, ft_strdup("<"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("infile"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("echo"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("-n"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("hoot"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_PIPE, ft_strdup("|"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("cat"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_OR, ft_strdup("||"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("ls"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("-l"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("-a"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_PIPE, ft_strdup("|"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("cat"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_RD_OUTPUT, ft_strdup(">"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("outfile"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_RD_OUTPUT, ft_strdup(">"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_lstadd_back(&lst, ft_lstnew(TK_WORD, ft_strdup("of"), NULL));
	ft_lstadd_back(&lst, ft_lstnew(TK_WT_SPACE, ft_strdup("^^^^"), NULL));

	ft_indexing(lst);
	printList(lst, NULL);
	printf("\n\n");



	t_tree *tree = mk_tree(lst);

	// print_tree(tree);

	printTree(tree); 




	//		< -->   --> infile -->   --> echo -->   --> -n -->   --> hoot 
	//		-->		--> | -->   --> cat -->   --> || -->   --> ls -->   --> -l 
	//		-->   --> -a -->   --> | -->   --> cat -->   -->
	//		> -->   --> outfile -->   --> > -->   --> of -->   --> NULL
	




	ft_lstclear(&lst);
}

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
