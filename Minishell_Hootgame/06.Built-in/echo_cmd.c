/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:16:53 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/13 03:24:39 by reben-ha         ###   ########.fr       */
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

	i = 0;
	flag = TRUE;
	while (isoption(cmd[i]))
	{
		flag = FALSE;
		i++;
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
