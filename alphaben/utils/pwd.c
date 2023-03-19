/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/18 19:10:25 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_pwd(void)
{
	char cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	ft_error_str(cwd, 1);
	return (strdup(cwd));
}

char *get_prompt(char *pwd)
{
	char *prompt;

	if (ft_strrchr(pwd, '/') != NULL)
	{
		prompt = ft_strjoin_gnl((ft_strjoin(PROMPT_ONE,
					ft_strrchr(pwd, '/') + 1)),PROMPT_TWO);
		return (free(pwd), prompt);
	}
	return (free(pwd), PROMPT);
}

t_list *get_ls()
{
	t_list *list;
	DIR *op_dir;
	char *path;
	struct dirent *ent;

	list = NULL;
	path = get_pwd();
	op_dir = opendir(path);
	ft_error_str(op_dir, 2);
	while ((ent = readdir(op_dir)) != NULL)
	{
		if (ent->d_name[0] != '.')
			ft_lstadd_back(&list, ft_lstnew(0, ft_strdup(ent->d_name), NULL));
	}
	closedir(op_dir);
	return (free(path), free(ent),list);
}

