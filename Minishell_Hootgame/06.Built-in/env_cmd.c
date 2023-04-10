/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:50:35 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/10 02:43:07 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

void	env_cmd(void)
{
	int	i;

	i = 0;
	while (g_pub.env[i])
	{
		printf("%s\n", g_pub.env[i]);
		i++;
	}
	g_pub.exit_status = 0;
}
