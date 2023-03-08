/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:16:53 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/08 18:18:30 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	echo_check_option(char *command_line)
{
	if (ft_strnstr(command_line, "-n", ft_strlen(command_line)) != NULL)
		return (TRUE);
	return (FALSE);
}

static char	*echo_mk_str(char *command, int option)
{
	if (option == TRUE)
		return (ft_strnstr(command, "echo -n", ft_strlen(command)) + 8);
	else
		return (ft_strnstr(command, "echo", ft_strlen(command)) + 5);
}
/* Give full command line ,Ex : "echo -n hello" */
void	echo_b(char *command_line)
{
	char	*str;

	str = echo_mk_str(command_line,
			echo_check_option(command_line));
	if (TRUE == echo_check_option(command_line))
		printf("%s", str);
	else if (FALSE == echo_check_option(command_line))
		printf("%s\n", str);
}
