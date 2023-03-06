/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:27:22 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/06 22:05:10 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree	*create_command(t_list *lst, int *i)
{
	char	*cmd;
	int		start;
	int		end;

	cmd = NULL;
	start = (*i);
	while (in(lst, (*i))->type == TK_WORD)
		(*i)++;
	end = (*i);	
	while (start < end)
	{
		cmd = ft_strjoin_gnl(cmd, in(lst, start)->value);
		cmd = ft_strjoin_gnl(cmd, " ");	
		start++;
	}
	return (ft_treenew(cmd, TK_WORD));
}

t_tree	*create_operator(t_list *lst, int *i)
{
	t_tree	*operator;

	operator = ft_treenew(in(lst, (*i))->value, in(lst, (*i))->type);
	(*i)++;
	return (operator);
}

t_tree	*create_redirect(t_list *lst, int *i)
{
	char	*redirect;
	int		type;

	type = in(lst, (*i))->type;
	redirect = ft_strjoin(in(lst, (*i))->value, " ");
	(*i)++;
	redirect = ft_strjoin_gnl(redirect, in(lst, (*i))->value);
	(*i)++;
	return (ft_treenew(redirect, type));
}
