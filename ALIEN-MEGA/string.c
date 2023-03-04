/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:53:30 by ebennamr          #+#    #+#             */
/*   Updated: 2023/02/27 18:49:23 by ebennamr         ###   ########.fr       */
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
