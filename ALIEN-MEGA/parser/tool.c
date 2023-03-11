/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:53:06 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/11 21:49:29 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void print_tree(t_tree *root) 
{
    printf("		   %s\n", root->lst->value);
    printf("  	%s		  	%s\n", root->left->lst->value, root->right->lst->value);
    printf("%s	    %s		%s	  %s\n", root->left->left->lst->value, root->left->right->lst->value, root->right->left->lst->value, root->right->right->lst->value);
}


void printList(t_list *lst) 
{
    if (lst == NULL) {
        printf("Empty list\n");
        return;
    }

    printf("List: ");
    while (lst != NULL) {
        printf("%s ", lst->value);
        lst = lst->next;
    }
    printf("\n");
}

void printTree(t_tree *tree) 
{
    if (tree == NULL) 
	{
        return;
    }

    printf("Node: ");
    printList(tree->lst);

    printf("Left child: ");
    printTree(tree->left);

    printf("Right child: ");
    printTree(tree->right);
}