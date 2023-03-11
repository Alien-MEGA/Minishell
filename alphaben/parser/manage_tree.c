// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   manage_tree.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/06 20:27:22 by reben-ha          #+#    #+#             */
// /*   Updated: 2023/03/10 21:25:04 by ebennamr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../minishell.h"

// t_tree	*create_command(t_list *lst, int *i)
// {
// 	t_tree	*new_tree;
// 	t_list	*new_lst;
// 	t_list	*new_rd;

// 	new_lst = NULL;
// 	new_rd = NULL;
// 	while (in(lst, (*i)) && in(lst, (*i))->type >= TK_RD_INPUT
// 			&& in(lst, (*i))->type <= TK_RD_OUTPUT_APPEND)
// 		ft_lstadd_back(&new_rd, create_redirect(lst, i));
// 	while (in(lst, (*i))
// 		&& !(in(lst, (*i))->type >= TK_PIPE && in(lst, (*i))->type <= TK_OR))
// 	{
// 		ft_lstadd_back(&new_lst,
// 			ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
// 		(*i)++;
// 	}
// 	while (in(lst, (*i)) && in(lst, (*i))->type >= TK_RD_INPUT
// 			&& in(lst, (*i))->type <= TK_RD_OUTPUT_APPEND)
// 		ft_lstadd_back(&new_rd, create_redirect(lst, i));
// 	new_tree = ft_treenew(new_lst);
// 	new_tree->redirect_mode = new_rd;
// 	return (new_tree);
// }

// t_tree	*create_operator(t_list *lst, int *i)
// {
// 	t_tree	*operator;

// 	operator = ft_treenew(ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
// 	(*i)++;
// 	return (operator);
// }

// t_list	*create_redirect(t_list *lst, int *i)
// {
// 	t_list	*new_node;

// 	new_node = NULL;
// 	ft_lstadd_back(&new_node, ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
// 	(*i)++;
// 	ft_lstadd_back(&new_node, ft_lstnew(in(lst, (*i))->type, in(lst, (*i))->value, NULL));
// 	(*i)++;
// 	return (new_node);
// }
