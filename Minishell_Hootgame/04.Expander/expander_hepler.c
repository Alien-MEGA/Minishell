/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_hepler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:52:39 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/10 02:54:54 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

void	expand_cmd_helper(t_list **new_list, t_list *lst)
{
	char	*tmp;

	tmp = lst->value;
	lst->value = expand_word(lst->value, 0, 0);
	if (lst->type == TK_WORD)
	{
		free(tmp);
		tmp = lst->value;
		lst->value = ft_strtrim(lst->value, " ");
		insert_list(new_list, lst);
	}
	else
		ft_lstadd_back(new_list, nd_copy(lst));
	free(tmp);
}

int	expand_redi_helper(t_list **new_list, t_list *lst)
{
	char	*tmp;

	tmp = lst->value;
	lst->value = expand_word(lst->value, 0, 0);
	if (lst->type == TK_WORD)
	{
		free(tmp);
		tmp = lst->value;
		lst->value = ft_strtrim(lst->value, " ");
		if (lst->value[0] == '\0' || indexofchar(lst->value, ' ') != -1)
			return (free(tmp), ft_lstclear(new_list), FALSE);
		ft_lstadd_back(new_list, nd_copy(lst));
	}
	else
		ft_lstadd_back(new_list, nd_copy(lst));
	free(tmp);
	return (TRUE);
}

void	redir_err(void)
{
	g_pub.exit_status = 1;
	ft_printf(STDERR_FILENO, "minishell : ambiguous redirect \n");
}
