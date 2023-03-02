/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:29:14 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/01 23:27:53 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	skip_wt_sapce(t_list **list, char *line, int *i)
{
	while (line [*i] && (line[*i] == ' ' || line[*i] == '\t'))
		*i += 1;
	add_token(list, TK_WT_SPACE, " ");
	*i -= 1;
}

void	skip_quote(t_list **list, char *line, int *i,char quote)
{
	int ind_of_quote;
	char pt_quote[2];

	ind_of_quote = indexofchar(&line[*i + 1], quote);
	//printf("index of first qute %d",*i);
	//printf("index of end qute %d", inde);

	pt_quote[0] = quote;
	if (ind_of_quote < 0)
	add_token(list, TK_OPEN_QUOTE, pt_quote);
	else if (quote == '\'')
		add_token(list, TK_SINGLE_QUOTE, ft_substr(line,*i + 1, ind_of_quote));
	else if (quote == '"')
		add_token(list, TK_DOUBLE_QUOTE, ft_substr(line, *i + 1,ind_of_quote ));
	if (ind_of_quote < 0)
	*i = ft_strlen(line) - 1;
	else
	*i += ind_of_quote + 1;
}

void skip_word(t_list **list, char *line, int *i)
{
	int count;
	count = 0;

while (line[*i] && indexofchar(SP_CHAR,line[*i]) == -1)
{
	count ++;
	*i += 1;
}
	add_token(list, TK_WORD, ft_substr(line, *i - count, count));
}
