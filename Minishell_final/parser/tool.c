/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:53:06 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/13 01:34:54 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void printList(t_list *lst, t_list *rd) 
{
    if (lst == NULL && rd == NULL) {
        printf("Empty lists\n");
        return;
    }

    if (lst != NULL) {
        printf("List 1: ");
        while (lst != NULL) {
            printf("%s ", lst->value);
            lst = lst->next;
        }
        // printf("\n");
    }

    if (rd != NULL) {
        printf("  List 2: ");
        while (rd != NULL) {
            printf("%s ", rd->value);
            rd = rd->next;
        }
    }
	printf("\n");
}

void printTree(t_tree *tree) 
{
    if (tree == NULL) 
	{
        return ((void)printf("Empty\n"));
    }

    printf("Node: ");
    printList(tree->lst, tree->redirect_mode);

    printf("Left child: ");
    printTree(tree->left);

    printf("Right child: ");
    printTree(tree->right);
}