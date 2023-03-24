/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:11 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/23 17:32:44 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	istype(int t, int type)
{
	if (type == T_O && (t == TK_AND || t == TK_OR || t == TK_PIPE))
		return (TRUE);
	if (type == T_R && (t == TK_HERE_DOC || t == TK_RD_INPUT
			|| t == TK_RD_OUTPUT_APPEND || t == TK_RD_OUTPUT))
		return (TRUE);
	if (type == T_W && (t == TK_WORD || t == TK_DOUBLE_QUOTE
			|| t == TK_SINGLE_QUOTE))
		return (TRUE);
	return (FALSE);
}

int	check_op_syntax(t_list *prev, t_list *nxt)
{
	if (nxt != NULL && nxt->type == TK_WT_SPACE)
		nxt = nxt->next;
	if (nxt == NULL || prev == NULL)
		return (FALSE);
	if (istype(prev->type, T_O) == TRUE || prev->type == TK_OPEN_BRACE)
		return (FALSE);
	if (istype(nxt->type, T_O) == TRUE || nxt->type == TK_CLOSE_BRACE)
		return (FALSE);
	return (TRUE);
}

int	check_rd_syntax(t_list *nxt)
{
	if (nxt != NULL && nxt->type == TK_WT_SPACE)
		nxt = nxt->next;
	if (nxt == NULL)
		return (FALSE);
	if (istype(nxt->type, T_W) != TRUE)
		return (FALSE);
	return (TRUE);
}
