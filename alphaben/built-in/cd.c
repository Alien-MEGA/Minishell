/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:38:13 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/09 17:10:39 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void cd_to_home()
{
	 char * home;
	home = expand_env("HOME");
	if (home == NULL)
	{
		ft_printf(2, "cd:HOME not set", path);
		g_pub.exit_status = 1;
	}
	else
	cd_cmd(HOME);
}
void	cd_cmd(char *path)
{
	if (path == NULL)
		cd_to_home();
	if (access(path, F_OK) != 0)
	{
		ft_printf(2, "minishell:cd: %s: No such file or directory", path);
		g_pub.exit_status = 1;
	}
	else if (is_dir(path) == FALSE)
	{
		ft_printf(2, "cd: cd:not a directory:%s", path);
		g_pub.exit_status = 1;
	}

}

int	is_dir(char *path)
{
struct	stat data;

if (stat(path,&data) != 0)
	ft_error(FAIL, 1);
return (S_ISDIR(data.st_mode));
}
