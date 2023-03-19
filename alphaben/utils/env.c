/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:16:59 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/14 14:08:04 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int index_in_env(char *key)
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
		g_pub.env = (char **)malloc(3 * sizeof(char *));
		ft_error_str(g_pub.env, 1);
		path = get_pwd();
		ft_error_str(path, 1);
		g_pub.env[0] = ft_strjoin("PWD=", path);
		g_pub.env[1] = ft_strjoin("_=", _path);
		g_pub.env[2] = NULL;
		g_pub.path = ft_strdup(DEFAULT_PATH);
		g_pub.isdef_env = TRUE;
		free(path);
	}
	else
		g_pub.env = ft_matrixdup(env);
		set_shlvl();
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
	{
		tmp = g_pub.env[index] ;
		g_pub.env[index] = ft_strjoin_gnl(join, value);
	}
	else if (index >= 0 && OPT_APPEND == option)
			g_pub.env[index] = ft_strjoin_gnl(g_pub.env[index], value);
	else
			add_to_env(ft_strjoin_gnl(join, value));
	free(tmp);
}

void unset_var(char *key)
{
	int	index;
	int	len;

	if (g_pub.env[0] == NULL)
		return ;
	index = index_in_env(key);
	len = ft_matlen(g_pub.env);
	if (index < 0)
		return ;
	free(g_pub.env[index]);
	while (index < len - 1)
	{
		g_pub.env[index] = g_pub.env[index + 1];
		index++;
	}
	g_pub.env[len - 1] = 0;
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
	unset_from_exp(key);
	while (g_pub.env[i])
	{
		if (ft_strncmp(g_pub.env[i], join, len) == FALSE)
			return (free(join), ft_strdup(g_pub.env[i] + len));
		i++;
	}
	return (free(join), NULL);
}
