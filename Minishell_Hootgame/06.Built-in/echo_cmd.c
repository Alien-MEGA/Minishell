/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:16:53 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/27 02:33:20 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"

char	*cmd_join(char **cmd)
{
	int i;
	char *cmd_line;

	i = 0;
	cmd_line = NULL;
	while (cmd[++i])
	{
		cmd_line = ft_strjoin_gnl(cmd_line, cmd[i]);
		cmd_line = ft_strjoin_gnl(cmd_line, " ");
	}
	return (cmd_line);
}

void	echo_cmd(char **cmd)
{
	char	*string;
	int		flag;

	flag = FALSE;
	if (ft_strncmp(cmd[1], "-n", 2) == 0)
	{
		string = cmd_join(&cmd[2]);
		flag = TRUE;
	}
	else
		string = cmd_join(&cmd[1]);
	if (flag == TRUE)
		printf("%s", string);
	else if (flag == FALSE)
		printf("%s\n", string);
}
