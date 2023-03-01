/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:47:06 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/01 18:12:44 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



t_data data;
char *prompt()
{
	char	*line;

		line = readline(PROMPT);
		if (line != 0)
		add_history(line);
		printf("line : %s \n",line);
// token

t_list *ls = 0;
 create_token_list(&ls,line);
int len = ft_lstsize(ls);
 t_token *t;
// t = (t_token *)ls->content;
// printf("type %d , Value : %s \n", t->type, t->value);

 while (ls != 0)
 {
		t = (t_token *)ls->content;
		printf("type %d , Value : %s \n",t->type, t->value);
		ls = ls->next;
}
		return (line);
}

int main()
{

		while (1)
		{

			prompt();
		}




}
