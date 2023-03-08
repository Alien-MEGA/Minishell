/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:16:53 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/08 17:35:57 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	echo_check_option(char *command_line)
{
	if (ft_strnstr(command_line, "-n", 2) != NULL)
		return (TRUE);
	return (FALSE);
}

static char	*echo_mk_str(char **command, int option)
{
	if (option == TRUE)
		return (command[2]);
	else if (option == FALSE)
		return (ft_strjoin(command[1], "\n"));
}
/* Give full command line ,Ex : "echo -n hello" */
void	echo_b(char *command_line)
{
	char	*str;

	str = echo_mk_str(ft_split(command_line, ' '),
			echo_check_option(command_line));
	printf("%s", str);
}
