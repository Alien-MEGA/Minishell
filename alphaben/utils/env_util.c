/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:20:26 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/03 19:16:37 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	add_to_env(char *content)
{
	int		env_len;
	char	**tmp;
	int		i;

	tmp = g_pub.env;
	env_len = (int)ft_matlen(g_pub.env);
	g_pub.env = malloc(sizeof(char *) * (env_len + 2));
	ft_error_str(g_pub.env, 1);
	while (i < env_len)
	{
		g_pub.env[i] = tmp[i];
		i++;
	}
	g_pub.env[i] = content;
	g_pub.env[i + 1] = NULL;
	free(tmp);
}
