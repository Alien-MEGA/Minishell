/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:40:07 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/10 22:19:16 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

void	reset_std_fd(void)
{
	ft_error(dup2(g_pub.std_fd.fd_rd, 0), 1);
	ft_error(dup2(g_pub.std_fd.fd_wr, 1), 1);
}

static int	find_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i] && access(paths[i], F_OK | X_OK) == FAIL)
		i++;
	if (access(paths[i], X_OK) != FAIL)
		return (i);
	return (FAIL);
}

static void	ft_apply_now(char *path, char **cmd, char **env)
{
	ft_error(access(path, F_OK), 1);
	ft_error(access(path, X_OK), 1);
	ft_error(execve(path, cmd, env), 1);
}

static char	**ft_path(char *cmd)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	path = expand_env("PATH");
	if (!path)
		return (ft_printf(2, "Minishell : %s : No such file or directory\n"
				, cmd), exit(127), NULL);
	paths = ft_split(path, ':');
	i = -1;
	while (paths[++i] != NULL)
	{
		paths[i] = ft_strjoin_gnl(paths[i], "/");
		paths[i] = ft_strjoin_gnl(paths[i], cmd);
	}
	return (paths);
}

void	execute_x(char **cmd, char **env)
{
	char	**paths;
	char	*path;

	if (run_builtin(cmd, -1, -1) == SUCCESS)
		return (ft_free(cmd), exit(g_pub.exit_status));
	if (ft_strchr_check(cmd[0], '/'))
		ft_apply_now(cmd[0], cmd, env);
	paths = ft_path(cmd[0]);
	if (find_path(paths) == FAIL)
		return (ft_printf(2, "Minishell : %s : command not found\n"
				, cmd[0]), ft_free(paths), ft_free(cmd), exit(127));
	path = ft_strdup(paths[find_path(paths)]);
	ft_free(paths);
	ft_error(execve(path, cmd, env), 0);
}
