/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:16:07 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/13 17:35:11 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

void	unset_cmd(char **cmd)
{
	g_pub.exit_status = 0;
	if (*cmd == NULL)
		return ;
	while (*cmd)
	{
		if (check_var(*cmd) != TRUE)
		{
			ft_printf(2, "minishell: unset: '%s': not a valid identifier\n",
				*cmd);
			g_pub.exit_status = 1;
			return ;
		}
		else
		{
			unset_var(*cmd);
			unset_from_exp(*cmd);
		}
		cmd++;
	}
}
