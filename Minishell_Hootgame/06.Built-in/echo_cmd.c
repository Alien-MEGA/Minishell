/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:16:53 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:13 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

void	echo_cmd(char **cmd)
{
	int	i;
	int	flag;

	i = 0;
	flag = TRUE;
	if (ft_strcmp(cmd[0], "-n") == 0)
	{
		flag = FALSE;
		i = 1;
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
