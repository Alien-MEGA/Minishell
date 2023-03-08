/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:16:55 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/08 17:33:31 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/* Give full command line ,Ex : "exit "44" " */
void	exit_b(char *command_line)
{
	char	**str;
	char	*parameter;

	str = ft_split(command_line, ' ');
	if (str[2] != NULL)
		return (ft_free(str), ft_printf(2,
				"Minishell : exit: too many arguments\n"), exit(1));
	parameter = ft_strdup(str[1]);
	ft_free(str);
	if (parameter == NULL)
		exit(0);
	exit(ft_atoi(parameter));
}
