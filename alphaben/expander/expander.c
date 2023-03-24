/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:06:35 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/24 16:50:37 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	iscontain_var(char *word)
{
	int	i;
	int	bool;

	i = 0;
	if (indexofchar(word, '$') == -1)
		return (FALSE);

	while (word[i])
	{
		bool = word[i + 1] == '_' || (ft_isalpha(word[i + 1] ) || word[i + 1] == '?');
		if (word[i] == '$' && bool)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static char	*get_next_key(char *word, int *i)
{
	int	start;

	start = *i;
	if(word[*i] == '\0')
		return (NULL);
	if (word[*i] == '?')
		return ((*i)++, ft_strdup("?"));
	if (word[*i] != '_' && !ft_isalpha(word[*i]))
		return (NULL);
	(*i)++;
	while (word[*i])
	{
		if (word[*i] != '_' && !ft_isalnum(word[*i]))

			return (ft_substr(word, start, *i - start));
		(*i)++;
	}
	return(ft_strdup(&word[start]));
}

static char	*expand_word(char *word, int start, int i)
{
	char	*key;
	char	*new_word;
	char	*tmp;
	int	num;

	num = 0;
	new_word = ft_strdup("");
	while (word[i])
	{
		if (word[i]== '$')
		{
			num = i++;
			key = get_next_key(word, &i);
			if (key)
			{
				tmp = ft_substr(word, start, num - start);
				new_word =  ft_strjoin_gnl(new_word, tmp);
				free(tmp);
				tmp = expand_env(key);
				if(tmp == NULL)
					tmp = ft_strdup("");
				new_word = ft_strjoin_gnl(new_word, tmp);
				free(tmp);
				start = i;
			}
			free(key);
		}
		else
			i++;

	}
	tmp = ft_substr(word, start, i - start);
	new_word = ft_strjoin_gnl(new_word, tmp);
	return(free(tmp), new_word);
}

void	exapnd_var_list(t_list *lst)
{
	char	*tmp;

	while (lst)
	{
		if (lst->type != TK_SINGLE_QUOTE && iscontain_var(lst->value))
		{
			tmp = lst->value;
			lst->value = expand_word(tmp, 0, 0);
			free(tmp);
		}

		lst = lst->next;
		// if (lst->type == TK_HERE_DOC)
		// lst->next->type = TK_SINGLE_QUOTE;
	}
}

void	expander(t_list lst)
{
	//exapnd_var_list(lst)
}
