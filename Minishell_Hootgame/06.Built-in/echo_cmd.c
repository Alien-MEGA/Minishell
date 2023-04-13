/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:16:53 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/13 01:58:54 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static int	isoption(char *word)
{
	int	len;
	int	i;

	if (word == NULL)
		return (FALSE);
	len = ft_strlen(word);
	if (len < 2 || word[0] != '-')
		return (FALSE);
	if (word[1] != 'n')
		return (FALSE);
	i = 2;
	while (word[i])
	{
		if (word[i] != 'n')
			return (FALSE);
			i++;
	}
	return (TRUE);
}

void	echo_cmd(char **cmd)
{
	int	i;
	int	flag;

	g_pub.exit_status = 0;
	i = 0;
	flag = TRUE;
	while (isoption(cmd[i]))
	{
		flag = FALSE;
		i ++;
	}
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		i++;
		if (cmd[i])
			printf(" ");
	}
	if (flag == TRUE)
		printf("\n");
}
