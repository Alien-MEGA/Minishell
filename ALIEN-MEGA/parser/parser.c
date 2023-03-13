/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:22:05 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/13 01:39:33 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// lst;
// (< infile echo -n hoot) | cat | ls -l -a || cat > outfile > of;

t_tree	*bracket_handle(t_list **lst)
{
	t_tree	*tree;

	(*lst) = (*lst)->next;
	tree = or_and(lst);
	(*lst) = (*lst)->next;
	skip_space(lst);
	return (tree);
}

t_tree	*pipeline(t_list **lst)
{
	t_tree	*tree;

	tree = create_command(lst);
	while (*lst
			&& (*lst)->type == TK_PIPE)
	{
		ft_treeswap_root(&tree, create_operator(lst), LEFT);
		tree->right = create_command(lst);
	}
	return (tree);
}

t_tree	*or_and(t_list **lst)
{
	t_tree	*tree;

	tree = pipeline(lst);
	while ((*lst)
			&& ((*lst)->type == TK_OR
			|| (*lst)->type == TK_AND))
	{
		ft_treeswap_root(&tree, create_operator(lst), LEFT);
		tree->right = pipeline(lst);
	}
	return (tree);
}

t_tree	*mk_tree(t_list *lst)
{
	t_tree	*tree;

	tree = NULL;
	return (or_and(&lst));
}

/* ==============> Test <============== */

void	test()
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(TK_OPEN_BRACE, ft_strdup("("), NULL));
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
	ft_lstadd_back(&lst, ft_lstnew(TK_CLOSE_BRACE, ft_strdup(")"), NULL));



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

/*
	==============> Idea about <============== 
	Check every time if there is a TK_OPEN_BRACE
*/