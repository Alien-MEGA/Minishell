/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/02 18:56:47 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*wildcard_exp(char *word)
{
	t_list	*pwd_ls;
	char *path;
	int		i;
	int		j;


	pwd_ls = get_ls();
	if (pwd_ls == 0)
		return (ft_strdup(""));
	while (pwd_ls)
	{
		i = 0;
		j = 0;
		path = (char *)pwd_ls->data;
		
	}


return 0;}

char	*get_pwd(void)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	ft_error_str(cwd, 1);
	return (strdup(cwd));
}

char	*get_prompt(char *pwd)
{
	if (ft_strrchr(pwd, '/') != NULL)
		return (ft_strjoin_gnl((ft_strjoin
					(PROMPT_ONE, ft_strrchr(pwd, '/') + 1))
				, PROMPT_TWO));
	return (PROMPT);
}

t_list	*get_ls()
{
	t_list	*list;
	DIR		*op_dir;
	char	*path;
	struct dirent	*ent;

	list = 0;
	path = get_pwd();
	op_dir = opendir(path);
	ft_error_str(op_dir, 2);
	while ((ent = readdir(op_dir)) != NULL)
	{
		if(ent->d_name[0] != '.')
			ft_lstadd_back(&list, ft_lstnew(ent->d_name));
	}
	free(path);
	return (list);
}
