/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:57:50 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/12 21:57:33 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

int	print_error(char *value)
{
	ft_printf(2,
		"Minishell : syntax error near unexpected token `%s'\n",
		value);
	g_pub.exit_status = 258;
	return (FALSE);
}

int	check_syntax(t_list *tokens)
{
	if (check_quote(tokens) == FALSE)
	{
		ft_printf(2, "%sminishell:lexer:%sopen quote%s\n", RED, GREEN, RESET);
			g_pub.exit_status = 258;
		return (FALSE);
	}
	if (check_brace(tokens) == FALSE || check_quote(tokens) == FALSE)
	{
		ft_printf(2, "%sminishell:lexer:%sbrace error\n%s\n", RED, GREEN, RESET);
		g_pub.exit_status = 258;
		return (FALSE);
	}
	if (check_tokens(tokens) == FALSE)
		return (FALSE);
	return (check_br_op(tokens));
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
		if (num_close_brace > num_open_brace)
			return (FALSE);
		tokens = tokens->next;
	}
	if (num_close_brace == num_open_brace)
		return (TRUE);
	return (FALSE);
}

int	check_tokens(t_list *tk)
{
	t_list	*nxt;
	t_list	*prev;

	nxt = NULL;
	prev = NULL;
	while (tk)
	{
		nxt = tk->next;
		if (istype(tk->type, T_O) == TRUE && !check_op_syntax(prev, nxt))
			return (print_error(tk->value));
		else if (istype(tk->type, T_R) && !check_rd_syntax(nxt))
			return (print_error(tk->value));
		if ((tk->type == TK_OPEN_BRACE && nxt != NULL )
			&& nxt->type == TK_CLOSE_BRACE)
			return (print_error(tk->value));
		prev = tk;
		tk = nxt;
	}
	return (TRUE);
}
