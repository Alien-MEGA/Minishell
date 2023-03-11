/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:11 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/10 19:57:52 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	istype(int t, int type)
{
	if (type == TP_OPER && (t == TK_AND || t == TK_OR || t == TK_PIPE))
		return (TRUE);
	if (type == TP_REDIR &&  (t == TK_HERE_DOC || t == TK_RD_INPUT ||
	 t == TK_RD_OUTPUT_APPEND || t == TK_RD_OUTPUT))
		return (TRUE);
	if (type == TP_WORD &&  (t == TK_WORD || t == TK_DOUBLE_QUOTE || t == TK_SINGLE_QUOTE))
		return (TRUE);
	return (FALSE);
}

int check_op_syntax(t_list *prev, t_list *nxt)
{
	if (nxt != NULL && nxt->type == TK_WT_SPACE)
		nxt = nxt->next;
	if (nxt == NULL || prev == NULL)
		return (FALSE);
	if (istype(prev->type, TP_WORD) == FALSE && prev->type != TK_CLOSE_BRACE | prev->type != TK_WT_SPACE)
		return (FALSE);
	if (istype(nxt->type, TP_WORD) == FALSE && nxt->type != TK_OPEN_BRACE)
		return (FALSE);
	return (TRUE);
}

int check_rd_syntax(t_list *nxt)
{
	if (nxt != NULL && nxt->type == TK_WT_SPACE)
		nxt =nxt->next;
	if (nxt == NULL)
		return (FALSE);
	if (istype(nxt->type, TP_WORD)!= TRUE)
		return (FALSE);
	return (TRUE);
}
