/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:16:59 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/03 16:08:30 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void load_env(char *_path, char **env)
{
	char *path;
	if (env[0] == NULL)
	{
		g_pub.env = (char **)malloc(4);
		ft_error_str(g_pub.env, 1);
		path = get_pwd();
		ft_error_str(path, 1);
		g_pub.env[0] = ft_strjoin("PWD=", get_pwd());
		g_pub.env[1] = ft_strdup(SHLVL);
		g_pub.env[2] = ft_strjoin("_=", _path);
		g_pub.env[3] = NULL;
		g_pub.path = ft_strdup(DEFAULT_PATH);
		g_pub.isdef_env = TRUE;

		free(path);
	}
	else
		g_pub.env = ft_matrixdup(env);

	ft_error_str(g_pub.env, 1);
}

void export_to_env(char *key, char *value, int option)
{
}

void unset_var(char *key)
{
}

char *expand_env(char *key)
{
	char *join;
	int i;
	int len;

	i = 0;
	join = ft_strjoin(key, "=");
	len = ft_strlen(join);
	ft_error_str(join, 1);
	while (g_pub.env[i])
	{
		if (ft_strncmp(g_pub.env[i], join, len) == 0)
			return (free(join), ft_strdup(g_pub.env[i] + len));
		i++;
	}
	return (strdup(""));
}
