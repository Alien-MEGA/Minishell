/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:53:30 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/02 16:46:27 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	indexofchar(char *line, char c)
{
	int i;

	i = 0;
	if (line == 0)
		return (-1);
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}

	return (-1);
}
