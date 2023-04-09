/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:46:50 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 20:04:19 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

t_loc	ini_loc(int i, int j)
{
	t_loc	loc;

	loc.i = i;
	loc.j = j;
	return (loc);
}

t_list	*nd_copy(t_list *lst)
{
	t_list	*nlst;

	if (lst == NULL)
		return (NULL);
	nlst = ft_lstnew(lst->type, ft_strdup(lst->value), NULL);
	ft_error_str(nlst, 1);
	return (nlst);
}

int	nxt_type(t_list	*lst)
{
	if (lst == NULL)
		return (-1);
	else if (lst->next == NULL)
		return (-1);
	else
		return (lst->next->type);
}
