/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:16:55 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/22 15:31:48 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/* Give full command line ,Ex : "exit "44" " */
void	exit_cmd(char *command_line)
{
	char	**str;
	char	*parameter;

	str = ft_split(command_line, ' ');
	if (str[1] == NULL)
		return (ft_printf(2, "exit\n"),
				exit(0));
	if (str[2] != NULL)
		return (ft_free(str), ft_printf(2,
				"exit\nMinishell : exit: too many arguments\n"), exit(1));
	parameter = ft_strdup(str[1]);
	return (ft_free(str), ft_printf(2, "exit\n"),
			exit(ft_atoi(parameter)));
}
