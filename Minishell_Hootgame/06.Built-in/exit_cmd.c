/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:16:55 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/05 20:06:14 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01.Main/minishell.h"
/* Give full command line ,Ex : "exit "44" " */
void	exit_cmd(char **cmd)
{
	if (cmd == NULL || cmd[0] == NULL)
		return (ft_printf(2, "exit\n"),
			exit(g_pub.exit_status));
	if (cmd[1] != NULL)
	{
		g_pub.exit_status = 1;
		return (ft_printf(2,
				"exit\nMinishell : exit: too many arguments\n"));
	}
	// Note : if not number
	return (ft_printf(2, "exit\n"),
		exit(ft_atoi(cmd[0])));
}
