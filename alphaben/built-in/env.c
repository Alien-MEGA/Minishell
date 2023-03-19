/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:58:51 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/14 13:20:37 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_b()
{
	int i;

	i = 0;
	export_to_env("_", "env", OPT_APPEND);

	while (g_pub.env[i])
	{
		printf("%s\n", g_pub.env[i]);
		i++;
	}
	g_pub.exit_status = 0;

}
