/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:16:07 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/08 19:24:24 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void unset_cmd(char **args)
{
	g_pub.exit_status = 0;
	if (*args == NULL)
		exit(0);
		while (*args)
		{
			if (check_var(*args) != TRUE)
				g_pub.exit_status = 1;
			else
			{
				unset_var(*args);
				unset_from_exp(*args);
			}
			printf("args: %s",*args);
			args++;
		}
	//	exit(g_pub.exit_status);
}
