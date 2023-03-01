/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:36:54 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/01 18:42:12 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_current_dir_path()
{
	char cwd[PATH_MAX];
	char new_cwd;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		new_cwd = (char *)malloc(ft_strlen(cwd));
		if (new_cwd == NULL)
			perror("getcwd() error");//repalce
	}
	else
		perror("getcwd() error");// replace
}
char *get_current_dir_name()
{
	
}
