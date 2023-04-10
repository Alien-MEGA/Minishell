/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:04:18 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/10 02:21:42 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

int	iscontain_var(char *word)
{
	int	i;
	int	bool1;
	int	bool2;
	int	bool3;

	i = 0;
	if (!word || indexofchar(word, '$') == -1)
		return (FALSE);
	while (word[i])
	{
		bool1 = word[i + 1] == '_';
		bool2 = word[i + 1] == '?';
		bool3 = ft_isalpha(word[i + 1]);
		if (word[i] == '$' && (bool1 || bool2 || bool3))
			return (TRUE);
		i++;
	}
	return (FALSE);
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
		bool = (!istype(prev, T_W) || !istype(nxt_type(lst), T_W));
		if (lst->type == TK_WT_SPACE && bool)
			prev = -1;
		else
		{
			ft_lstadd_back(&nlst, nd_copy(lst));
			prev = lst->type;
		}
		lst = lst->next;
	}
	return (ft_lstclear(&tmp), nlst);
}

t_list	*get_list_form_var(t_list *lst)
{
	char	**words;
	t_list	*nlst;
	int		i;

	i = 0;
	nlst = NULL;
	words = ft_split(lst->value, ' ');
	if (words[0] == NULL)
		return (free(words), NULL);
	else if (lst->type == TK_WORD && ft_strlen(lst->value) > 0)
	{
		while (words[i])
		{
			ft_lstadd_back(&nlst, ft_lstnew(TK_WORD, words[i], NULL));
			if (words[i + 1] != NULL)
				ft_lstadd_back(&nlst, ft_lstnew(12, ft_strdup(" "), 0));
			i++;
		}
		free(words);
		return (nlst);
	}
	return (NULL);
}

void	insert_list(t_list **head, t_list *lst)
{
	t_list	*nlst;
	t_list	*tmp;

	nlst = NULL;
	if (lst->type == TK_WORD && lst->value[0] != '\0')
	{
		nlst = get_list_form_var(lst);
		if (nlst != NULL)
		{
			if (*head == NULL)
				*head = nlst;
			else
			{
				tmp = ft_lstlast(*head);
				tmp->next = nlst;
			}
		}
	}
}
