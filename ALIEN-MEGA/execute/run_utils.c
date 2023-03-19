/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:40:07 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/18 00:33:17 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int wait_pross(pid_t pross)	
{
	int status;

	waitpid(pross, &status, 0);
	while (wait(NULL) != -1)
		;
	return (status);
}

int	find_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i] && access(paths[i], F_OK | X_OK) == FAIL)
		i++;
	if (access(paths[i], X_OK) > FAIL)
		return (i);
	return (FAIL);
}

void	ft_apply_now(char *path, char **cmd, char **env)
{
	ft_error(access(path, F_OK), 1);
	ft_error(access(path, X_OK), 1);
	ft_error(execve(path, cmd, env), 1);
}

char	**ft_path(char *cmd, char **env)
{
	char	**paths;
	int		i;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == NULL)
		i++;
	if (!env[i])
		return (ft_printf(2, "pipex() : %s : No such file or directory\n"
				, cmd), exit(127), NULL);
	paths = ft_split((env[i] + 5), ':');
	i = -1;
	while (paths[++i] != NULL)
	{
		paths[i] = ft_strjoin_gnl(paths[i], "/");
		paths[i] = ft_strjoin_gnl(paths[i], cmd);
	}
	return (paths);
}

void	execute_x(char *argv, char **env)
{
	char	**paths;
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	free(argv);
	if (!env)
		return (ft_printf(2, "pipex() : %s : No such file or directory\n"
				, cmd[0]), exit(127));
	if (ft_strchr_check(cmd[0], '/'))
		ft_apply_now(cmd[0], cmd, env);
	paths = ft_path(cmd[0], env);
	if (find_path(paths) == FAIL)
		return (ft_printf(2, "pipex() : %s : command not found\n"
				, cmd[0]), exit(127));
	path = paths[find_path(paths)];
	ft_free(paths);
	ft_error(execve(path, cmd, env), 0);
}