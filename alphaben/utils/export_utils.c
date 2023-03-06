/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:33:01 by ebennamr          #+#    #+#             */
/*   Updated: 2023/03/06 20:40:37 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

int	check_var(char *var)
{
	int	i;
	int	len;

	if (var[0] != '_' && !ft_isalpha(var[0]))
		return (FALSE);
		i = 1;
		len = ft_strlen(var);

	while (i < len)
	{
		if (var[i] != '_' && !ft_isalnum(var[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

