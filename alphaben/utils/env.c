/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:16:59 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/03 20:13:26 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int index_in_env(char *key)
{
	char *join;
	int i;
	int len;

	i = 0;
	join = ft_strjoin(key, "=");
	len = ft_strlen(join);
	while (g_pub.env[i])
	{
		if (ft_strncmp(g_pub.env[i], join, len) == FALSE)
			return (free(join), i);
			i++;
	}
	return (free(join), -1);
}

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
	int		index;
	char	*join;
	char	*tmp;

	tmp = NULL;
	join = ft_strjoin(key, "=");
	index = index_in_env(key);
	if (index >= 0 && OPT_CREAT == option)
		g_pub.env[index] = ft_strjoin_gnl(join, value);
	else if (index >= 0 && OPT_APPEND == option)
			g_pub.env[index] = ft_strjoin_gnl(g_pub.env[index], value);
	else
		add_to_env(ft_strjoin_gnl(join, value));
	free(tmp);
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
		if (ft_strncmp(g_pub.env[i], join, len) == FALSE)
			return (free(join), ft_strdup(g_pub.env[i] + len));
		i++;
	}
	return (strdup(""));
}
