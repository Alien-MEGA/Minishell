/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/02 15:37:49 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*wildcard_exp(char *word)
{
	
}

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
	