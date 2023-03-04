/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:57:50 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/04 18:48:01 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_syntax(t_list *tokens)
{



}

int	check_quote(t_list *tokens)
{
	t_token	*tk;

	while (tokens)
	{
		tk = (t_token *)tokens->data;
		if (tk->type == TK_OPEN_QUOTE)
			return (FALSE);
		tokens = tokens->next;
	}
	return (TRUE);
}

int check_brace(t_list *tokens)
{
	int		num_open_brace;
	int		num_close_brace;
	t_token		*tk;

	num_close_brace = 0;
	num_open_brace = 0;
	while (tokens)
	{
		tk = (t_token *)tokens->data;
		if (tk->type == TK_OPEN_BRACE)
			num_open_brace++;
		if (tk->type == TK_CLOSE_BRACE)
			num_close_brace++;
			tokens = tokens->next;
	}
	printf("check barce : open %d , close %d\n",num_open_brace, num_close_brace);
	if (num_close_brace == num_open_brace)
		return (TRUE);

	return (FALSE);
}
