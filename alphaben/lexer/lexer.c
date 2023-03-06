/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:57:50 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/06 14:43:56 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_syntax(t_list *tokens)
{
	int bool;

	bool = FALSE;
	if (check_brace(tokens) == FALSE && check_brace(tokens) == FALSE)
		return (bool);
}

int	check_quote(t_list *tokens)
{
	while (tokens)
	{
		if (tokens->type == TK_OPEN_QUOTE)
			return (FALSE);
		tokens = tokens->next;
	}
	return (TRUE);
}

int	check_brace(t_list *tokens)
{
	int		num_open_brace;
	int		num_close_brace;

	num_close_brace = 0;
	num_open_brace = 0;
	while (tokens)
	{
		if (tokens->type == TK_OPEN_BRACE)
			num_open_brace++;
		if (tokens->type == TK_CLOSE_BRACE)
			num_close_brace++;
			tokens = tokens->next;
			if (num_close_brace > num_open_brace)
				return (FALSE);
	}
	if (num_close_brace == num_open_brace)
		return (TRUE);

	return (FALSE);
}

// int check_tokens(t_list *tokens)
// {
// 	t_token	*next;
// 	t_token	*previous;

// 	next = NULL;
// 	previous = NULL;
// 	while (tokens)
// 	{
// 		next = tokens->next;
// 		if ()
// 	}

// }
