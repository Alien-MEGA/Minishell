/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:04:18 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:13 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static t_list	*remove_empty(t_list *lst)
{
	int		prev;
	t_list	*nlst;
	t_list	*tmp;

	prev = TK_AND;
	nlst = NULL;
	tmp = lst;
	while (lst)
	{
		if (lst->value[0] == '\0')
		{
			if (!(istype(prev, T_W) || (lst->next
				&& !istype(lst->next->type, T_W))))
			{
				ft_lstadd_back(&nlst,
					ft_lstnew(lst->type, ft_strdup(lst->value), NULL));
				prev = lst->type;
			}
		}
		else
		{
			ft_lstadd_back(&nlst, ft_lstnew(lst->type, ft_strdup(lst->value), NULL));
			prev = lst->type;
		}
		lst = lst->next;
	}
	return (ft_lstclear(&tmp), nlst);
}

t_list	*ft_filter(t_list *lst)
{
	int		prev;
	int		bool;
	t_list	*nlst;
	t_list	*tmp;

	prev = -1;
	nlst = NULL;
	tmp = lst;
	while (lst)
	{
		bool = (!istype(prev, T_W)
				|| !lst->next || !istype(lst->next->type, T_W));
		if (lst->type == TK_WT_SPACE && bool)
			prev = -1;
		else
		{
			ft_lstadd_back(&nlst, ft_lstnew(lst->type,
					ft_strdup(lst->value), 0));
			prev = lst->type;
		}
		lst = lst->next;
	}
	return (ft_lstclear(&tmp), nlst);
}

void	expand_var_insert(t_list *lst)
{
	char	**words;
	t_list	*nlst;
	int i;

	i = 0;
	nlst = NULL;
	words = ft_split(lst->value, ' '); //Note : You miss this " "
	if (words == NULL)
	{
		free(lst->value);
		lst->value = ft_strdup("");
	}
	else if (lst->type == TK_WORD && ft_strlen(lst->value) > 0)
	{
		while (words[i])
		{
			printf("%s", words[i]);
			ft_lstadd_back(&nlst, ft_lstnew(TK_WORD, words[i], NULL));
			ft_lstadd_back(&nlst, ft_lstnew(TK_WT_SPACE, ft_strdup(" "), NULL));
			i++;
		}
		ft_insert(&lst, nlst);
		free(words);
	}
}
