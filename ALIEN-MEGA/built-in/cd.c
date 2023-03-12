/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:38:13 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/12 23:12:09 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	cd_to_home(void)
{
	char	*home;

	g_pub.exit_status = 1;
	home = expand_env("HOME");
	if (home == NULL)
		ft_printf(2, "cd:HOME not set");
	else
		cd_cmd(home);
	free(home);
}

void	cd_cmd(char *path)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = get_pwd();
	g_pub.exit_status = 1;
	if (path == NULL)
		cd_to_home();
	else if (chdir(path) == FAIL)
		perror("minishell:cd:");
	else
	{
		pwd = get_pwd();
		export_to_env("OLDPWD", oldpwd, OPT_CREAT);
		export_to_env("PWD", pwd, OPT_CREAT);
		g_pub.exit_status = 0;
		free(pwd);
		free(oldpwd);
	}
}
